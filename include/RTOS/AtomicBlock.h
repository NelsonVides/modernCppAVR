
/*
    ***********************************************************************************************************************************
    ***********************************************************************************************************************************
    AtomicBlock.h
    ***********************************************************************************************************************************
    ***********************************************************************************************************************************

        This is a group of classes or essentially a template meta-program designed to
        replace the functionality of the AVR libc ATOMIC_BLOCK macros. The main
        motivation for the project is to provide a standard conforming approach.

        This design is fully portable as it uses no compiler specific elements, and
        conforms to C++ standards. It produces no-less efficient code and works on a
        number of architectures.

        Unsupported architectures can easily be added with
        a short update ( If you need help, ask in the AtomicBlock thread listed below ).

        As of version 1.1 the system now has a number of usage methods described below.
        These methods can be used together.

        Designed and implemented by Chirstopher Andrews.

        Distributed under GNU GPL V3 for free software.
        http://www.gnu.org/licenses/gpl.txt
        This licence will most probably change, if you have queries ask in the forum addressed below.

    -----------------------------------------------------------------------------------------------------------------------------------

        For more information you can ask questions here:
        http://arduino.cc/forum/index.php/topic,125253.msg941527.html#msg941527

    ***********************************************************************************************************************************
    ***********************************************************************************************************************************

        Declarable objects.

            - AtomicBlock, AtomicBlockSafe
                This will turn off interrupts when created.
                On destruction its operation depends on the passed template parameter.

            - NonAtomicBlock, NonAtomicBlockSafe
                This will turn on interrupts when created.
                On destruction its operation depends on the passed template parameter.

        Passable parameters.

            - Atomic_RestoreState
                When the owning object is destroyed, this mode specifies the state of the global interrupt flag
                will be returned to its original value as the owning object goes out of scope.

            - Atomic_Force
                When the owning object is destroyed, this mode specifies the state of the global interrupt flag
                will be forced to the opposite value set by the owning object when created.

        Optional parameters.

            - Safe operation for Atomic_RestoreState can be gained by using a second template parameter
            '_Safe' or by using declarable objects suffixed with 'Safe' ( Outlined below ).

                AVR Specific.
                    Safe mode causes Atomic_RestoreState to only touch the global interrupt bit in SREG.

        Usage type 1.

            - ATOMIC_BLOCK / NONATOMIC_BLOCK equivalent.

                AtomicBlock<Atomic_RestoreState> 		a_Block;
                NonAtomicBlock<Atomic_RestoreState> 	a_NoBlock;
                AtomicBlock<Atomic_Force> 			a_Block;
                NonAtomicBlock<Atomic_Force> 			a_NoBlock;

            - Status register safe mode.

                AtomicBlock<Atomic_RestoreState, _Safe> 		a_Block;
                NonAtomicBlock<Atomic_RestoreState, _Safe> 	n_NoBlock;

                AtomicBlockSafe<Atomic_RestoreState> 			a_BlockSafe;
                NonAtomicBlockSafe<Atomic_RestoreState> 		n_NoBlockSafe;

                AtomicBlock<Atomic_Force, _Safe> 				a_Block;
                NonAtomicBlock<Atomic_Force, _Safe> 			n_NoBlock;

                AtomicBlockSafe<Atomic_Force> 				a_BlockSafe;
                NonAtomicBlockSafe<Atomic_Force> 				n_NoBlockSafe;

            - Sample usage.

                ISR(TIMER0_COMPA_vect)
                    {
                        AtomicBlock<Atomic_RestoreState> 	a_Block;
                        //Read some data.
                        //...
                        {
                            NonAtomicBlock<Atomic_Force> 	a_NoBlock;
                            //Calculate new data
                            //...
                        }
                        //Write some data
                    }


            CAUTION: 	As the atomic operation lasts for the lifetime of the variable, anything
                        before the declaration will not be protected. Use extra scope operators
                         '{' and '}' to help make things clearer if needed.

        Usage type 2

            Each blocking type contains a function named 'Protect'. It can be used to
            protect any kind of element.

            E.g.

                - Typedefs make using 'Protect' easier.
                    typedef NonAtomicBlock<Atomic_Force> MyBlock;

                For the sake of these examples 'i' is an 'int'.

                - Protected writes
                    MyBlock::Protect( i ) = analogRead( A0 );

                - Protected reads
                    Serial.println( MyBlock::Protect( i ) );

                - Protected non-member function calls.
                    MyBlock::Protect( inc )( i );

                - Protected pointers
                    *( &MyBlock::Protect( i ) ) = 77;
                    (*MyBlock::Protect( &i ))++;

                - No unnecessary instructions.
                    - This will not produce any code.
                        MyBlock::Protect( 1 + 2 + 3 + 4 + 5 );
                    - These two lines produce exactly the same code.
                        digitalWrite( MyBlock::Protect( 13 ), digitalRead( MyBlock::Protect( 13 ) ) ^ 1 );
                        digitalWrite( 13, digitalRead( 13 ) ^ 1 );
                    - This will only turn interrupts on and off once.
                        MyBlock::Protect( MyBlock::Protect( MyBlock::Protect( MyBlock::Protect( i ) ) ) );

            CAUTION: 'Protect' will only protect one element. Statements as arguments are not going to work as expected.
                E.g.

                    - Wrong use. ( argument statement will not be blocked. If you use the result, it will be inside the atomic block. )
                        MyBlock::Protect( PORTK |= _BV( 5 ) );

                    - Correct usage. ( just 'Protect' PORTK )
                        MyBlock::Protect( PORTK ) |= _BV( 5 );

            LIMITATIONS:

                    * I have chosen not to support any sort of member function protection. Once I have validated the current system
                    I can look further into it. The required interface seems to generalise the type system too much and breaks some
                    existing functionality as the compiler cannot disambiguate the control paths.

        Version history
            - 1.2

                Now supports:
                    AVR 8-bit processors supporting SREG
                        Arduino 8-bit family 							( Compiled / Tested )
                        Teensy 2.0										( Not Compiled / Not Tested )
                        Teensy++ 2.0									( Not Compiled / Not Tested )
            - 1.1
                Added 'Protect' method.
            - 1.0
                Safe mode added into  Atomic_RestoreState
            - 0.1
                Initial design
*/

#ifndef HEADER_ATOMICBLOCK
#define HEADER_ATOMICBLOCK

/*********************************************************************
    GNU GCC Specific.
    ------------------
    Old compilers and/or missing optimisation flags can cause
    elements to not be inlined. For example, the Maple IDE will
    create inefficient code, whereas Arduino ATMega and Due
    tool chains compile very efficient code.

    To solve the problem in the Maple IDE some empty constructor/
    destructor pairs had to be added with an inline hint.

    Appears to be related to compiler generated elements,
    temporary values and implicit constructor/destructor's.

    __COMPILER__INLINE__ provides a portable way of implementing GCC specifics.
    On modern compilers with good optimisation flags, inline will
    have no additional benefits for the code.
*********************************************************************/

#ifdef __GNUC__
    #define __COMPILER__INLINE__ __attribute__( ( always_inline ) ) inline
#else
    #define __COMPILER__INLINE__ inline
#endif

#include "../stl/cstdint.h"
#include "../avr/io.h"

namespace vAVR {
    namespace atomic {
        namespace internal {

            static constexpr bool _Safe = true;

            /*** GlobalInterrupts On/Off function prototypes must not change. ***/
            __COMPILER__INLINE__ static void GlobalInterruptsOff()
            {
                __asm__ __volatile__("cli" ::: "memory");
            }
            __COMPILER__INLINE__ static void GlobalInterruptsOn()
            {
                __asm__ __volatile__("sei" ::: "memory");
            }

            /*********************************************************************
                _AtomicWrapper interface.
                    Intended as a temporary object for 'Protect' function.
                    Its '_BlockType' is effective throughout its life/scope.
            *********************************************************************/
            template<typename _BlockType, typename _ContainedType>
            class _AtomicWrapper
            {
                _BlockType		b_Block;
                _ContainedType	&c_Object;

            protected:
                template<typename>
                friend class _AtomicInline;

                __COMPILER__INLINE__ explicit _AtomicWrapper(_ContainedType& o_OwningObject)
                    : b_Block(), c_Object(o_OwningObject) {}

            public:
                __COMPILER__INLINE__ ~_AtomicWrapper() {}

                __COMPILER__INLINE__ operator _ContainedType&()
                {
                    return this->c_Object;
                }

                __COMPILER__INLINE__ operator _ContainedType&() const
                {
                    return this->c_Object;
                }

                template<typename _Type>
                __COMPILER__INLINE__ _AtomicWrapper<_BlockType, _ContainedType>& operator=(const _Type& t_Copy)
                {
                    this->c_Object = t_Copy;
                    return *this;
                }
            };

            /*********************************************************************
                _TypeSeparator interface.
                    Provides instantiation objects for 'Protect'. This allows
                    standard and volatile components whereas constant values do
                    not need protecting so they do not get diverted through
                    _AtomicWrapper.
            *********************************************************************/

            template<typename _BlockType, typename _Type>
            struct _TypeSeparator
            {
                using TemporaryType = _AtomicWrapper<_BlockType, _Type>;
            };

            template<typename _BlockType, typename _Type>
            struct _TypeSeparator<_BlockType, volatile _Type&>
            {
                using TemporaryType = _AtomicWrapper<_BlockType, volatile _Type>;
            };

            template<typename _BlockType, typename _Type>
            struct _TypeSeparator<_BlockType, const _Type>
            {
                using TemporaryType = const _Type&;
            };


            /*********************************************************************
                _AtomicInline interface.
                    Provider of 'Protect' function for 'Atomic' & 'NonAtomic'
                    interfaces. This interface is not intended for direct use.
            *********************************************************************/
            template<typename _BlockType>
            class _AtomicInline
            {
                __COMPILER__INLINE__ _AtomicInline() {}
                __COMPILER__INLINE__ ~_AtomicInline() {}
            protected:
                template<template<bool, bool> class, bool> 	friend class AtomicBlock;
                template<template<bool, bool> class, bool> 	friend class NonAtomicBlock;
                template<template<bool, bool> class> 		friend class AtomicBlockSafe;
                template<template<bool, bool> class> 		friend class NonAtomicBlockSafe;
            public:
                template<typename _Type>                                      // template parameter
                __COMPILER__INLINE__ static                                   // function attributes
                    typename _TypeSeparator<_BlockType, _Type>::TemporaryType // return type
                    Protect(_Type& t_Var)                                     // name binding and parameter type
                {
                    return typename _TypeSeparator<_BlockType, _Type>::TemporaryType(t_Var);
                }

                template<typename _Type>
                __COMPILER__INLINE__ static
                    typename _TypeSeparator<_BlockType, const _Type>::TemporaryType
                    Protect(const _Type& t_Var)
                {
                    return typename _TypeSeparator<_BlockType, const _Type>::TemporaryType(t_Var);
                }
            };
        }

        /*********************************************************************
            Atomic_RestoreState interface.
                This mode is used to do either an atomic or non-atomic
                operation when the state of the interrupts are at an
                unknown state.

                This mode also makes use of  the '_SafeRestore' flag, if bits
                are modified in the interrupt register during the atomic
                operation, this will prevent the bits being reset during the
                restore operation. Some platforms do not use this feature.

                The operation depends on the value of '_Atomic'.
        *********************************************************************/

        /*********************************************************************
            Atomic_RestoreState AVR specific.
                This will cause SREG to be returned to its original value
                at the end of its life. Its function depends on '_Atomic'.
        *********************************************************************/
        template<bool _Atomic, bool _SafeRestore = false>
        struct Atomic_RestoreState
        {
            __COMPILER__INLINE__ Atomic_RestoreState() : u_SREG(mcu::SREG::get())
            {
                ((_Atomic ?
                    internal::GlobalInterruptsOff :
                    internal::GlobalInterruptsOn))();
            }

            __COMPILER__INLINE__ ~Atomic_RestoreState()
            {
                if (_SafeRestore)
                {
                    if (_Atomic && mcu::SREG_I::get() ) internal::GlobalInterruptsOn();
                    if (!_Atomic && !mcu::SREG_I::get()) internal::GlobalInterruptsOff();
                }
                else
                {
                    mcu::SREG::set(this->u_SREG);
                }
            }

            const stl::uint8_t u_SREG;
        };

        /*********************************************************************
            Atomic_Force interface.
                This will force the current state of interrupts to be a
                state depending on '_Atomic'. If true, the operation is
                atomic. If false the operation is non-atomic.
        *********************************************************************/

        template<bool _Atomic, bool _Unused = true>
        struct Atomic_Force
        {
            __COMPILER__INLINE__ Atomic_Force()
            {
                (_Atomic ?
                    internal::GlobalInterruptsOff :
                    internal::GlobalInterruptsOn)();
            }

            __COMPILER__INLINE__ ~Atomic_Force()
            {
                (_Atomic ?
                    internal::GlobalInterruptsOn :
                    internal::GlobalInterruptsOff)();
            }
        };

        /*********************************************************************
            Main high-level interfaces.

             -	AtomicBlock			Disables interrupts during operation.

             -	AtomicBlockSafe		Disables interrupts during operation.
                                    Atomic_RestoreState uses a register safe
                                    version if applicable.

             -	NonAtomicBlock		Enables interrupts during operation.

             -	NonAtomicBlockSafe	Enables interrupts during operation.
                                    Atomic_RestoreState uses a register safe
                                    version if applicable.
        *********************************************************************/
        template<template<bool, bool> class _AtomicMode, bool _SafeRestore = false>
        struct AtomicBlock
            : _AtomicMode<true, _SafeRestore>,
            internal::_AtomicInline<AtomicBlock<_AtomicMode, _SafeRestore>>
        {
            __COMPILER__INLINE__ explicit AtomicBlock()
                : _AtomicMode<true, _SafeRestore>(),
                internal::_AtomicInline<AtomicBlock<_AtomicMode, _SafeRestore>>() {}

            __COMPILER__INLINE__ ~AtomicBlock() {}
        };

        template<template<bool, bool> class _AtomicMode, bool _SafeRestore = false>
        struct NonAtomicBlock
            : _AtomicMode<false, _SafeRestore>,
            internal::_AtomicInline<NonAtomicBlock<_AtomicMode, _SafeRestore>>
        {
            __COMPILER__INLINE__ explicit NonAtomicBlock()
                : _AtomicMode<false, _SafeRestore>(),
                internal::_AtomicInline<NonAtomicBlock<_AtomicMode, _SafeRestore>>() {}

            __COMPILER__INLINE__ ~NonAtomicBlock() {}
        };

        template<template<bool, bool> class _AtomicMode>
        struct AtomicBlockSafe
            : _AtomicMode<true, true>,
            internal::_AtomicInline<AtomicBlockSafe<_AtomicMode>>
        {
            __COMPILER__INLINE__ explicit AtomicBlockSafe()
                : _AtomicMode<true, true>(),
                internal::_AtomicInline<AtomicBlockSafe<_AtomicMode>>() {}

            __COMPILER__INLINE__ ~AtomicBlockSafe() {}
        };

        template<template<bool, bool> class _AtomicMode>
        struct NonAtomicBlockSafe
            : _AtomicMode<false, true>,
            internal::_AtomicInline<NonAtomicBlockSafe<_AtomicMode>>
        {
            __COMPILER__INLINE__ explicit NonAtomicBlockSafe()
                : _AtomicMode<false, true>(),
                internal::_AtomicInline<NonAtomicBlockSafe<_AtomicMode>>() {}

            __COMPILER__INLINE__ ~NonAtomicBlockSafe() {}
        };

        /*********************************************************************
            Atomic_None interface.
                This addition allows objects to implement conditional
                atomic blocking, allowing support for thread/ISR safe code.
                If a user of the object has no need for synchronisation or
                thread safety, passing Atomic_None stops the interrupt
                handling instructions from being generated.
        *********************************************************************/
        template<bool _Unused_A = true, bool _Unused_B = true>
        struct Atomic_None {};

        /*********************************************************************
            AtomicIf helper.
                'AtomicIf<bool, mode>::AType' is type 'AtomicBlock<x>'
                where 'x' is 'mode' when 'bool' is true,
                otherwise 'x' is Atomic_None.
        *********************************************************************/
        template<bool b_UseAtomic,
            template<bool, bool> class _AtomicMode = Atomic_RestoreState>
        struct AtomicIf
        {
            using AType = AtomicBlock<Atomic_None>;
        };

        template<template<bool, bool> class _AtomicMode>
        struct AtomicIf<true, _AtomicMode>
        {
            using AType = AtomicBlock<_AtomicMode>;
        };
    }
} /* end of namespace vAVR */

#endif

