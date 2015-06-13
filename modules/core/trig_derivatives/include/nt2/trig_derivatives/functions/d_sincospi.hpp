//==============================================================================
//         Copyright 2015 J.T. Lapreste
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_TRIG_DERIVATIVES_FUNCTIONS_D_SINCOSPI_HPP_INCLUDED
#define NT2_TRIG_DERIVATIVES_FUNCTIONS_D_SINCOSPI_HPP_INCLUDED
#include <nt2/include/functor.hpp>

namespace nt2 { namespace tag
  {
    struct d_sincospi_ : ext::elementwise_<d_sincospi_>
    {
      /// @brief Parent hierarchy
      typedef ext::elementwise_<d_sincospi_> parent;
      template<class... Args>
      static BOOST_FORCEINLINE BOOST_AUTO_DECLTYPE dispatch(Args&&... args)
      BOOST_AUTO_DECLTYPE_BODY( dispatching_d_sincospi_( ext::adl_helper(), static_cast<Args&&>(args)... ) )
    };
  }
  namespace ext
  {
    template<class Site>
    BOOST_FORCEINLINE generic_dispatcher<tag::d_sincospi_, Site> dispatching_d_sincospi_(adl_helper, boost::dispatch::meta::unknown_<Site>, ...)
    {
      return generic_dispatcher<tag::d_sincospi_, Site>();
    }
    template<class... Args>
    struct impl_d_sincospi_;
  }
  /*!
    Computes simultaneously the sine and cosine
    of the input in \f$\pi\f$ multiples.

    @par Semantic:

    For every parameters of floating type T0:

    @code
    T0 s, c;
    tie(s, c) = d_sincospi(x);
    @endcode

    is similar to:

    @code
    T0 s =  sinpi(x);
    T0 c =  cospi(x);
    @endcode

    @see @funcref{fast_d_sincospi}, @funcref{sincos}, @funcref{sincosd}
    @param a0 input

    @return A Fusion Sequence containing the sinpi and cospi of @c a0
  **/

  NT2_FUNCTION_IMPLEMENTATION(tag::d_sincospi_, d_sincospi, 1)

  /*!
    Computes simultaneously the sine and cosine
    of the input in \f$\pi\f$ multiples.

    @par Semantic:

    For every parameters of floating type T0:

    @code
    T0 s, c;
    s = d_sincospi(x, c);
    @endcode

    is similar to:

    @code
    T0 s =  sinpi(x);
    T0 c =  cospi(x);
    @endcode

    @param a0 angle in radian
    @param a1 L-Value that will receive the sin of @c a0

    @return the sinpi of a0
  **/


   NT2_FUNCTION_IMPLEMENTATION_TPL(tag::d_sincospi_, d_sincospi,(A0 const&)(A1&),2)

  /*!
    Computes simultaneously the sine and cosine
    of the input in \f$\pi\f$ multiples.

    @par Semantic:

    For every parameters of floating type T0:

    @code
    T0 s, c;
    d_sincospi(x, s, c);
    @endcode

    is similar to:

    @code
    T0 s =  sinpi(x);
    T0 c =  cospi(x);
    @endcode

    @param a0 angle in radian
    @param a1 L-Value that will receive the sinpi of @c a0
    @param a2 L-Value that will receive the cospi of @c a0
  **/
   NT2_FUNCTION_IMPLEMENTATION_TPL(tag::d_sincospi_, d_sincospi,(A0 const&)(A1&)(A2&),3)

    }

#endif


