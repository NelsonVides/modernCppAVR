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

}

#endif

