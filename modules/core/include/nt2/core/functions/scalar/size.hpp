//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_CORE_FUNCTIONS_IMPL_SIZE_SCALAR_HPP_INCLUDED
#define NT2_CORE_FUNCTIONS_IMPL_SIZE_SCALAR_HPP_INCLUDED

#include <nt2/core/functions/size.hpp>
#include <nt2/core/container/extent/extent.hpp>

namespace nt2 { namespace ext
{
  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::size_, tag::cpu_
                            , (A0), (scalar_< fundamental_<A0> >)
                            )
  {
    typedef container::extent< of_size_<1,1> > result_type;

    result_type BOOST_DISPATCH_FORCE_INLINE operator()(A0 const&) const
    {
      result_type that;
      return that;
    }
  };
} }

#endif
