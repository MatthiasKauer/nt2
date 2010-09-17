/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_SDK_META_ARITHMETIC_HPP_INCLUDED
#define NT2_SDK_META_ARITHMETIC_HPP_INCLUDED

#include <nt2/sdk/meta/strip.hpp>
#include <boost/typeof/typeof.hpp>
#include <nt2/extension/parameters.hpp>
#include <nt2/sdk/functor/category.hpp>
#include <nt2/sdk/functor/meta/dominant.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/repeat_from_to.hpp>

namespace nt2	{ namespace details
{
	template<class Category,class Dummy=void> struct arithmetic;
	
	template<class Dummy,class X>
	struct arithmetic<tag::scalar_(X),Dummy>
	{
		template<class Sig> struct result;

		#define M0(z,n,t)	static typename meta::strip<BOOST_PP_CAT(A,n)>::type& \
											BOOST_PP_CAT(a,n);
											/**/
											
		#define M1(z,n,t)  + BOOST_PP_CAT(a,n)
		#define M2(z,n,t)																													\
		template<class This,BOOST_PP_ENUM_PARAMS(n,class A)>											\
		struct  result<This(BOOST_PP_ENUM_PARAMS(n,A))>														\
		{																																					\
			BOOST_PP_REPEAT(n,M0,~)																									\
			BOOST_TYPEOF_NESTED_TYPEDEF_TPL	(	nested																\
																			,	a0 BOOST_PP_REPEAT_FROM_TO(1,n,M1,~))	\
			 typedef typename nested::type   type;																	\
		 };																																				\
		 /**/

		BOOST_PP_REPEAT_FROM_TO(2,NT2_MAX_ARITY,M2,~)
		#undef M2
		#undef M1
		#undef M0
	};
} }

namespace nt2	{ namespace meta
{
	struct arithmetic
	{
		template<class Sig> struct result;

    template<class This,class A0>
		struct result<This(A0)> : strip<A0> {};

		#define M3(z,n,t)																																\
		template<class This,BOOST_PP_ENUM_PARAMS(n,class A)>														\
		struct  result<This(BOOST_PP_ENUM_PARAMS(n,A))>																	\
		{																																								\
			typedef	typename meta::dominant<BOOST_PP_ENUM_PARAMS(n,A)>::type::tag 	dom;	\
			typedef	typename std::tr1 																										\
			::result_of<details::arithmetic<dom>(BOOST_PP_ENUM_PARAMS(n,A))>::type	type;	\
		};																																							\
		/**/

		BOOST_PP_REPEAT_FROM_TO(2,NT2_MAX_ARITY,M2,~)
		#undef M3
	};
} }

#endif
