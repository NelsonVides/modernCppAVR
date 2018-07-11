#ifndef HEADER_MUTEX
#define HEADER_MUTEX

#include "AtomicBlock.h"
#include "../stl/cstdint.h"

namespace vAVR {
    namespace Sync {

        using TID = unsigned char;
        using HLOCK = const unsigned int;
        using HMUTEX = const stl::uint16_t;
        using HTASK = const stl::uint16_t; // User task handle is separate from task ID.

        enum class MUTEX_BLOCK : stl::uint8_t {
            m_Restore,
            m_Force,
            m_None,
        };

        enum class LOCK_MODE : stl::uint8_t {
            l_Simple,
            l_Recursive,
        };

        constexpr auto LOCK_FREE = 0xFF;

#ifdef _BOUNDS_CHECK
    #define LOCK_BOUNDS_CHECK ( MT::c_Counter & ( LOCK_FREE - 1 ) )
#else
    #define LOCK_BOUNDS_CHECK 0
#endif

        /**************************************************************************************
            Compile time counter.

                Evaluate the counter by finding the last defined overload.
                Each function, when defined, alters the lookup sequence for
                lower-order functions.
                Restricted by size of unsigned int.

            Original author and details can be found here:
            http://stackoverflow.com/questions/6166337/does-c-support-compile-time-counters
        **************************************************************************************/
        template<size_t _Size> // This type returns a number through function lookup.
        struct cn              // The function returns cn<n>.
        {
            char data[_Size + 1];
        }; // The caller uses (sizeof fn() - 1).

        template<typename _Id, size_t _Size, size_t _Acc>
        cn<_Acc> seen(_Id, cn<_Size>, cn<_Acc>); // Default fallback case.

        /* Evaluate the counter by finding the last defined overload.
        Each function, when defined, alters the lookup sequence for lower-order
        functions. */
#define counter_read(id) \
        (sizeof seen(id(), cn<1>(), cn<\
        (sizeof seen(id(), cn<2>(), cn<\
        (sizeof seen(id(), cn<4>(), cn<\
        (sizeof seen(id(), cn<8>(), cn<\
        (sizeof seen(id(), cn<16>(), cn<\
        (sizeof seen(id(), cn<32>(), cn<\
        (sizeof seen(id(), cn<64>(), cn<\
        (sizeof seen(id(), cn<128>(), cn<\
        (sizeof seen(id(), cn<256>(), cn<\
        (sizeof seen(id(), cn<512>(), cn<\
        (sizeof seen(id(), cn<1024>(), cn<\
        (sizeof seen(id(), cn<2048>(), cn<\
        (sizeof seen(id(), cn<4096>(), cn<\
        (sizeof seen(id(), cn<8192>(), cn<\
        (sizeof seen(id(), cn<16384>(), cn<0 \
        >() ) - 1 )>() ) - 1 ) \
        >() ) - 1 )>() ) - 1 ) \
        >() ) - 1 )>() ) - 1 ) \
        >() ) - 1 )>() ) - 1 ) \
        >() ) - 1 )>() ) - 1 ) \
        >() ) - 1 )>() ) - 1 ) \
        >() ) - 1 )>() ) - 1 ) \
        >() ) - 1 )

        /*********************************************************************
            counter_inc macro
            Define a single new function with place-value equal to the bit
            flipped to 1 by the increment operation.
            This is the lowest-magnitude function yet undefined in the
            current context of defined higher-magnitude functions.
        *********************************************************************/
#define counter_inc( id ) \
        cn<counter_read( id ) + 1> \
            seen( id, cn<( counter_read( id ) + 1 ) & ~ counter_read( id )>, \
                  cn<( counter_read( id ) + 1 ) & counter_read( id )> )


#define CounterMove        counter_inc
#define CounterValue    counter_read
#define CreateCounter( x ) struct x{}

        //Global counters, ensures globally unique values
        //(Pre-defined __COUNTER__ values are unique only to a translation unit.).
        CreateCounter(__MUTEX_GLOBAL_CNT);
        CreateCounter(__TASK_GLOBAL_CNT);
        /*********************************************************************
        Working data.
        *********************************************************************/
        extern TID _G_TASK_ID_;
        extern bool _G_SAFE_CALL_FLAG;

        /*********************************************************************
            Select.
                Selects a type based on '_Condition'.
        *********************************************************************/
        template<bool _Condition, typename _True, typename _False>
        struct Select
        {
            using Result = _True;
        };

        template<typename _True, typename _False>
        struct Select<false, _True, _False>
        {
            using Result = _False;
        };

        /*********************************************************************
            LockMode class.
                This interface is a lookup table for GlobalLock's to see what
                type they are defined as ( recursive or non-recursive ).
        *********************************************************************/
        template<HLOCK _LOCK_ID>
        struct LockMode
        {
            enum {
                Mode = 0xBADF00D
            };
        };

        /*********************************************************************
            GlobalLock class.
        *********************************************************************/
        template<HLOCK _LOCK_ID>
        class GlobalLock {

            template<HMUTEX, MUTEX_BLOCK> friend class Mutex; //Only thing allowed to touch this interface.

            using MyType = GlobalLock<_LOCK_ID>;
            using LockInternal = LockMode<_LOCK_ID>;

            /*********************************************************************
                If these lines below:                                                */
            enum {
                Validate_lock_integrity = sizeof(typename LockInternal::Invalid_lock_handle___Use_createMutex)
            };
            __COMPILER__INLINE__ GlobalLock() {}
            __COMPILER__INLINE__ ~GlobalLock() {}
            /*    are the cause of your error, you have attempted to use
                a lock directly rather than one provided by the system.

                Locks are an internal interface and must not be used directly to
                ensure integrity, use createMutex to generate a valid handle.
            *********************************************************************/

            struct SimpleLock
            {
                static bool ReferenceStart(const TID t_TaskID)
                {
                    t_Task = t_TaskID;
                    return true;
                }

                static bool ReferenceDecrease(const TID t_TaskID)
                {
                    if (t_Task == t_TaskID) return t_Task = LOCK_FREE;
                    return false;
                }

                static bool ReferenceIncrease(const TID t_TaskID)
                {
                    return false;
                }
                static volatile TID t_Task;
            };

            struct RecursiveLock
            {
                static bool ReferenceStart(const TID t_TaskID)
                {
                    t_Task = t_TaskID;
                    return c_Counter = 0x1;
                }

                static bool ReferenceDecrease(const TID t_TaskID)
                {
                    if (t_Task != t_TaskID) return false;
                    if (--c_Counter == 0x0) t_Task = LOCK_FREE;
                    return true;
                }

                static bool ReferenceIncrease(const TID t_TaskID)
                {
                    if ((t_Task != t_TaskID) || LOCK_BOUNDS_CHECK) return false;
                    return ++c_Counter;
                }

                static volatile unsigned char c_Counter;
                static volatile TID              t_Task;
            };

            using LockData = typename Select<LockInternal::Mode == LOCK_MODE::l_Recursive, RecursiveLock, SimpleLock>::Result;

            __COMPILER__INLINE__ static bool InUse()
            {
                return LockData::t_Task != LOCK_FREE;
            }

            __COMPILER__INLINE__ static bool IsOwned(const TID t_TaskID)
            {
                return LockData::t_Task == t_TaskID;
            }

            __COMPILER__INLINE__ static bool Lock(const TID t_TaskID)
            {
                return (InUse() ? LockData::ReferenceIncrease : LockData::ReferenceStart)(t_TaskID);
            }

            __COMPILER__INLINE__ static bool Unlock(const TID t_TaskID)
            {
                return LockData::ReferenceDecrease(t_TaskID);
            }
        };

        //Initial lock values.
        template<HLOCK _LOCK_ID> volatile unsigned char GlobalLock<_LOCK_ID>::RecursiveLock::c_Counter = 0x0;
        template<HLOCK _LOCK_ID> volatile TID GlobalLock<_LOCK_ID>::RecursiveLock::t_Task = LOCK_FREE;
        template<HLOCK _LOCK_ID> volatile TID GlobalLock<_LOCK_ID>::SimpleLock::t_Task = LOCK_FREE;

        /*********************************************************************
            ModeSelector class.
        *********************************************************************/
        template<MUTEX_BLOCK _BlockMode> struct ModeSelector;

        template<> struct ModeSelector<MUTEX_BLOCK::m_Restore>
        {
            using Result = atomic::AtomicBlock<atomic::Atomic_RestoreState>;
        };
        template<> struct ModeSelector<MUTEX_BLOCK::m_Force>
        {
            using Result = atomic::AtomicBlock<atomic::Atomic_Force>;
        };
        template<> struct ModeSelector<MUTEX_BLOCK::m_None>
        {
            using Result = atomic::AtomicBlock<atomic::Atomic_None>;
        };

        /*********************************************************************
            Mutex class.
        *********************************************************************/
        template<HMUTEX _MUTEX_ID, MUTEX_BLOCK _BlockMode = MUTEX_BLOCK::m_Force>
        class Mutex
        {
        protected:
            using GLock = GlobalLock<_MUTEX_ID>;
            using thisBlock = typename ModeSelector<_BlockMode>::Result;
        public:
            __COMPILER__INLINE__ static bool InUse()
            {
                return thisBlock::Protect(GLock::InUse)();
            }

            __COMPILER__INLINE__ static bool IsOwner(const TID _TASK_ID)
            {
                return thisBlock::Protect(GLock::IsOwned)(_TASK_ID);
            }

            __COMPILER__INLINE__ static bool Lock(const TID _TASK_ID)
            {
                return thisBlock::Protect(GLock::Lock)(_TASK_ID);
            }

            __COMPILER__INLINE__ static TID Owner()
            {
                return thisBlock::Protect(GLock::LockInternal::t_Task);
            }

            __COMPILER__INLINE__ static bool Unlock(const TID _TASK_ID)
            {
                return thisBlock::Protect(GLock::Unlock)(_TASK_ID);
            }
        };


        /*********************************************************************
            MutexData structure.
                This interface deconstructs a mutex handle to its definition.
        *********************************************************************/
        template<HMUTEX _Val>
        struct MutexData
        {
            enum {
                BlockTypeID = stl::uint8_t(_Val >> 0x8),    // What sort of blocking the mutex uses.
                MutexID = stl::uint8_t(_Val),                // The ID of the mutex.
            };
        };

        struct ChangeFocus
        {
            ChangeFocus(const TID &t_New) : t_Store(_G_TASK_ID_)
            {
                _G_TASK_ID_ = t_New;
            }

            ~ChangeFocus()
            {
                _G_TASK_ID_ = t_Store;
            }

            const TID t_Store;
        };


        /*********************************************************************
            User interface.
        *********************************************************************/
        __COMPILER__INLINE__ void safeCall(void(*_Func)())
        {
            _G_SAFE_CALL_FLAG = true;
            _Func();
            _G_SAFE_CALL_FLAG = false;
        }

#define createMutex( atomic_mode ) \
                                createMutexEx( atomic_mode, LOCK_MODE::l_Recursive )

#define createMutexEx( atomic_mode, lock_mode ) \
                                ( HMUTEX( atomic_mode ) <<0x8 ) | ( HMUTEX ) byte( CounterValue( __MUTEX_GLOBAL_CNT ) ); \
                                template<> class LockMode<CounterValue( __MUTEX_GLOBAL_CNT )>{ \
                                    template<HLOCK> friend class GlobalLock; \
                                    enum{ Mode = lock_mode }; \
                                    typedef unsigned long long int Invalid_lock_handle___Use_createMutex; }; \
                                CounterMove( __MUTEX_GLOBAL_CNT )

#define duplicateHandle( mutex_handle, atomic_mode ) \
                                ( HMUTEX( atomic_mode ) <<0x8 ) | ( HMUTEX ) byte( MutexData<mutex_handle>::MutexID )

#define acquireMutex( mutex_handle ) \
                                getMutexType( mutex_handle )::Lock( getTaskID() )

#define releaseMutex( mutex_handle ) \
                                getMutexType( mutex_handle )::Unlock( getTaskID() )

#define getOwner( mutex_handle ) \
                                getMutexType( mutex_handle )::Owner()

#define getMutexType( mutex_handle ) \
                                Mutex<MutexData<mutex_handle>::MutexID, ( MUTEX_BLOCK ) MutexData<mutex_handle>::BlockTypeID>

#define getMutexMode( mutex_handle ) \
                                MutexData<mutex_handle>::BlockTypeID

#define registerTask( name ) \
                                ~( ( ( HTASK ) CounterValue( __TASK_GLOBAL_CNT ) + 1 ) <<0x8 ); \
                                template<TID _G_TASK_ID_> void name( void ); \
                                void name( void ){ \
                                    const TID t_This = CounterValue( __TASK_GLOBAL_CNT ) + 0x1; \
                                    if( ::_G_SAFE_CALL_FLAG ) name<t_This>(); \
                                    else{ \
                                        ChangeFocus cf( t_This ); \
                                        name<t_This>(); \
                                    } \
                                } \
                                CounterMove( __TASK_GLOBAL_CNT )

#define getTaskFromHandle( htask ) \
                                (~htask)>> 0x8

#define isOwner( mutex_handle ) \
                                getOwner( mutex_handle ) == getTaskID()

#define getTaskID(empty_list) \
                                ::_G_TASK_ID_

#define _TASK_                template<TID _G_TASK_ID_> __COMPILER__INLINE__

    } /* end of namespace Sync */
} /* end of namespace vAVR */

#endif