//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2013   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#define NT2_UNIT_MODULE "nt2 linalg toolbox - tied qr function"

#include <nt2/include/functions/qr.hpp>
#include <nt2/include/functions/eye.hpp>
#include <nt2/include/functions/tie.hpp>
#include <nt2/include/functions/eye.hpp>
#include <nt2/include/functions/ones.hpp>
#include <nt2/include/functions/numel.hpp>
#include <nt2/include/functions/triu.hpp>
#include <nt2/include/functions/mtimes.hpp>
#include <nt2/include/functions/rand.hpp>

#include <nt2/table.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/unit/tests/ulp.hpp>
#include <nt2/sdk/unit/tests/relation.hpp>
#include <nt2/sdk/unit/tests/exceptions.hpp>


NT2_TEST_CASE_TPL ( direct_qr, NT2_REAL_TYPES)
{
  using nt2::_;
  using nt2::meta::as_;

  int i[3] = {4, 4, 5};
  int j[3] = {4, 5, 4};
  for(int k = 0; k < 3; ++k)
  {
    nt2::table<T> x, q, r, p, ux, u, tau;
    nt2::table<T> b = nt2::ones(i[k], j[k], as_<T>());
    b(2, 3) = T(10);
    nt2::table<nt2_la_int> ip;

    /// Interface tests
    /// x = qr(b, upper_)
      NT2_DISPLAY(b);
      r = nt2::qr(b, nt2::upper_);
      NT2_DISPLAY(b);
      NT2_DISPLAY(r);

      // x = qr(b)
      NT2_DISPLAY(b);
      x = nt2::qr(b);
      NT2_DISPLAY(b);
      NT2_DISPLAY(x);

      // x = qr(b, raw_)
      NT2_DISPLAY(b);
      x = nt2::qr(b);
      NT2_DISPLAY(b);
      NT2_DISPLAY(x);

      // x = qr(b, 0)
      NT2_DISPLAY(b);
      x = nt2::qr(b, 0);
      NT2_DISPLAY(b);
      NT2_DISPLAY(x);

      // x = qr(b, nt2::econ_)
      NT2_DISPLAY(b);
      x = nt2::qr(b, nt2::econ_);
      NT2_DISPLAY(b);
      NT2_DISPLAY(x);

      // tie(x, tau)= nt2::qr(b, nt2::raw_);
      tie(x, tau)= nt2::qr(b, nt2::raw_);
      NT2_DISPLAY(b);
      NT2_DISPLAY(triu(x));
      NT2_DISPLAY(x);
      NT2_DISPLAY(tau);

      // tie(x, tau, ip)= nt2::qr(b, nt2::raw_);
      tie(x, tau, ip)= nt2::qr(b, nt2::raw_);
      NT2_DISPLAY(x);
      NT2_DISPLAY(tau);
      NT2_DISPLAY(ip);

      // tie(q, r)= nt2::qr(b, nt2::matrix_);
      tie(q, r)= nt2::qr(b, nt2::matrix_);
      NT2_DISPLAY(b);
      NT2_DISPLAY(q);
      NT2_DISPLAY(r);
      NT2_TEST_ULP_EQUAL( b, nt2::mtimes(q, r), T(200));

      // tie(q, r, ip)= nt2::qr(b, nt2::vector_);
      tie(q, r, ip)= nt2::qr(b, nt2::vector_);
      NT2_DISPLAY(b);
      NT2_DISPLAY(q);
      NT2_DISPLAY(r);
      NT2_DISPLAY(ip);
      NT2_TEST_ULP_EQUAL( b(nt2::_, ip), nt2::mtimes(q, r), T(200));

      //  tie(q, r, p)= nt2::qr(b, nt2::matrix_);
      tie(q, r, p)= nt2::qr(b, nt2::matrix_);
      NT2_DISPLAY(b);
      NT2_DISPLAY(q);
      NT2_DISPLAY(r);
      NT2_DISPLAY(p);
      NT2_TEST_ULP_EQUAL( mtimes(b, p), nt2::mtimes(q, r), T(200));

      // tie(q, r)= nt2::qr(b, nt2::econ_);
      tie(q, r)= nt2::qr(b, nt2::econ_);
      NT2_DISPLAY(b);
      NT2_DISPLAY(q);
      NT2_DISPLAY(r);
      NT2_TEST_ULP_EQUAL( b, nt2::mtimes(q, r), T(200));

  }
}
NT2_TEST_CASE_TPL ( direct_qrc, NT2_REAL_TYPES)
{
  using nt2::_;
  using nt2::meta::as_;
  typedef std::complex<T> cT;
  int i[3] = {4, 4, 5};
  int j[3] = {4, 5, 4};
  for(int k = 0; k < 3; ++k)
  {
    nt2::table<cT> x, q, r, p, ux, u, tau;
    nt2::table<cT> b = nt2::ones(i[k], j[k], as_<cT>());
    b(2, 3) = cT(10, 10);
    nt2::table<nt2_la_int> ip;

    /// Interface tests
    /// x = qr(b, upper_)
       NT2_DISPLAY(b);
       r = nt2::qr(b, nt2::upper_);
       NT2_DISPLAY(b);
       NT2_DISPLAY(r);

      // x = qr(b)
      NT2_DISPLAY(b);
      x = nt2::qr(b);
      NT2_DISPLAY(b);
      NT2_DISPLAY(x);

      // x = qr(b, raw_)
      NT2_DISPLAY(b);
      x = nt2::qr(b);
      NT2_DISPLAY(b);
      NT2_DISPLAY(x);

      // x = qr(b, 0)
      NT2_DISPLAY(b);
      x = nt2::qr(b, 0);
      NT2_DISPLAY(b);
      NT2_DISPLAY(x);

      // x = qr(b, nt2::econ_)
      NT2_DISPLAY(b);
      x = nt2::qr(b, nt2::econ_);
      NT2_DISPLAY(b);
      NT2_DISPLAY(x);

      // tie(x, tau)= nt2::qr(b, nt2::raw_);
      tie(x, tau)= nt2::qr(b, nt2::raw_);
      NT2_DISPLAY(b);
      NT2_DISPLAY(triu(x));
      NT2_DISPLAY(x);
      NT2_DISPLAY(tau);

      // tie(x, tau, ip)= nt2::qr(b, nt2::raw_);
      tie(x, tau, ip)= nt2::qr(b, nt2::raw_);
      NT2_DISPLAY(x);
      NT2_DISPLAY(tau);
      NT2_DISPLAY(ip);

      // tie(q, r)= nt2::qr(b, nt2::matrix_);
      tie(q, r)= nt2::qr(b, nt2::matrix_);
      NT2_DISPLAY(b);
      NT2_DISPLAY(q);
      NT2_DISPLAY(r);
      NT2_TEST_ULP_EQUAL( b, nt2::mtimes(q, r), T(200));

      // tie(q, r, ip)= nt2::qr(b, nt2::vector_);
      tie(q, r, ip)= nt2::qr(b, nt2::vector_);
      NT2_DISPLAY(b);
      NT2_DISPLAY(q);
      NT2_DISPLAY(r);
      NT2_DISPLAY(ip);
      NT2_TEST_ULP_EQUAL( b(nt2::_, ip), nt2::mtimes(q, r), T(200));

      //  tie(q, r, p)= nt2::qr(b, nt2::matrix_);
      tie(q, r, p)= nt2::qr(b, nt2::matrix_);
      NT2_DISPLAY(b);
      NT2_DISPLAY(q);
      NT2_DISPLAY(r);
      NT2_DISPLAY(p);
      NT2_TEST_ULP_EQUAL( mtimes(b, p), nt2::mtimes(q, r), T(200));

      // tie(q, r)= nt2::qr(b, nt2::econ_);
      tie(q, r)= nt2::qr(b, nt2::econ_);
      NT2_DISPLAY(b);
      NT2_DISPLAY(q);
      NT2_DISPLAY(r);
      NT2_TEST_ULP_EQUAL( b, nt2::mtimes(q, r), T(200));

  }
}
