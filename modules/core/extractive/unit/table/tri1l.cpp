//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#include <nt2/table.hpp>
#include <nt2/include/functions/tri1l.hpp>

#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/unit/tests/relation.hpp>
#include <nt2/sdk/unit/tests/exceptions.hpp>
#include <nt2/sdk/unit/tests/type_expr.hpp>

NT2_TEST_CASE_TPL( tri1l_types, NT2_TYPES )
{
  using boost::mpl::_;
  using nt2::meta::value_type_;

  nt2::table<T> x( nt2::of_size(4,4) );
  NT2_TEST_EXPR_TYPE( nt2::tri1l(x)  , (value_type_<_>), (T));
  NT2_TEST_EXPR_TYPE( nt2::tri1l(x,1), (value_type_<_>), (T));
}

NT2_TEST_CASE_TPL( triu_scalar, NT2_TYPES )
{
  T x = nt2::tri1l(T(42));
  NT2_TEST_EQUAL( x, T(1) );

  x = nt2::tri1l(T(42),1);
  NT2_TEST_EQUAL( x, T(42) );

  x = nt2::tri1l(T(42),0);
  NT2_TEST_EQUAL( x, T(1) );

  x = nt2::tri1l(T(42),-1);
  NT2_TEST_EQUAL( x, T(0) );
}

NT2_TEST_CASE( triu_assert )
{
  nt2::table<double> x( nt2::of_size(2,5,3) );
  NT2_TEST_ASSERT(nt2::tri1l(x));
  NT2_TEST_ASSERT(nt2::tri1l(x,1));
}

NT2_TEST_CASE_TPL( tri1l, NT2_TYPES )
{
  nt2::table<T> x
              , y( nt2::of_size(5,3) )
              , ref( nt2::of_size(5,3) );

  for(int j=1;j<=3;j++)
    for(int i=1;i<=5;i++)
      y(i,j) = i + 10*j;

  for(int j=1;j<=3;j++)
    for(int i=1;i<=5;i++)
      ref(i,j) = (i==j) ? T(1) : ((i>=j) ? y(i,j) : 0);

  x = nt2::tri1l(y);

  NT2_TEST_EQUAL( x, ref );

  x = nt2::tri1l(y,0);

  NT2_TEST_EQUAL( x, ref );

  for(int j=1;j<=3;j++)
    for(int i=1;i<=5;i++)
      ref(i,j) = (i+1==j) ? T(1) : ((i+1>= j) ? y(i,j) : 0);

  x = nt2::tri1l(y,1);

  NT2_TEST_EQUAL( x, ref );

  x = nt2::tri1l(y,-1);

  for(int j=1;j<=3;j++)
    for(int i=1;i<=5;i++)
      ref(i,j) = (i-1==j) ? T(1) : ((i-1>= j) ? y(i,j) : 0);

  NT2_TEST_EQUAL( x, ref );

  x = nt2::tri1l(y,5);
  NT2_TEST_EQUAL( x, y );
}
