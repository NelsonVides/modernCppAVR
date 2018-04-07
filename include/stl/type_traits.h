#ifndef _TYPE_TRAITS_H_
#define _TYPE_TRAITS_H_

namespace atl {

/*
 * std::integral_constant; IMPORTANT
 */


template<typename T, T v>
struct integral_constant {
    static constexpr T value = v;
    using value_type = T;
    using type = integral_constant;
    constexpr operator value_type() const noexcept { return value; }
    constexpr value_type operator()() const noexcept { return value; }
    };

template<bool B>
using bool_constant = integral_constant<bool, B>;

using true_type  = integral_constant<bool, true>;
using false_type = integral_constant<bool, false>;


/*
 * Type relationships
 */

template<typename T, typename U>
    struct is_same : false_type {};
template<typename T>
    struct is_same<T, T> : true_type {};


/*
 * SFINAE-friendly traits
 * primary type categories
 */

 
template<typename T> struct remove_const          { using type = T; };
template<typename T> struct remove_const<const T> { using type = T; };
 
template<typename T> struct remove_volatile             { using type = T; };
template<typename T> struct remove_volatile<volatile T> { using type = T;  };

template<typename T>
struct remove_cv { using type = typename remove_volatile<typename remove_const<T>::type>::type; };

template<typename T> using remove_cv_t       = typename remove_cv<T>::type;
template<typename T> using remove_const_t    = typename remove_const<T>::type;
template<typename T> using remove_volatile_t = typename remove_volatile<T>::type;

/*
 * remove_reference
 */
template<typename T> struct remove_reference      { using type = T; };
template<typename T> struct remove_reference<T&>  { using type = T; };
template<typename T> struct remove_reference<T&&> { using type = T; };
template<typename T> using remove_reference_t = typename remove_reference<T>::type;

template<typename T> struct is_void       { static const bool value = false; };
template<>           struct is_void<void> { static const bool value = true; };


} //end of namespace atl
#endif


