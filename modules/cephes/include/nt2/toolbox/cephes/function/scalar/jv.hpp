//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_CEPHES_FUNCTION_SCALAR_JV_HPP_INCLUDED
#define NT2_TOOLBOX_CEPHES_FUNCTION_SCALAR_JV_HPP_INCLUDED

  extern "C"{
    extern float cephes_jvf ( float,float );
    extern double cephes_jv ( double,double );
    extern long double cephes_jvl ( long double,long double );
  }


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is arithmetic_
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION( cephes::tag::jv_, tag::cpu_
                            , (A0)(A1)
                            , (scalar_< arithmetic_<A0> >)(scalar_< arithmetic_<A1> >)
                            )
  {

    typedef typename meta::result_of<meta::floating(A0)>::type result_type;

    NT2_FUNCTOR_CALL(2)
    {
      return nt2::cephes::jv(result_type(a0), result_type(a1));
    }
  };
} }


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is double
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION( cephes::tag::jv_, tag::cpu_
                            , (A0)(A1)
                            , (scalar_< double_<A0> >)(scalar_< double_<A1> >)
                            )
  {

    typedef typename meta::result_of<meta::floating(A0)>::type result_type;

    NT2_FUNCTOR_CALL(2)
    { return cephes_jv(a0, a1); }
  };
} }


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is float
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION( cephes::tag::jv_, tag::cpu_
                            , (A0)(A1)
                            , (scalar_< float_<A0> >)(scalar_< float_<A1> >)
                            )
  {

    typedef typename meta::result_of<meta::floating(A0)>::type result_type;

    NT2_FUNCTOR_CALL(2)
    { return cephes_jvf(a0, a1); }
  };
} }


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is long double
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION( cephes::tag::jv_, tag::cpu_
                            , (A0)(A1)
                            , (long_double_<A0>)(long_double_<A1>)
                            )
  {

    typedef typename meta::result_of<meta::floating(A0)>::type result_type;

    NT2_FUNCTOR_CALL(2)
    { return cephes_jvl(a0, a1); }
  };
} }


#endif
