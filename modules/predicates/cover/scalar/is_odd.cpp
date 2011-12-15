//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_UNIT_MODULE "nt2 predicates toolbox - is_odd/scalar Mode"

//////////////////////////////////////////////////////////////////////////////
// cover test behavior of predicates components in scalar mode
//////////////////////////////////////////////////////////////////////////////
/// created  by jt the 21/02/2011
/// 
#include <nt2/toolbox/predicates/include/functions/is_odd.hpp>
#include <nt2/include/functions/ulpdist.hpp>
#include <nt2/include/functions/max.hpp>
#include <nt2/sdk/simd/logical.hpp>

#include <nt2/include/functions/abs.hpp>

#include <boost/type_traits/is_same.hpp>
#include <nt2/sdk/functor/meta/call.hpp>
#include <nt2/sdk/meta/as_integer.hpp>
#include <nt2/sdk/meta/as_floating.hpp>
#include <nt2/sdk/meta/as_signed.hpp>
#include <nt2/sdk/meta/upgrade.hpp>
#include <nt2/sdk/meta/downgrade.hpp>
#include <nt2/sdk/meta/scalar_of.hpp>
#include <nt2/sdk/meta/floating.hpp>
#include <nt2/sdk/meta/arithmetic.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/memory/buffer.hpp>
#include <nt2/toolbox/constant/constant.hpp>


NT2_TEST_CASE_TPL ( is_odd_real__1_0,  NT2_REAL_TYPES)
{
  
  using nt2::is_odd;
  using nt2::tag::is_odd_;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef typename nt2::meta::call<is_odd_(T)>::type r_t;
  typedef typename nt2::meta::scalar_of<r_t>::type ssr_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef nt2::logical<T> wished_r_t;


  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 
  double ulpd;
  ulpd=0.0;

  // random verifications
  static const nt2::uint32_t NR = NT2_NB_RANDOM_TEST;
  {
    NT2_CREATE_BUF(tab_a0,T, NR, T(-10000), T(10000));
    double ulp0, ulpd ; ulpd=ulp0=0.0;
    T a0;
    for(nt2::uint32_t j =0; j < NR; ++j )
      {
        std::cout << "for param "
                  << "  a0 = "<< u_t(a0 = tab_a0[j])
                  << std::endl;
        NT2_TEST_EQUAL( nt2::is_odd(a0),r_t(int(nt2::abs(a0)/nt2::Two<T>())*2+nt2::One<T>()==nt2::abs(a0)));
     }
     
   }
} // end of test for floating_

NT2_TEST_CASE_TPL ( is_odd_signed_int__1_0,  NT2_INTEGRAL_SIGNED_TYPES)
{
  
  using nt2::is_odd;
  using nt2::tag::is_odd_;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef typename nt2::meta::call<is_odd_(T)>::type r_t;
  typedef typename nt2::meta::scalar_of<r_t>::type ssr_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef nt2::logical<T> wished_r_t;


  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 
  double ulpd;
  ulpd=0.0;

  // random verifications
  static const nt2::uint32_t NR = NT2_NB_RANDOM_TEST;
  {
    NT2_CREATE_BUF(tab_a0,T, NR, T(-10000), T(10000));
    double ulp0, ulpd ; ulpd=ulp0=0.0;
    T a0;
    for(nt2::uint32_t j =0; j < NR; ++j )
      {
        std::cout << "for param "
                  << "  a0 = "<< u_t(a0 = tab_a0[j])
                  << std::endl;
        NT2_TEST_EQUAL( nt2::is_odd(a0),r_t(int(nt2::abs(a0)/nt2::Two<T>())*2+nt2::One<T>()==nt2::abs(a0)));
     }
     
   }
} // end of test for signed_int_

NT2_TEST_CASE_TPL ( is_odd_unsigned_int__1_0,  NT2_UNSIGNED_TYPES)
{
  
  using nt2::is_odd;
  using nt2::tag::is_odd_;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef typename nt2::meta::call<is_odd_(T)>::type r_t;
  typedef typename nt2::meta::scalar_of<r_t>::type ssr_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef nt2::logical<T> wished_r_t;


  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 
  double ulpd;
  ulpd=0.0;

  // random verifications
  static const nt2::uint32_t NR = NT2_NB_RANDOM_TEST;
  {
    NT2_CREATE_BUF(tab_a0,T, NR, T(-10000), T(10000));
    double ulp0, ulpd ; ulpd=ulp0=0.0;
    T a0;
    for(nt2::uint32_t j =0; j < NR; ++j )
      {
        std::cout << "for param "
                  << "  a0 = "<< u_t(a0 = tab_a0[j])
                  << std::endl;
        NT2_TEST_EQUAL( nt2::is_odd(a0),r_t(int(nt2::abs(a0)/2.0)*2+nt2::One<T>()==nt2::abs(a0)));
     }
     
   }
} // end of test for unsigned_int_
