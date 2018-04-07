#ifndef _TYPE_TRAITS_H_
#define _TYPE_TRAITS_H_

namespace atl {

#include<stdlib.h>

/* 
 * integral_constant; IMPORTANT
 */

template<typename T, T v>
struct integral_constant {
    static constexpr T value = v;
    using value_type = T;
    using type = integral_constant;
    constexpr operator value_type() const noexcept { return value; }
    constexpr value_type operator()() const noexcept { return value; }
    };

template<bool B> using bool_constant = integral_constant<bool, B>;
using true_type  = integral_constant<bool, true>;
using false_type = integral_constant<bool, false>;


/*
 * Type relationships
 */

template<typename T, typename U> struct is_same : false_type {};
template<typename T>             struct is_same<T, T> : true_type {};

/*
 * cv-specifiers
 */

template<typename T> struct remove_const          { using type = T; };
template<typename T> struct remove_const<const T> { using type = T; };

template<typename T> struct remove_volatile             { using type = T; };
template<typename T> struct remove_volatile<volatile T> { using type = T;  };

template<typename T> struct remove_cv { 
    using type = typename remove_volatile<typename remove_const<T>::type>::type; };

template<typename T> using remove_cv_t       = typename remove_cv<T>::type;
template<typename T> using remove_const_t    = typename remove_const<T>::type;
template<typename T> using remove_volatile_t = typename remove_volatile<T>::type;

template<typename T> struct add_cv       { using type = const volatile T; };
template<typename T> struct add_const    { using type = const T; };
template<typename T> struct add_volatile { using type = volatile T; };

template<typename T> using add_cv_t       = typename add_cv<T>::type;
template<typename T> using add_const_t    = typename add_const<T>::type;
template<typename T> using add_volatile_t = typename add_volatile<T>::type;


template<typename>   struct is_const : false_type {};
template<typename T> struct is_const<const T> : true_type {};

template<typename>   struct is_volatile : false_type {};
template<typename T> struct is_volatile<volatile T> : true_type {};


/*
 * reference-qualifiers
 */

template<typename>   struct is_lvalue_reference      : public false_type { };
template<typename T> struct is_lvalue_reference<T&>  : public true_type { };
template<typename>   struct is_rvalue_reference      : public false_type { };
template<typename T> struct is_rvalue_reference<T&&> : public true_type { };

template<typename T> struct remove_reference      { using type = T; };
template<typename T> struct remove_reference<T&>  { using type = T; };
template<typename T> struct remove_reference<T&&> { using type = T; };
template<typename T> using remove_reference_t = typename remove_reference<T>::type;

/*
 * pointer-qualifiers
 */
template<typename T> struct remove_pointer                    {using type = T;};
template<typename T> struct remove_pointer<T*>                {using type = T;};
template<typename T> struct remove_pointer<T* const>          {using type = T;};
template<typename T> struct remove_pointer<T* volatile>       {using type = T;};
template<typename T> struct remove_pointer<T* const volatile> {using type = T;};
template<typename T> using remove_pointer_t = typename remove_pointer<T>::type;

namespace detail {
    template<typename T> struct is_pointer_helper     : false_type {};
    template<typename T> struct is_pointer_helper<T*> : true_type {};
}
template<typename T> struct is_pointer : detail::is_pointer_helper<remove_cv_t<T>> {};

/*
 * essentials
 */
// is_void
template<typename T> struct is_void : is_same<void, remove_cv_t<T>> {};
//template<typename T> constexpr bool is_void_v = is_void<T>::value;

// is_null_pointer
using nullptr_t = decltype(nullptr);
template<typename T> struct is_null_pointer : is_same<nullptr_t, remove_cv_t<T>> {};

// is_integral
namespace detail {
    template<typename> struct is_integral_base: false_type {};
    template<> struct is_integral_base<bool>  : true_type {};
    template<> struct is_integral_base<char>   : true_type {};
    template<> struct is_integral_base<signed char> : true_type {};
    template<> struct is_integral_base<unsigned char> : true_type {};
    template<> struct is_integral_base<short> : true_type {};
    template<> struct is_integral_base<unsigned short> : true_type {};
    template<> struct is_integral_base<int> : true_type {};
    template<> struct is_integral_base<unsigned int> : true_type {};
    template<> struct is_integral_base<long> : true_type {};
    template<> struct is_integral_base<unsigned long> : true_type {};
    template<> struct is_integral_base<long long> : true_type {};
    template<> struct is_integral_base<unsigned long long> : true_type {};
}
template<typename T> struct is_integral: detail::is_integral_base<remove_cv_t<T>> {};

// is_floating_point
namespace detail {
    template<typename> struct is_float_base: false_type {};
    template<> struct is_float_base<float>  : true_type {};
    template<> struct is_float_base<double>   : true_type {};
    template<> struct is_float_base<long double> : true_type {};
}
template<typename T> struct is_floating_point: detail::is_float_base<remove_cv_t<T>> {};

// is_arithmetic
template<typename T> struct is_arithmetic 
        : integral_constant<bool, is_integral<T>::value || is_floating_point<T>::value> {};

// is_array
template<typename T> struct is_array : false_type {}; 
template<typename T> struct is_array<T[]> : true_type {};
template<typename T, size_t N> struct is_array<T[N]> : true_type {};

/*
 * numeric qualifiers
 */

namespace detail {
    template<typename T, bool = is_arithmetic<T>::value>
        struct is_signed : integral_constant<bool, T(-1) < T(0)> {};
    template<typename T> struct is_signed<T,false> : false_type {};
} // namespace detail
 
template<typename T> struct is_signed : detail::is_signed<T>::type {};


} //end of namespace atl
#endif


