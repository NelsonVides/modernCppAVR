#ifndef STL_CSTDINT_HPP
#define STL_CSTDINT_HPP

/**
 * * @file
 * * @brief Standard integer types
 * * @since 1.0.0
 * */

namespace stl
{
#ifdef __DOXYGEN__
    using int8_t = implementation_defined;
    using int16_t = implementation_defined;
    using int32_t = implementation_defined;
    using int64_t = implementation_defined;
    using uint8_t = implementation_defined;
    using uint16_t = implementation_defined;
    using uint32_t = implementation_defined;
    using uint64_t = implementation_defined;
#else
    using int8_t = __INT8_TYPE__;
    using int16_t = __INT16_TYPE__;
    using int32_t = __INT32_TYPE__;
    using int64_t = __INT64_TYPE__;
    using uint8_t = __UINT8_TYPE__;
    using uint16_t = __UINT16_TYPE__;
    using uint32_t = __UINT32_TYPE__;
    using uint64_t = __UINT64_TYPE__;
#endif

}

#endif

