//==============================================================================
//         Copyright 2003 - 2013   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2013   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#include <nt2/include/functions/is_not_real.hpp>

#include <boost/dispatch/functor/meta/call.hpp>
#include <nt2/sdk/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests/relation.hpp>
#include <nt2/sdk/unit/tests/type_expr.hpp>
#include <complex>
#include <nt2/sdk/complex/complex.hpp>
#include <boost/simd/sdk/simd/logical.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <boost/simd/sdk/config.hpp>

#include <nt2/include/constants/one.hpp>
#include <nt2/include/constants/zero.hpp>

NT2_TEST_CASE_TPL ( is_not_real_not_real,  NT2_REAL_TYPES)
{
  using nt2::is_not_real;
  using nt2::tag::is_not_real_;
  typedef typename std::complex<T> cT;
  typedef typename boost::dispatch::meta::call<is_not_real_(cT)>::type r_t;

  // return type conformity test
  NT2_TEST_TYPE_IS(r_t, nt2::logical<T>);

  // specific values tests
  NT2_TEST_EQUAL(is_not_real(nt2::One<T>()), r_t(false));
  NT2_TEST_EQUAL(is_not_real(nt2::Zero<T>()), r_t(false));
  NT2_TEST_EQUAL(is_not_real(cT(0, 0)), r_t(false));
  NT2_TEST_EQUAL(is_not_real(cT(1, 0)), r_t(false));
  NT2_TEST_EQUAL(is_not_real(cT(0, 2)), r_t(true));
  NT2_TEST_EQUAL(is_not_real(cT(0, 1)), r_t(true));
}
