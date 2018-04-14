#ifndef _GLIBCXX_UTILITY
#define _GLIBCXX_UTILITY 1

#include "type_traits.h"

namespace stl {

    template<typename T>
        decltype(auto) move(T&& param)
        {
            using ReturnType = remove_reference_t<T>&&;
            return static_cast<ReturnType>(param);
        }

    /// identity
    namespace detail {
        template<typename T>
            struct identity
            {
                using type = T;
            };
    }

    /// forward (as per N2835)
    /// Forward lvalues as rvalues.
    template<typename T>
        inline constexpr typename enable_if<!is_lvalue_reference<T>::value, T&&>::type
        forward(typename detail::identity<T>::type& t)
        {
            return static_cast<T&&>(t); 
        }

    /// Forward rvalues as rvalues.
    template<typename T>
        inline constexpr typename enable_if<!is_lvalue_reference<T>::value, T&&>::type
        forward(typename detail::identity<T>::type&& t)
        { 
            return static_cast<T&&>(t); 
        }

    /// Forward lvalues as lvalues.
    template<typename T>
        inline constexpr typename enable_if<is_lvalue_reference<T>::value, T>::type
        forward(typename detail::identity<T>::type t)
        { 
            return t;
        }

    /// Prevent forwarding rvalues as const lvalues.
    template<typename T>
        inline constexpr typename enable_if<is_lvalue_reference<T>::value, T>::type
        forward(remove_reference_t<T>&& t) = delete;

    /**
     * * @brief Check if a given value is in a specific range
     * * @param value The value to check
     * * @param low The lower bound (inclusive)
     * * @param high The upper bound (inclusive)
     * * @since 1.0.0
     * */
    template<typename ValueType> //, enable_if_t<is_integral<remove_reference_t<ValueType>>::value  > >
        constexpr auto in_range(ValueType value, ValueType low, ValueType high)
        { 
            return value >= low && value <= high; 
        }



} /* end of namespace stl */

#endif

