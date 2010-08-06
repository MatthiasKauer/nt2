/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_SDK_SIMD_IO_HPP_INCLUDED
#define NT2_SDK_SIMD_IO_HPP_INCLUDED

#include <nt2/sdk/simd/details/check.hpp>
#include <nt2/sdk/simd/native.hpp>
#include <boost/type_traits/is_integral.hpp>
#include <boost/type_traits/integral_promotion.hpp>

namespace nt2 { namespace simd
{
  //////////////////////////////////////////////////////////////////////////////
  // Stream insertion for swar types
  //////////////////////////////////////////////////////////////////////////////
  template<class S,class E> static inline
  std::ostream& operator<<( std::ostream& os, native<S,E> const & v )
  {
    // We want to display (u)int8_t as number not value
    typedef typename
            boost::mpl::if_c< boost::is_integral<S>::value
                            , typename  boost::integral_promotion<S>::type
                            , typename native<S,E>::value_type
                            >::type display_type;

    os << "{";
    for(std::size_t i=0;i<v.size()-1;++i)
      os << static_cast<display_type>(v[i]) << ",";
    os << static_cast<display_type>(v[v.size()-1]) << "}";
    return os;
  }
} }

#endif
