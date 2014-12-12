//==============================================================================
//         Copyright 2013 - 2014   Jean-Thierry Lapreste
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2013   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_LINALG_FUNCTIONS_BLAS_NRM2_HPP_INCLUDED
#define NT2_LINALG_FUNCTIONS_BLAS_NRM2_HPP_INCLUDED

/*!
  @file
  @brief Defines and implements blas_nrm2 function
**/

#include <nt2/include/functor.hpp>

namespace nt2
{
  namespace tag
  {
    /// @brief Defines blas_nrm2 function tag
    struct blas_nrm2_ : ext::abstract_<blas_nrm2_>
    {
      /// INTERNAL ONLY
      typedef ext::abstract_<blas_nrm2_> parent;
      template<class... Args>
      static BOOST_FORCEINLINE BOOST_AUTO_DECLTYPE dispatch(Args&&... args)
      BOOST_AUTO_DECLTYPE_BODY( dispatching_blas_nrm2_( ext::adl_helper(), static_cast<Args&&>(args)... ) )
    };
  }
  namespace ext
  {
    template<class Site>
    BOOST_FORCEINLINE generic_dispatcher<tag::blas_nrm2_, Site> dispatching_blas_nrm2_(adl_helper, boost::dispatch::meta::unknown_<Site>, ...)
    {
      return generic_dispatcher<tag::blas_nrm2_, Site>();
    }
    template<class... Args>
    struct impl_blas_nrm2_;
  }

  /*!
    @brief nrm2 square of euclidian norm

    @code
    nrm2 ( n, x, incx)
    @endcode

    @param n number of elements to use
    @param x input vector
    @param incx step through x
    return norm2(x(_(1, incx, (n-1)*incx+1))
  **/

  NT2_FUNCTION_IMPLEMENTATION_TPL (tag::blas_nrm2_, blas_nrm2
                                  , (const A0&)(const A1&)(const A2&)
                                  , 3
                                  );


}

#endif
