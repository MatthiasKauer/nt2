//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#include <boost/dispatch/meta/strip.hpp>

namespace boost { namespace dispatch { namespace meta
{
  BOOST_DISPATCH_FUNCTOR_IMPLEMENTATION( boost::simd::tag::shift_right_, tag::cpu_
                            , (A0)(A1)
                            , (scalar_< real_<A0> >)(scalar_< integer_<A1> >)
                            )
  {
    typedef A0 result_type;
    BOOST_DISPATCH_FUNCTOR_CALL(2)
    {
      typedef typename meta::as_integer<A0, unsigned>::type itype; 
      return bitwise_cast<result_type>(nt2::shift_right(bitwise_cast<itype>(a0),a1));
    }
  };
} } }

namespace boost { namespace dispatch { namespace meta
{
  BOOST_DISPATCH_FUNCTOR_IMPLEMENTATION( boost::simd::tag::shift_right_ , tag::cpu_
                            , (A0)(A1)
                            , (scalar_< integer_<A0> >)
                              (scalar_< integer_<A1> >)
                            )
  {
    typedef typename meta::result_of<meta::arithmetic(A0, A1)>::type result_type;
    BOOST_DISPATCH_FUNCTOR_CALL(2) { return a0 >> a1; }
  };
} } }

#endif
