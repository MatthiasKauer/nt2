################################################################################
#         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
#         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
#
#          Distributed under the Boost Software License, Version 1.0.
#                 See accompanying file LICENSE.txt or copy at
#                     http://www.boost.org/LICENSE_1_0.txt
################################################################################

SET( SOURCES
  aligned_gather.cpp
  aligned_load.cpp
  aligned_scatter.cpp
  aligned_store.cpp
  extract.cpp
  gather.cpp
  insert.cpp
  load.cpp
  make.cpp
  scatter.cpp
  slide.cpp
  splat.cpp
  store.cpp
  stream.cpp
  )

nt2_module_add_tests(boost.simd.sdk.memory.simd.unit ${SOURCES})

