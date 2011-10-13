//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_ARITHMETIC_FUNCTIONS_SCALAR_IDIVROUND_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_ARITHMETIC_FUNCTIONS_SCALAR_IDIVROUND_HPP_INCLUDED
#include <boost/simd/include/constants/digits.hpp>
#include <boost/simd/include/functions/round2even.hpp>
#include <boost/simd/include/functions/rdivide.hpp>
#include <boost/simd/include/functions/iround.hpp>
#include <boost/simd/include/functions/tofloat.hpp>


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is arithmetic_
/////////////////////////////////////////////////////////////////////////////
namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::idivround_, tag::cpu_
			      , (A0)
			      , (scalar_< arithmetic_<A0> >)(scalar_< arithmetic_<A0> >)
			      )
  {
    typedef A0 result_type;
    BOOST_SIMD_FUNCTOR_CALL_REPEAT(2)
      {
	return (!a1) ? a1 :iround(tofloat(a0)/tofloat(a1));
      }
  };
  
  /////////////////////////////////////////////////////////////////////////////
  // Implementation when type A0 is floating_
  /////////////////////////////////////////////////////////////////////////////
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION(boost::simd::tag::idivround_, tag::cpu_,
			     (A0),
			     (scalar_< floating_<A0> > )(scalar_< floating_<A0> > )
			     )
  {
    typedef typename dispatch::meta::as_integer < A0 >::type result_type;
    BOOST_SIMD_FUNCTOR_CALL_REPEAT(2)
    {
      return iround(a0/a1);
    }
  };
} } }

#endif
