//==============================================================================
//         Copyright 2015 J.T. Lapreste
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_TRIG_DERIVATIVES_FUNCTIONS_D_SINPI_HPP_INCLUDED
#define NT2_TRIG_DERIVATIVES_FUNCTIONS_D_SINPI_HPP_INCLUDED
#include <nt2/include/functor.hpp>


namespace nt2 { namespace tag
  {
   /*!
     @brief d_sinpi generic tag

     Represents the d_sinpi function in generic contexts.

     @par Models:
        Hierarchy
   **/
    struct d_sinpi_ : ext::elementwise_<d_sinpi_>
    {
      /// @brief Parent hierarchy
      typedef ext::elementwise_<d_sinpi_> parent;
      template<class... Args>
      static BOOST_FORCEINLINE BOOST_AUTO_DECLTYPE dispatch(Args&&... args)
      BOOST_AUTO_DECLTYPE_BODY( dispatching_d_sinpi_( ext::adl_helper(), static_cast<Args&&>(args)... ) )
    };
  }
  namespace ext
  {
   template<class Site>
   BOOST_FORCEINLINE generic_dispatcher<tag::d_sinpi_, Site> dispatching_d_sinpi_(adl_helper, boost::dispatch::meta::unknown_<Site>, ...)
   {
     return generic_dispatcher<tag::d_sinpi_, Site>();
   }
   template<class... Args>
   struct impl_d_sinpi_;
  }
  /*!
    sine of angle in \f$\pi\f$ multiples.

    @par Semantic:

    For every parameter of floating type T0

    @code
    T0 r = d_sinpi(x);
    @endcode

    is similar to:

    @code
    T0 r = sin(Pi<T0>()*x);
    @endcode

    @see @funcref{sine}, @funcref{fast_sin}, @funcref{sincospi}, @funcref{sin}, @funcref{sind}
    @param a0

    @return a value of the same type as the parameter
  **/
  NT2_FUNCTION_IMPLEMENTATION(tag::d_sinpi_, d_sinpi, 1)
}

#endif



