//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2013   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//         Copyright 2012 - 2013   MetaScale SAS
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_CORE_FUNCTIONS_SHARED_MEMORY_TRANSFORM_HPP_INCLUDED
#define NT2_CORE_FUNCTIONS_SHARED_MEMORY_TRANSFORM_HPP_INCLUDED

#include <nt2/core/functions/transform.hpp>
#include <nt2/sdk/shared_memory/shared_memory.hpp>
#include <nt2/sdk/shared_memory/worker.hpp>
#include <nt2/sdk/shared_memory/spawner.hpp>
#include <nt2/sdk/shared_memory/spawner/parfor.hpp>
#include <nt2/sdk/config/cache.hpp>
#include <cstddef>

namespace nt2 { namespace ext
{
  //============================================================================
  // Partial Shared Memory elementwise operation
  // Generates a SPMD loop nest and forward to internal site for evaluation
  // using the partial transform syntax.
  //============================================================================
  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::transform_, (nt2::tag::shared_memory_<BackEnd,Site>)
                            , (A0)(A1)(BackEnd)(Site)(A2)
                            , ((ast_<A0, nt2::container::domain>))
                              ((ast_<A1, nt2::container::domain>))
                              (unspecified_<A2>)
                            )
  {

    typedef void                                                             result_type;

    BOOST_FORCEINLINE result_type operator()(A0& a0, A1& a1, A2 a2) const
    {

      std::size_t top_cache_line_size = config::top_cache_size()/sizeof(typename A0::value_type);
      std::size_t it = a2.first;
      std::size_t sz = a2.second;
      if(!top_cache_line_size) top_cache_line_size = 1u;

       nt2::worker<tag::transform_, BackEnd,A0,A1> w(a0,a1);
       nt2::spawner<tag::parfor_, BackEnd>         s;

       s(w,it,sz,top_cache_line_size);
    }
  };

} }
#endif
