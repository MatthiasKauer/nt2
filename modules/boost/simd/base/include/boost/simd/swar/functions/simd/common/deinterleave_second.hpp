//==============================================================================
//         Copyright 2003 - 2012 LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012 LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_SWAR_FUNCTIONS_SIMD_COMMON_DEINTERLEAVE_SECOND_HPP_INCLUDED
#define BOOST_SIMD_SWAR_FUNCTIONS_SIMD_COMMON_DEINTERLEAVE_SECOND_HPP_INCLUDED

#include <boost/simd/swar/functions/deinterleave_second.hpp>
#include <boost/simd/include/functions/simd/insert.hpp>
#include <boost/simd/include/functions/simd/extract.hpp>
#include <boost/simd/include/functions/simd/bitwise_cast.hpp>
#include <boost/simd/sdk/meta/is_bitwise_logical.hpp>
#include <boost/simd/sdk/meta/as_arithmetic.hpp>
#include <boost/simd/sdk/meta/cardinal_of.hpp>

namespace boost { namespace simd { namespace ext
{
  BOOST_DISPATCH_IMPLEMENT          ( deinterleave_second_, tag::cpu_
                                    , (A0)(A1)(X)
                                    , ((simd_< unspecified_<A0>, X>))
                                      ((simd_< unspecified_<A1>, X>))
                                    )
  {
    typedef A0 result_type;

    result_type operator()(A0 const& a0, A1 const& a1) const
    {
      result_type that;
      const std::size_t middle = meta::cardinal_of<A0>::value/2;
      for(std::size_t i=0,j=middle;i<middle;++i,++j)
      {
        that[i] = a0[(i*2)+1];
        that[j] = a1[(i*2)+1];
      }
      return that;
    }
  };

  BOOST_DISPATCH_IMPLEMENT_IF         ( deinterleave_second_, tag::cpu_
                                      , (A0)(X)
                                      , ( boost::simd::meta::is_bitwise_logical<A0> )
                                      , ((simd_< logical_<A0>, X>))
                                        ((simd_< logical_<A0>, X>))
                                      )
  {
    typedef A0 result_type;

    BOOST_FORCEINLINE BOOST_SIMD_FUNCTOR_CALL_REPEAT(2)
    {
      typedef typename meta::as_arithmetic<A0>::type type;
      return bitwise_cast<result_type>(
        deinterleave_first( bitwise_cast<type>(a0), bitwise_cast<type>(a1) )
      );
    }
  };
} } }

#endif
