//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_CONSTANT_CONSTANTS_SIMD_COMMON_TRUE_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_CONSTANT_CONSTANTS_SIMD_COMMON_TRUE_HPP_INCLUDED

#include <boost/simd/toolbox/constant/constants/true.hpp>
#include <boost/simd/include/constants/allbits.hpp>

namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION ( simd::tag::True, tag::cpu_, (A0)(X)
                                    , ((target_< simd_< fundamental_<A0>,X> >))
                                    )
  {
    typedef typename A0::type base_type;
    typedef typename meta::as_logical<base_type>::type result_type;
    BOOST_DISPATCH_FORCE_INLINE result_type operator()(A0 const&) const
    {
      base_type base;
      base = Allbits<base_type>();
      return native_cast<result_type>(base);
    }
  };
} } }

#endif
