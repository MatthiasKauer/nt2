//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
/*!
 * \file
**/
#ifndef NT2_TOOLBOX_COMBINATORIAL_FUNCTIONS_ANP_HPP_INCLUDED
#define NT2_TOOLBOX_COMBINATORIAL_FUNCTIONS_ANP_HPP_INCLUDED
#include <nt2/include/simd.hpp>
#include <nt2/include/functor.hpp>

/*!
 * \ingroup combinatorial
 * \defgroup combinatorial_anp anp
 *
 * \par Description
 * number of arrangement of p elements among n
 * If a0 (n) and a1 (p) are not of integer type
 * they are rounded to nearest integer before computation.
 * \par Formula
 * \f[A_n^p = \frac{n!}{(n-p)!}\f]
 *
 * \par Header file
 * 
 * \code
 * #include <nt2/include/functions/anp.hpp>
 * \endcode
 * 
 * 
 * \synopsis
 *
 * \code
 * namespace nt2
 * {
 *   template <class A0>
 *     meta::call<tag::anp_(A0,A0)>::type
 *     anp(const A0 & a0,const A0 & a1);
 * }
 * \endcode
 *
 * \param a0 the first parameter of anp
 * \param a1 the second parameter of anp
 * 
 * \return a value of the common type of the parameters
 *  
 * \par Notes
 * In SIMD mode, this function acts elementwise on the inputs vectors elements
 * \par
 *  
**/

namespace nt2 { namespace tag
  {         
    /*!
     * \brief Define the tag anp_ of functor anp 
     *        in namespace nt2::tag for toolbox combinatorial
    **/
    struct anp_ {};
  }
  NT2_FUNCTION_IMPLEMENTATION(tag::anp_, anp, 2)
}

#endif

// modified by jt the 25/12/2010
