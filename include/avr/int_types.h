#ifndef STL_INT_TYPES_H
#define STL_INT_TYPES_H

#ifndef AVR_INTERNAL_REGISTERS_HPP
#error "Don't add this directly! Only to be used within Internal::Registers"
#endif

#include "../stl/cstdint.h"
#include "../stl/type_traits.h"

namespace stl { 
    namespace int_types {

        /**
         * * @brief A template to determine the exact int type to represent the given size
         * * This template provides integer types that match the given size exactly. If a given size can be represented exaclty, it provides a member type called @p type that is an alias for the repective integer type.
         * * @tparam Size The desired size of the type
         * * @see #atl::int_types::uint_for_size For the equivalent helper for unsigned types
         * * @since 1.0.0
         * */
        template<int Size> struct int_for_size;
        template<>         struct int_for_size<8>  { using type = int8_t; };
        template<>         struct int_for_size<16> { using type = int16_t; };
        template<>         struct int_for_size<32> { using type = int32_t; };
        template<>         struct int_for_size<64> { using type = int64_t; };
        template<int Size> using int_for_size_t = typename int_for_size<Size>::type;

        template<int Size> struct uint_for_size : make_unsigned<int_for_size_t<Size>> { };
        template<int Size> using uint_for_size_t = typename uint_for_size<Size>::type;
    }
}

#endif

