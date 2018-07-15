#pragma once

#include "../stl/cstdint.h"
#include "../stl/type_traits.h"
#include "../stl/utility.h"
#include "HeapPatientQueue.h"
#include "vTask.h"

namespace vAVR {
    template<stl::uint8_t N>
    class Scheduler
    {
        HeapPatientQueue<vTask*, N> runningQueue;
        HeapPatientQueue<vTask*, N> readyQueue;
        HeapPatientQueue<vTask*, N> blockedQueue;

    public:
        void RunWorld() {}
    };
}