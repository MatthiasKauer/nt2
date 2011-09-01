//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_PREDICATES_FUNCTIONS_SIMD_SSE_AVX_IS_EQUAL_WITH_EQUAL_NANS_TO_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_PREDICATES_FUNCTIONS_SIMD_SSE_AVX_IS_EQUAL_WITH_EQUAL_NANS_TO_HPP_INCLUDED
#ifdef BOOST_SIMD_HAS_AVX_SUPPORT

#include <boost/simd/toolbox/predicates/functions/is_equal_with_equal_nans.hpp>

namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::is_equal_with_equal_nans_, boost::simd::tag::avx_
                            , (A0)
                            , ((simd_<double_<A0>,boost::simd::tag::avx_>))
                              ((simd_<double_<A0>,boost::simd::tag::avx_>))
                            )
  {
    typedef A0 result_type;
    BOOST_SIMD_FUNCTOR_CALL_REPEAT(2)
    {
      A0 that = { _mm256_cmp_pd(a0,a1, _CMP_EQ_UQ) };
      return that;
    }
  };

  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::is_equal_with_equal_nans_, boost::simd::tag::avx_
                            , (A0)
                            , ((simd_<float_<A0>,boost::simd::tag::avx_>))
                              ((simd_<float_<A0>,boost::simd::tag::avx_>))
                            )
  {
    typedef A0 result_type;
    BOOST_SIMD_FUNCTOR_CALL_REPEAT(2)
    {
      A0 that = { _mm256_cmp_ps(a0,a1, _CMP_EQ_UQ) };
      return that;
    }
  };
  
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::is_equal_with_equal_nans_, boost::simd::tag::avx_
                            , (A0)
                            , ((simd_<double_<A0>,boost::simd::tag::sse_>))
                              ((simd_<double_<A0>,boost::simd::tag::sse_>))
                            )
  {
    typedef A0 result_type;
    BOOST_SIMD_FUNCTOR_CALL_REPEAT(2)
    {
      A0 that = { _mm_cmp_pd(a0,a1, _CMP_EQ_UQ) };
      return that;
    }
  };

  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::is_equal_with_equal_nans_, boost::simd::tag::avx_
                            , (A0)
                            , ((simd_<float_<A0>,boost::simd::tag::sse_>))
                              ((simd_<float_<A0>,boost::simd::tag::sse_>))
                            )
  {
    typedef A0 result_type;
    BOOST_SIMD_FUNCTOR_CALL_REPEAT(2)
    {
      A0 that = { _mm_cmp_ps(a0,a1, _CMP_EQ_UQ) };
      return that;
    }
  };

} } }

#endif
#endif
