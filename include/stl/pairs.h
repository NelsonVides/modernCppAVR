// Pair implementation -*- C++ -*-

// Copyright (C) 2001-2018 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// Under Section 7 of GPL version 3, you are granted additional
// permissions described in the GCC Runtime Library Exception, version
// 3.1, as published by the Free Software Foundation.

// You should have received a copy of the GNU General Public License and
// a copy of the GCC Runtime Library Exception along with this program;
// see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
// <http://www.gnu.org/licenses/>.

/*
 *
 * Copyright (c) 1994
 * Hewlett-Packard Company
 *
 * Permission to use, copy, modify, distribute and sell this software
 * and its documentation for any purpose is hereby granted without fee,
 * provided that the above copyright notice appear in all copies and
 * that both that copyright notice and this permission notice appear
 * in supporting documentation.  Hewlett-Packard Company makes no
 * representations about the suitability of this software for any
 * purpose.  It is provided "as is" without express or implied warranty.
 *
 *
 * Copyright (c) 1996,1997
 * Silicon Graphics Computer Systems, Inc.
 *
 * Permission to use, copy, modify, distribute and sell this software
 * and its documentation for any purpose is hereby granted without fee,
 * provided that the above copyright notice appear in all copies and
 * that both that copyright notice and this permission notice appear
 * in supporting documentation.  Silicon Graphics makes no
 * representations about the suitability of this software for any
 * purpose.  It is provided "as is" without express or implied warranty.
 */

 /** @file bits/stl_pair.h
  *  This is an internal header file, included by other library headers.
  *  Do not attempt to use it directly. @headername{utility}
  */

#ifndef _STL_PAIR_H
#define _STL_PAIR_H 1

#include "utility.h" // for std::move / std::forward, and std::swap
#include "type_traits" // for std::__decay_and_strip too

namespace stl
{
    /**
      *  @brief Struct holding two objects of arbitrary type.
      *
      *  @tparam _firstType  Type of first object.
      *  @tparam _secondType  Type of second object.
      */
    template<typename _firstType, typename _secondType>
    struct pair
    {
        _firstType first;
        _secondType second;

        pair() : first(), second() {}

        template<typename _U1, typename _U2>
        pair(const pair<_U1, _U2>& __p)
            : first(__p.first), second(__p.second)
        {}

        template<typename _U1, typename _U2>
        pair(pair<_U1, _U2>&& __p)
            : first(stl::move(__p.first)),
            second(stl::move(__p.second))
        {}

        pair(const _firstType& __a, const _secondType& __b)
            : first(__a), second(__b) {}
        pair(_firstType&& __a, _secondType&& __b)
            : first(stl::move(__a)), second(stl::move(__b))
        {}

        pair& operator=(const pair& __p)
        {
            first = __p.first;
            second = __p.second;
            return *this;
        }

        pair&& operator=(pair&& __p)
        {
            first = stl::move(__p.first);
            second = stl::move(__p.second);
            return *this;
        }
    };
    /// Two pairs of the same type are equal iff their members are equal.
    template<typename _firstType, typename _secondType>
    inline bool operator==(const pair<_firstType, _secondType>& __x, const pair<_firstType, _secondType>& __y)
    {
        return __x.first == __y.first && __x.second == __y.second;
    }

    template<typename _firstType, typename _secondType>
    inline bool operator<(const pair<_firstType, _secondType>& __x, const pair<_firstType, _secondType>& __y)
    {
        return __x.first < __y.first
            || (!(__y.first < __x.first) && __x.second < __y.second);
    }

    /// Uses @c operator== to find the result.
    template<typename _firstType, typename _secondType>
    inline bool operator!=(const pair<_firstType, _secondType>& __x, const pair<_firstType, _secondType>& __y)
    {
        return !(__x == __y);
    }

    /// Uses @c operator< to find the result.
    template<typename _firstType, typename _secondType>
    inline bool operator>(const pair<_firstType, _secondType>& __x, const pair<_firstType, _secondType>& __y)
    {
        return __y < __x;
    }

    /// Uses @c operator< to find the result.
    template<typename _firstType, typename _secondType>
    inline bool operator<=(const pair<_firstType, _secondType>& __x, const pair<_firstType, _secondType>& __y)
    {
        return !(__y < __x);
    }

    /// Uses @c operator< to find the result.
    template<typename _firstType, typename _secondType>
    inline bool operator>=(const pair<_firstType, _secondType>& __x, const pair<_firstType, _secondType>& __y)
    {
        return !(__x < __y);
    }

    /**
     *  @brief A convenience wrapper for creating a pair from two objects.
     *  @param  __x  The first object.
     *  @param  __y  The second object.
     *  @return   A newly-constructed pair<> object of the appropriate type.
     *
     *  The standard requires that the objects be passed by reference-to-const,
     *  but LWG issue #181 says they should be passed by const value.  We follow
     *  the LWG by default.
     */
    template<typename _firstType, typename _secondType>
    inline pair<_firstType, _secondType>
        make_pair(const _firstType& __x, const _secondType& __y)
    {
        return pair<_firstType, _secondType>(__x, __y);
    }

    template<typename _firstType, typename _secondType>
    inline pair<_firstType, _secondType>
        make_pair(_firstType&& __x, _secondType&& __y)
    {
        return pair<_firstType, _secondType>(stl::move(__x), stl::move(__y));
    }
} // namespace stl

#endif /* _STL_PAIR_H */
