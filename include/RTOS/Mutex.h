#ifndef HEADER_MUTEX
#define HEADER_MUTEX

#include "AtomicBlock.h"
#include "../stl/cstdint.h"
#include "../stl/type_traits.h"

namespace vAVR {
    namespace Sync {

        using TaskID = stl::uint8_t;
        constexpr stl::uint8_t LOCK_FREE = 0xFF;
        class vTask; //forward declaration to tasks

        enum class MUTEX_BLOCK {
            m_Restore,
            m_Force,
            m_None,
        };

        enum class LOCK_MODE {
            l_Simple,
            l_Recursive,
        };

        namespace internal {

            template<typename LockType>
            struct LockBase
            {
            protected:
                template<MUTEX_BLOCK,LOCK_MODE> friend class Mutex;
                vTask* t_Task;
                volatile unsigned char c_Counter;
                LockBase(vTask* owner) : t_Task(owner) {}

            public:
                bool ReferenceStart(vTask *const p_Task)
                {
                    return static_cast<LockType*>(this)->ReferenceStartImpl(p_Task);
                }
                bool ReferenceDecrease(vTask *const p_Task)
                {
                    return static_cast<LockType*>(this)->ReferenceDecreaseImpl(p_Task);
                }
                bool ReferenceIncrease(vTask *const p_Task)
                {
                    return static_cast<LockType*>(this)->ReferenceIncreaseImpl(p_Task);
                }
            };

            class SimpleLock : LockBase<SimpleLock>
            {
                __COMPILER__INLINE__ bool ReferenceStartImpl(vTask*const p_Task)
                {
                    t_Task = p_Task;
                    return (c_Counter = true);
                }

                __COMPILER__INLINE__ bool ReferenceDecreaseImpl(vTask*const p_Task)
                {
                    if (t_Task == p_Task) return (c_Counter = true);
                    return false;
                }

                __COMPILER__INLINE__ bool ReferenceIncreaseImpl(vTask*const p_Task)
                {
                    if (t_Task == p_Task) return (c_Counter = false);
                    return false;
                }
            };

            class RecursiveLock : LockBase<RecursiveLock>
            {
                __COMPILER__INLINE__ bool ReferenceStartImpl(vTask*const p_Task)
                {
                    t_Task = p_Task;
                    return (c_Counter = 0x1);
                }
                __COMPILER__INLINE__ bool ReferenceDecreaseImpl(vTask*const p_Task)
                {
                    if (t_Task != p_Task) return false;
                    if (--c_Counter == 0x0) return true;
                    return false;
                }
                __COMPILER__INLINE__ bool ReferenceIncreaseImpl(vTask*const p_Task)
                {
                    if ((t_Task != p_Task)) return false;
                    return ++c_Counter;
                }
            };

            /*********************************************************************
                AtomicPolicy class.
            *********************************************************************/
            template<MUTEX_BLOCK BlockMode> struct AtomicPolicy;
            template<> struct AtomicPolicy<MUTEX_BLOCK::m_Restore> {
                using Result = Atomic::AtomicBlock<Atomic::Atomic_RestoreState>;
            };
            template<> struct AtomicPolicy<MUTEX_BLOCK::m_Force> {
                using Result = Atomic::AtomicBlock<Atomic::Atomic_Force>;
            };
            template<> struct AtomicPolicy<MUTEX_BLOCK::m_None> {
                using Result = Atomic::AtomicBlock<Atomic::Atomic_None>;
            };

            /*********************************************************************
                LockPolicy class.
            *********************************************************************/
            template<LOCK_MODE LockMode> struct LockPolicy;
            template<> struct LockPolicy<LOCK_MODE::l_Simple> {
                using Result = SimpleLock;
            };
            template<> struct LockPolicy<LOCK_MODE::l_Recursive> {
                using Result = RecursiveLock;
            };
        }

        /*********************************************************************
            Mutex class.
        *********************************************************************/
        template<MUTEX_BLOCK _BlockMode = MUTEX_BLOCK::m_Force,
            LOCK_MODE _LockMode = LOCK_MODE::l_Recursive>
        class Mutex
        {
            using Atomicity = typename internal::AtomicPolicy<_BlockMode>::Result;
            using LockingKind = typename internal::LockPolicy<_LockMode>::Result;
            LockingKind m_Lock;
        
        public:
            explicit Mutex(vTask* p_Task) : m_Lock(p_Task) {}

            inline bool InUse() const
            {
                Atomicity temporaryAtom;
                return m_Lock.c_Counter != 0x00;
            }

            inline bool IsOwner(const vTask * const p_Task) const
            {
                Atomicity temporaryAtom;
                return m_Lock.t_Task == p_Task;
            }

            inline const vTask * Owner() const
            {
                Atomicity temporaryAtom;
                return m_Lock.t_Task;
            }

            inline bool Lock(const vTask * const p_Task)
            {
                Atomicity temporaryAtom;
                return (InUse() ? m_Lock.ReferenceIncrease : m_Lock.ReferenceStart)(p_Task);
            }

            __COMPILER__INLINE__ bool Unlock(const vTask * const p_Task)
            {
                Atomicity temporaryAtom;
                return m_Lock.ReferenceDecrease(p_Task);
            }
        };
    } /* end of namespace Sync */
} /* end of namespace vAVR */

#endif