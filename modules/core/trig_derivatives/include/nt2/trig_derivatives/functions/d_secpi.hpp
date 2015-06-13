//==============================================================================
//         Copyright 2015 J.T. Lapreste
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_TRIG_DERIVATIVES_FUNCTIONS_D_SECPI_HPP_INCLUDED
#define NT2_TRIG_DERIVATIVES_FUNCTIONS_D_SECPI_HPP_INCLUDED
#include <nt2/include/functor.hpp>


namespace nt2 { namespace tag
  {
   /*!
     @brief d_secpi generic tag

     Represents the d_secpi function in generic contexts.

     @par Models:
        Hierarchy
   **/
    struct d_secpi_ : ext::elementwise_<d_secpi_>
    {
      /// @brief Parent hierarchy
      typedef ext::elementwise_<d_secpi_> parent;
      template<class... Args>
      static BOOST_FORCEINLINE BOOST_AUTO_DECLTYPE dispatch(Args&&... args)
      BOOST_AUTO_DECLTYPE_BODY( dispatching_d_secpi_( ext::adl_helper(), static_cast<Args&&>(args)... ) )
    };
  }
  namespace ext
  {
   template<class Site>
   BOOST_FORCEINLINE generic_dispatcher<tag::d_secpi_, Site> dispatching_d_secpi_(adl_helper, boost::dispatch::meta::unknown_<Site>, ...)
   {
     return generic_dispatcher<tag::d_secpi_, Site>();
   }
   template<class... Args>
   struct impl_d_secpi_;
  }
  /*!
    secant of the angle in pi multiples.

    @par Semantic:

    For every parameter of floating type T0

    @code
    T0 r = d_secpi(a0);
    @endcode

    is similar to:

    @code
    T0 r = rec(cospi(x));
    @endcode

    @see @funcref{secd}, @funcref{sec}, @funcref{secant},
    @param a0

    @return a value of the same type as the parameter
  **/
  NT2_FUNCTION_IMPLEMENTATION(tag::d_secpi_, d_secpi, 1)
}

#endif


