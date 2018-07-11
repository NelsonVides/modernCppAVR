#ifndef _TYPE_TRAITS_H_
#define _TYPE_TRAITS_H_

#include <stddef.h>
#include "../stdlib.h"

namespace stl {

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
     * function qualifiers
     */
    // primary template
    template<class> struct is_function : false_type { };
    // specialization for regular functions
    template<class Ret, class... Args> struct is_function<Ret(Args...)> : true_type {};
    //specialization for variadic functions such as printf
    template<class Ret, class... Args> struct is_function<Ret(Args......)> : true_type {};
    //specialization for function types that have cv-qualifiers
    template<class Ret, class... Args> struct is_function<Ret(Args...) const> : true_type {};
    template<class Ret, class... Args> struct is_function<Ret(Args...) volatile> : true_type {};
    template<class Ret, class... Args> struct is_function<Ret(Args...) const volatile> : true_type {};
    template<class Ret, class... Args> struct is_function<Ret(Args......) const> : true_type {};
    template<class Ret, class... Args> struct is_function<Ret(Args......) volatile> : true_type {};
    template<class Ret, class... Args> struct is_function<Ret(Args......) const volatile> : true_type {};
    //specialization for function types that have ref-qualifiers
    template<class Ret, class... Args> struct is_function<Ret(Args...) &> : true_type {};
    template<class Ret, class... Args> struct is_function<Ret(Args...) const &> : true_type {};
    template<class Ret, class... Args> struct is_function<Ret(Args...) volatile &> : true_type {};
    template<class Ret, class... Args> struct is_function<Ret(Args...) const volatile &> : true_type {};
    template<class Ret, class... Args> struct is_function<Ret(Args......) &> : true_type {};
    template<class Ret, class... Args> struct is_function<Ret(Args......) const &> : true_type {};
    template<class Ret, class... Args> struct is_function<Ret(Args......) volatile &> : true_type {};
    template<class Ret, class... Args> struct is_function<Ret(Args......) const volatile &> : true_type {};
    template<class Ret, class... Args> struct is_function<Ret(Args...) &&> : true_type {};
    template<class Ret, class... Args> struct is_function<Ret(Args...) const &&> : true_type {};
    template<class Ret, class... Args> struct is_function<Ret(Args...) volatile &&> : true_type {};
    template<class Ret, class... Args> struct is_function<Ret(Args...) const volatile &&> : true_type {};
    template<class Ret, class... Args> struct is_function<Ret(Args......) &&> : true_type {};
    template<class Ret, class... Args> struct is_function<Ret(Args......) const &&> : true_type {};
    template<class Ret, class... Args> struct is_function<Ret(Args......) volatile &&> : true_type {};
    template<class Ret, class... Args> struct is_function<Ret(Args......) const volatile &&> : true_type {};

    /*
     * essentials
     */

    // enable_if
    template<bool B, typename T = void> struct enable_if { };
    template<typename T> struct enable_if<true, T> { using type = T; };
    template<bool B, typename T = void> using enable_if_t = typename enable_if<B,T>::type;

    // is_void
    template<typename T> struct is_void : is_same<void, remove_cv_t<T>> {};

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

    // rank
    template<class T> struct rank : public integral_constant<size_t, 0> {};
    template<class T> struct rank<T[]> : public integral_constant<size_t, rank<T>::value + 1> {};
    template<class T, size_t N> struct rank<T[N]> : public integral_constant<size_t, rank<T>::value + 1> {};

    /*
     * numeric qualifiers
     */

    namespace detail {
        template<typename T, bool = is_arithmetic<T>::value>
            struct is_signed : integral_constant<bool, T(-1) < T(0)> {};
        template<typename T> struct is_signed<T,false> : false_type {};
    } 
    template<typename T> struct is_signed : detail::is_signed<T>::type {};

    namespace detail {
        template<typename T, bool = is_arithmetic<T>::value>
            struct is_unsigned : integral_constant<bool, T(0) < T(-1)> {};
        template<typename T> struct is_unsigned<T, false> : false_type {};
    } // namespace detail
    template<typename T> struct is_unsigned : detail::is_unsigned<T>::type {};

    // Utility for finding the signed versions of unsigned integral types.
    template<typename SignedType> struct make_unsigned { using type = SignedType; };
    template<> struct make_unsigned<signed char>       { using type = unsigned char; };
    template<> struct make_unsigned<signed short>      { using type = unsigned short; };
    template<> struct make_unsigned<signed int>        { using type = unsigned int; };
    template<> struct make_unsigned<signed long>       { using type = unsigned long; };
    template<> struct make_unsigned<signed long long>  { using type = unsigned long long; };

    // Selects a type based on 'Condition'.
    template<bool Condition, typename True, typename False>
    struct Select { using Result = True; };
    template<typename True, typename False>
    struct Select<false, True, False> { using Result = False; };
} //end of namespace atl

#endif


