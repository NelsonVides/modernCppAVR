#ifndef HEADER_MUTEX
#define HEADER_MUTEX

#include "AtomicBlock.h"
#include "../stl/cstdint.h"
#include "../stl/type_traits.h"

namespace vAVR {
    namespace Sync {

        using TaskID = stl::uint8_t;

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

            constexpr stl::uint8_t LOCK_FREE = 0xFF;

            template<typename LockChild>
            struct LockBase
            {
                bool ReferenceStart(const TaskID t_TaskID)
                {
                    return static_cast<LockChild*>(this)->ReferenceStartImpl(t_TaskID);
                }
                bool ReferenceDecrease(const TaskID t_TaskID)
                {
                    return static_cast<LockChild*>(this)->ReferenceDecreaseImpl(t_TaskID);
                }
                bool ReferenceIncrease(const TaskID t_TaskID)
                {
                    return static_cast<LockChild*>(this)->ReferenceIncreaseImpl(t_TaskID);
                }
            };

            class SimpleLock : LockBase<SimpleLock>
            {
                bool ReferenceStartImpl(const TaskID t_TaskID)
                {
                    t_Task = t_TaskID;
                    return true;
                }

                bool ReferenceDecreaseImpl(const TaskID t_TaskID)
                {
                    if (t_Task == t_TaskID) return (t_Task = LOCK_FREE);
                    return false;
                }

                bool ReferenceIncreaseImpl(const TaskID t_TaskID)
                {
                    (void)t_TaskID;
                    return false;
                }

                volatile TaskID t_Task;
            };

            class RecursiveLock : LockBase<SimpleLock>
            {
                bool ReferenceStartImpl(const TaskID t_TaskID)
                {
                    t_Task = t_TaskID;
                    return (c_Counter = 0x1);
                }
                bool ReferenceDecreaseImpl(const TaskID t_TaskID)
                {
                    if (t_Task != t_TaskID) return false;
                    if (--c_Counter == 0x0) t_Task = LOCK_FREE;
                    return true;
                }
                bool ReferenceIncreaseImpl(const TaskID t_TaskID)
                {
                    if ((t_Task != t_TaskID)) return false;
                    return ++c_Counter;
                }
                volatile unsigned char c_Counter;
                volatile TaskID        t_Task;
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
        // TODO: make some enum for classes.
        template<HMUTEX _MUTEX_ID,
            MUTEX_BLOCK _BlockMode = MUTEX_BLOCK::m_Force,
            LOCK_MODE   _LockMode = LOCK_MODE::l_Recursive>
        class Mutex
        {
            using Atomicity = typename internal::AtomicPolicy<_BlockMode>::Result;
            using LockingKind = typename internal::LockPolicy<_LockMode>::Result;
        
        public:
            __COMPILER__INLINE__ bool InUse()
            {
                Atomicity temporaryAtom;
                return (LockingKind::t_Task != internal::LOCK_FREE)();
            }

            __COMPILER__INLINE__ bool IsOwner(const TaskID _TASK_ID)
            {
                Atomicity temporaryAtom;
                return LockingKind::t_Task == _TASK_ID;
            }

            __COMPILER__INLINE__ bool Lock(const TaskID _TASK_ID)
            {
                Atomicity temporaryAtom;
                return (InUse() ? LockingKind::ReferenceIncrease : LockingKind::ReferenceStart)(_TASK_ID);
            }

            __COMPILER__INLINE__ TaskID Owner()
            {
                Atomicity temporaryAtom;
                return LockingKind::t_Task;
            }

            __COMPILER__INLINE__ bool Unlock(const TaskID _TASK_ID)
            {
                Atomicity temporaryAtom;
                return LockingKind::ReferenceDecrease(_TASK_ID);
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
                BlockTypeID = stl::uint8_t(_Val >> 0x8),     // What sort of blocking the mutex uses.
                MutexID = stl::uint8_t(_Val),                // The ID of the mutex.
            };
        };

    } /* end of namespace Sync */
} /* end of namespace vAVR */

#endif