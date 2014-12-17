//==============================================================================
//         Copyright 2013 - 2014   Jean-Thierry Laprest�
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2013   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_LINALG_FUNCTIONS_BLAS_BLAS2_GBMV_HPP_INCLUDED
#define NT2_LINALG_FUNCTIONS_BLAS_BLAS2_GBMV_HPP_INCLUDED

#include <nt2/linalg/functions/blas_gbmv.hpp>
#include <nt2/linalg/details/blas/blas2.hpp>
#include <nt2/include/functions/height.hpp>
#include <nt2/include/functions/width.hpp>
#include <nt2/linalg/details/utility/f77_wrapper.hpp>
#include <boost/dispatch/attributes.hpp>
#include <nt2/sdk/memory/container.hpp>

namespace nt2 { namespace ext
{
// /---------------------------------------------Real-single------------------------------------------------//

  BOOST_DISPATCH_IMPLEMENT  ( blas_gbmv_, tag::cpu_
                            , (T)(M)(KL)(ALPHA)(A)(SA)(X)(SX)(INCX)(BETA)(Y)(SY)(INCY)
                            , (scalar_<int8_<T>>)// trans
                              (scalar_<integer_<M>>) //m
                              (scalar_<integer_<KL>>) //kl
                              (scalar_<single_<ALPHA>>)//alpha
                              ((container_<nt2::tag::table_,  single_<A>, SA >)) //a
                              ((container_<nt2::tag::table_,  single_<X>, SX >)) //x
                              (scalar_<integer_<INCX>>)// incx
                              (scalar_<single_<BETA>>)// beta
                              ((container_<nt2::tag::table_,  single_<Y>, SY >)) //y
                              (scalar_<integer_<INCY>>)// incy
                            )
  {
    typedef void result_type;

    BOOST_FORCEINLINE void operator()( const T& trans
                                     , const M& mm
                                     , const KL& kkl
                                     , const ALPHA& alpha
                                     , const A& a
                                     , const X& x, const INCX & incx
                                     , const BETA beta
                                     , Y& y, const INCY & incy
                                     ) const
    {
      nt2_la_int n = width(a);
      nt2_la_int m = mm;
      nt2_la_int llpkup1 = height(a);
      nt2_la_int kl = kkl;
      nt2_la_int ku = llpkup1-kl-1;
      nt2_la_int lda = a.leading_size();
      nt2_la_int ix= incx;
      nt2_la_int iy= incy;
      NT2_F77NAME(sgbmv) (&trans, &m, &n, &kl, &ku, &alpha, a.raw(), &lda, x.raw(), &ix, &beta, y.raw(), &iy);
    }
  };

// /---------------------------------------------Real-double------------------------------------------------//
  BOOST_DISPATCH_IMPLEMENT  ( blas_gbmv_, tag::cpu_
                            , (T)(M)(KL)(ALPHA)(A)(SA)(X)(SX)(INCX)(BETA)(Y)(SY)(INCY)
                            , (scalar_<int8_<T>>)// n
                              (scalar_<integer_<M>>) //m
                              (scalar_<integer_<KL>>) //kl
                              (scalar_<double_<ALPHA>>)//alpha
                              ((container_<nt2::tag::table_,  double_<A>, SA >)) //a
                              ((container_<nt2::tag::table_,  double_<X>, SX >)) //y
                              (scalar_<integer_<INCX>>)// incx
                              (scalar_<double_<BETA>>)// beta
                              ((container_<nt2::tag::table_,  double_<Y>, SY >)) //dparam
                              (scalar_<integer_<INCY>>)// incy
                            )
  {
    typedef void result_type;

    BOOST_FORCEINLINE void operator()( const T& trans
                                     , const M& mm
                                     , const KL& kkl
                                     , const ALPHA& alpha
                                     , const A& a
                                     , const X& x, const INCX & incx
                                     , const BETA& beta
                                     , Y& y, const INCY & incy
                                     ) const
    {
      nt2_la_int n = width(a);
      nt2_la_int m = mm;
      nt2_la_int llpkup1 = height(a);
      nt2_la_int kl = kkl;
      nt2_la_int ku = llpkup1-kl-1;
      nt2_la_int lda = a.leading_size();
      nt2_la_int ix= incx;
      nt2_la_int iy= incy;
      NT2_F77NAME(dgbmv) (&trans, &m, &n, &kl, &ku, &alpha, a.raw(), &lda, x.raw(), &ix, &beta, y.raw(), &iy);
    }
  };



// /---------------------------------------------Complex-single------------------------------------------------//

  BOOST_DISPATCH_IMPLEMENT  ( blas_gbmv_, tag::cpu_
                            , (T)(M)(KL)(ALPHA)(A)(SA)(X)(SX)(INCX)(BETA)(Y)(SY)(INCY)
                            , (scalar_<int8_<T>>)// n
                              (scalar_<integer_<M>>) //m
                              (scalar_<integer_<KL>>) //kl
                              (scalar_<complex_<single_<ALPHA>>>)//alpha
                              ((container_<nt2::tag::table_,  complex_<single_<A>>, SA >)) //a
                              ((container_<nt2::tag::table_,  complex_<single_<X>>, SX >)) //y
                              (scalar_<integer_<INCX>>)// incx
                              (scalar_<complex_<single_<BETA>>>)// beta
                              ((container_<nt2::tag::table_,  complex_<single_<Y>>, SY >)) //dparam
                              (scalar_<integer_<INCY>>)// incy
                            )
  {
    typedef void result_type;

    BOOST_FORCEINLINE void operator()( const T& trans
                                     , const M& mm
                                     , const KL& kkl
                                     , const ALPHA& alpha
                                     , const A& a
                                     , const X& x, const INCX & incx
                                     , const BETA& beta
                                     , Y& y, const INCY & incy
                                     ) const
    {
      nt2_la_int n = width(a);
      nt2_la_int m = mm;
      nt2_la_int llpkup1 = height(a);
      nt2_la_int kl = kkl;
      nt2_la_int ku = llpkup1-kl-1;
      nt2_la_int lda = a.leading_size();
      nt2_la_int ix= incx;
      nt2_la_int iy= incy;
      NT2_F77NAME(cgbmv) (&trans, &m, &n, &kl, &ku, &alpha, a.raw(), &lda, x.raw(), &ix, &beta, y.raw(), &iy);
    }
  };

// /---------------------------------------------Complex-double------------------------------------------------//
  BOOST_DISPATCH_IMPLEMENT  ( blas_gbmv_, tag::cpu_
                            , (T)(M)(KL)(ALPHA)(A)(SA)(X)(SX)(INCX)(BETA)(Y)(SY)(INCY)
                            , (scalar_<int8_<T>>)// n
                              (scalar_<integer_<M>>) //m
                              (scalar_<integer_<KL>>) //kl
                              (scalar_<complex_<double_<ALPHA>>>)//alpha
                              ((container_<nt2::tag::table_,  complex_<double_<A>>, SA >)) //a
                              ((container_<nt2::tag::table_,  complex_<double_<X>>, SX >)) //y
                              (scalar_<integer_<INCX>>)// incx
                              (scalar_<complex_<double_<BETA>>>)// beta
                              ((container_<nt2::tag::table_,  complex_<double_<Y>>, SY >)) //dparam
                              (scalar_<integer_<INCY>>)// incy
                            )
  {
    typedef void result_type;

    BOOST_FORCEINLINE void operator()( const T& trans
                                     , const M& mm
                                     , const KL& kkl
                                     , const ALPHA& alpha
                                     , const A& a
                                     , const X& x, const INCX & incx
                                     , const BETA& beta
                                     , Y& y, const INCY & incy
                                     ) const
    {
      nt2_la_int n = width(a);
      nt2_la_int m = mm;
      nt2_la_int llpkup1 = height(a);
      nt2_la_int kl = kkl;
      nt2_la_int ku = llpkup1-kl-1;
      nt2_la_int lda = a.leading_size();
      nt2_la_int ix= incx;
      nt2_la_int iy= incy;
      NT2_F77NAME(zgbmv) (&trans, &m, &n, &kl, &ku, &alpha, a.raw(), &lda, x.raw(), &ix, &beta, y.raw(), &iy);
    }
  };


} }

#endif