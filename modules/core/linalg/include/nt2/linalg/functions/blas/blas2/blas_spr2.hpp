//==============================================================================
//         Copyright 2013 - 2014   Jean-Thierry Lapreste
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2013   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_LINALG_FUNCTIONS_BLAS_BLAS2_SPR2_HPP_INCLUDED
#define NT2_LINALG_FUNCTIONS_BLAS_BLAS2_SPR2_HPP_INCLUDED

#include <nt2/linalg/functions/blas_spr2.hpp>
#include <nt2/linalg/details/blas/blas2.hpp>
#include <nt2/include/functions/numel.hpp>
#include <nt2/include/functions/iround.hpp>
#include <nt2/include/functions/sqrt.hpp>
#include <nt2/include/functions/oneplus.hpp>
#include <nt2/include/constants/eight.hpp>
#include <nt2/linalg/details/utility/f77_wrapper.hpp>
#include <boost/dispatch/attributes.hpp>
#include <nt2/core/container/table/table.hpp>

namespace nt2 { namespace ext
{

//---------------------------------------------Real-single------------------------------------------------//

  BOOST_DISPATCH_IMPLEMENT  ( blas_spr2_, tag::cpu_
                            , (UPLO)(ALPHA)(X)(SX)(INCX)(Y)(SY)(INCY)(A)(SA)
                            , (scalar_<int8_<UPLO>>)// uplo
                              (scalar_<single_<ALPHA>>)// alpha
                              ((container_<nt2::tag::table_,  single_<X>, SX >)) //x
                              (scalar_<integer_<INCX>>)// incx
                              ((container_<nt2::tag::table_,  single_<Y>, SY >)) //y
                              (scalar_<integer_<INCY>>)// incy
                              ((container_<nt2::tag::table_,  single_<A>, SA >)) //a
                            )
  {
    typedef void result_type;

    BOOST_FORCEINLINE void operator()( const UPLO& uplo
                                     , const ALPHA& alpha
                                     , const X& x, const INCX & incx
                                     , const Y& y, const INCY & incy
                                     , A& a) const
    {
      nt2_la_int n = iround(sqrt(oneplus(Eight<size_t>()*numel(a)))) >> 1;
      nt2_la_int ix = incx;
      nt2_la_int iy = incy;
      NT2_F77NAME(sspr2) (&uplo, &n, &alpha, x.data(), &ix, y.data(), &iy, a.data());
    }
  };

//---------------------------------------------Real-double------------------------------------------------//

  BOOST_DISPATCH_IMPLEMENT  ( blas_spr2_, tag::cpu_
                            , (UPLO)(ALPHA)(X)(SX)(INCX)(Y)(SY)(INCY)(A)(SA)
                            , (scalar_<int8_<UPLO>>)// uplo
                              (scalar_<double_<ALPHA>>)// alpha
                              ((container_<nt2::tag::table_,  double_<X>, SX >)) //x
                              (scalar_<integer_<INCX>>)// incx
                              ((container_<nt2::tag::table_,  double_<Y>, SY >)) //y
                              (scalar_<integer_<INCY>>)// incy
                              ((container_<nt2::tag::table_,  double_<A>, SA >)) //a
                            )
  {
    typedef void result_type;

    BOOST_FORCEINLINE void operator()( const UPLO& uplo
                                     , const ALPHA& alpha
                                     , const X& x, const INCX & incx
                                     , const Y& y, const INCY & incy
                                     , A& a) const
    {
      nt2_la_int n = iround(sqrt(oneplus(Eight<size_t>()*numel(a)))) >> 1;
      nt2_la_int ix = incx;
      nt2_la_int iy = incy;
      NT2_F77NAME(dspr2) (&uplo, &n, &alpha, x.data(), &ix, y.data(), &iy, a.data());
    }
  };
} }

#endif
