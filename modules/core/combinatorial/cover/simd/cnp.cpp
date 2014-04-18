//==============================================================================
//         Copyright 2003 - 2014   LASMEA UMR 6602 CNRS/UBP
//         Copyright 2009 - 2014   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
// cover for functor cnp in simd mode
#include <nt2/combinatorial/include/functions/cnp.hpp>
#include <boost/simd/sdk/simd/io.hpp>
#include <boost/simd/sdk/simd/native.hpp>
#include <cmath>
#include <iostream>
#include <nt2/include/functions/round.hpp>
#include <nt2/sdk/unit/args.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/unit/tests/cover.hpp>
#include <vector>

NT2_TEST_CASE_TPL(cnp_0,  NT2_SIMD_REAL_TYPES)
{
  using boost::simd::native;
  typedef BOOST_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef native<T,ext_t>                  vT;

  using nt2::unit::args;
  const std::size_t NR = args("samples", NT2_NB_RANDOM_TEST);
  const double ulpd = args("ulpd",  1);

  const T min = args("min", T(0));
  const T max = args("max", T(10));
  std::cout << "Argument samples a0 chosen in range: [" << min << ",  " << max << "]" << std::endl;
  std::cout << "Argument samples a1 chosen in range: [ a0,  a0+" << max << "]" << std::endl;
  NT2_CREATE_BUF(a0,T, NR, min, max);
  NT2_CREATE_BUF(a1,T, NR, min, max);

  std::vector<T> ref(NR);
  for(std::size_t i=0; i!=NR; ++i)
  {
    a0[i] = nt2::round(a0[i]);
    a1[i] = nt2::round(a1[i]);
    a0[i] += a1[i];
    ref[i] = nt2::cnp(a0[i], a1[i]);
  }

  NT2_COVER_ULP_EQUAL(nt2::tag::cnp_, ((vT, a0))((vT, a1)), ref, ulpd);

}
