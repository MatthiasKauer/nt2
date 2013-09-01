//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#include <boost/simd/arithmetic/include/functions/round2zero.hpp>
#include <boost/simd/sdk/simd/native.hpp>
#include <boost/dispatch/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests/relation.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <boost/simd/include/constants/zero.hpp>
#include <boost/simd/include/constants/one.hpp>
#include <boost/simd/include/constants/mone.hpp>
#include <boost/simd/include/constants/mtwo.hpp>
#include <boost/simd/include/constants/inf.hpp>
#include <boost/simd/include/constants/minf.hpp>
#include <boost/simd/include/constants/nan.hpp>
#include <boost/simd/include/constants/valmax.hpp>
#include <boost/simd/include/constants/valmin.hpp>
#include <boost/simd/include/constants/maxflint.hpp>
#include <boost/simd/include/constants/half.hpp>

#include <boost/simd/sdk/config.hpp>
#include <boost/simd/sdk/simd/io.hpp>

NT2_TEST_CASE_TPL ( round2zero_real,  BOOST_SIMD_SIMD_REAL_TYPES)
{
  using boost::simd::round2zero;
  using boost::simd::tag::round2zero_;
  using boost::simd::native;
  typedef BOOST_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef native<T,ext_t>                  vT;
  typedef typename boost::dispatch::meta::call<round2zero_(vT)>::type r_t;

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  NT2_TEST_EQUAL(round2zero(boost::simd::Inf<vT>()), boost::simd::Inf<r_t>());
  NT2_TEST_EQUAL(round2zero(boost::simd::Minf<vT>()), boost::simd::Minf<r_t>());
  NT2_TEST_EQUAL(round2zero(boost::simd::Nan<vT>()), boost::simd::Nan<r_t>());
#endif
  NT2_TEST_EQUAL(round2zero(boost::simd::splat<vT>(1.4)), boost::simd::One<r_t>());
  NT2_TEST_EQUAL(round2zero(boost::simd::splat<vT>(1.5)), boost::simd::One<r_t>());
  NT2_TEST_EQUAL(round2zero(boost::simd::splat<vT>(1.6)), boost::simd::Two<r_t>());
  NT2_TEST_EQUAL(round2zero(boost::simd::splat<vT>(2.5)), boost::simd::Two<r_t>());
  NT2_TEST_EQUAL(round2zero(boost::simd::splat<vT>(-1.4)), boost::simd::Mone<r_t>());
  NT2_TEST_EQUAL(round2zero(boost::simd::splat<vT>(-1.5)), boost::simd::Mone<r_t>());
  NT2_TEST_EQUAL(round2zero(boost::simd::splat<vT>(-1.6)), boost::simd::Mtwo<r_t>());
  NT2_TEST_EQUAL(round2zero(boost::simd::splat<vT>(-2.5)), boost::simd::Mtwo<r_t>());
  NT2_TEST_EQUAL(round2zero(boost::simd::Half<vT>()), boost::simd::Zero<r_t>());
  NT2_TEST_EQUAL(round2zero(boost::simd::Mhalf<vT>()), boost::simd::Zero<r_t>());
  NT2_TEST_EQUAL(round2zero(boost::simd::Mone<vT>()), boost::simd::Mone<r_t>());
  NT2_TEST_EQUAL(round2zero(boost::simd::One<vT>()), boost::simd::One<r_t>());
  NT2_TEST_EQUAL(round2zero(boost::simd::Zero<vT>()), boost::simd::Zero<r_t>());
  NT2_TEST_EQUAL(round2zero(boost::simd::Maxflint<vT>()),boost::simd::Maxflint<vT>());
} // end of test for floating_

NT2_TEST_CASE_TPL ( round2zero_unsigned_int,  BOOST_SIMD_SIMD_UNSIGNED_TYPES)
{
  using boost::simd::round2zero;
  using boost::simd::tag::round2zero_;
  using boost::simd::native;
  typedef BOOST_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef native<T,ext_t>                  vT;
  typedef typename boost::dispatch::meta::call<round2zero_(vT)>::type r_t;

  // specific values tests
  NT2_TEST_EQUAL(round2zero(boost::simd::One<vT>()), boost::simd::One<r_t>());
  NT2_TEST_EQUAL(round2zero(boost::simd::Valmax<vT>()), boost::simd::Valmax<r_t>());
  NT2_TEST_EQUAL(round2zero(boost::simd::Valmin<vT>()), boost::simd::Valmin<r_t>());
  NT2_TEST_EQUAL(round2zero(boost::simd::Zero<vT>()), boost::simd::Zero<r_t>());
} // end of test for unsigned_int_

NT2_TEST_CASE_TPL ( round2zero_signed_int,  BOOST_SIMD_SIMD_INTEGRAL_SIGNED_TYPES)
{
  using boost::simd::round2zero;
  using boost::simd::tag::round2zero_;
  using boost::simd::native;
  typedef BOOST_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef native<T,ext_t>                  vT;
  typedef typename boost::dispatch::meta::call<round2zero_(vT)>::type r_t;

  // specific values tests
  NT2_TEST_EQUAL(round2zero(boost::simd::Mone<vT>()), boost::simd::Mone<r_t>());
  NT2_TEST_EQUAL(round2zero(boost::simd::One<vT>()), boost::simd::One<r_t>());
  NT2_TEST_EQUAL(round2zero(boost::simd::Valmax<vT>()), boost::simd::Valmax<r_t>());
  NT2_TEST_EQUAL(round2zero(boost::simd::Valmin<vT>()), boost::simd::Valmin<r_t>());
  NT2_TEST_EQUAL(round2zero(boost::simd::Zero<vT>()), boost::simd::Zero<r_t>());
} // end of test for signed_int_
