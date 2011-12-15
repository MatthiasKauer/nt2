//==============================================================================
//         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//============================================================================== 
#ifndef BOOST_SIMD_TOOLBOX_OPERATOR_FUNCTIONS_SIMD_COMMON_MINUS_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_OPERATOR_FUNCTIONS_SIMD_COMMON_MINUS_HPP_INCLUDED
#include <boost/simd/toolbox/operator/functions/minus.hpp>
#include <boost/simd/include/functions/splat.hpp>
//TODO is that necessary ?
//////////////////////////////////////////////////////////////////////////////
// mixed scalar/simd minus
//////////////////////////////////////////////////////////////////////////////
namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::minus_, tag::cpu_,
                                    (A0)(A1)(X),
                                    ((simd_<arithmetic_ <A0>,X>))((scalar_<arithmetic_<A1> >))
                                   )
  {
    typedef A0 result_type;
    BOOST_SIMD_FUNCTOR_CALL(2)
    {
      return boost::simd::minus(a0, boost::simd::splat<A0>(a1));
    }
  };

  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::minus_, tag::cpu_,
                                     (A0)(A1)(X),
                                     ((scalar_<arithmetic_<A0> >))((simd_<arithmetic_<A1>,X>))
                                   )
  {
    typedef A1 result_type;
    BOOST_SIMD_FUNCTOR_CALL(2)
    {
      return boost::simd::minus(boost::simd::splat<A0>(a0), a1);
    }
  };
} } }

#endif
