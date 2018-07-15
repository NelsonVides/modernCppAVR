#pragma once

#include "../stl/cstdint.h"
#include "../stl/type_traits.h"
#include "../stl/utility.h"

namespace vAVR {

    class vTask
    {
        stl::uint8_t TaskID;
 
    public:
        void RunTask() {}
    };
}