    template<class This, class A0 > struct result<This(A0)> : meta:: result_of< typename meta:: dispatch_call< Tag(A0) , EvalContext >::type(A0) > {}; template<class A0> BOOST_FORCEINLINE typename result<functor(A0)>::type operator()(A0 && a0) const { return meta::dispatch( Tag(), EvalContext() , static_cast<typename meta::as_ref<A0>::type>(a0) ) ( static_cast<typename meta::as_ref<A0>::type>(a0) ); } template<class This, class A0 , class A1 > struct result<This(A0 , A1)> : meta:: result_of< typename meta:: dispatch_call< Tag(A0 , A1) , EvalContext >::type(A0 , A1) > {}; template<class A0 , class A1> BOOST_FORCEINLINE typename result<functor(A0 , A1)>::type operator()(A0 && a0 , A1 && a1) const { return meta::dispatch( Tag(), EvalContext() , static_cast<typename meta::as_ref<A0>::type>(a0) , static_cast<typename meta::as_ref<A1>::type>(a1) ) ( static_cast<typename meta::as_ref<A0>::type>(a0) , static_cast<typename meta::as_ref<A1>::type>(a1) ); } template<class This, class A0 , class A1 , class A2 > struct result<This(A0 , A1 , A2)> : meta:: result_of< typename meta:: dispatch_call< Tag(A0 , A1 , A2) , EvalContext >::type(A0 , A1 , A2) > {}; template<class A0 , class A1 , class A2> BOOST_FORCEINLINE typename result<functor(A0 , A1 , A2)>::type operator()(A0 && a0 , A1 && a1 , A2 && a2) const { return meta::dispatch( Tag(), EvalContext() , static_cast<typename meta::as_ref<A0>::type>(a0) , static_cast<typename meta::as_ref<A1>::type>(a1) , static_cast<typename meta::as_ref<A2>::type>(a2) ) ( static_cast<typename meta::as_ref<A0>::type>(a0) , static_cast<typename meta::as_ref<A1>::type>(a1) , static_cast<typename meta::as_ref<A2>::type>(a2) ); } template<class This, class A0 , class A1 , class A2 , class A3 > struct result<This(A0 , A1 , A2 , A3)> : meta:: result_of< typename meta:: dispatch_call< Tag(A0 , A1 , A2 , A3) , EvalContext >::type(A0 , A1 , A2 , A3) > {}; template<class A0 , class A1 , class A2 , class A3> BOOST_FORCEINLINE typename result<functor(A0 , A1 , A2 , A3)>::type operator()(A0 && a0 , A1 && a1 , A2 && a2 , A3 && a3) const { return meta::dispatch( Tag(), EvalContext() , static_cast<typename meta::as_ref<A0>::type>(a0) , static_cast<typename meta::as_ref<A1>::type>(a1) , static_cast<typename meta::as_ref<A2>::type>(a2) , static_cast<typename meta::as_ref<A3>::type>(a3) ) ( static_cast<typename meta::as_ref<A0>::type>(a0) , static_cast<typename meta::as_ref<A1>::type>(a1) , static_cast<typename meta::as_ref<A2>::type>(a2) , static_cast<typename meta::as_ref<A3>::type>(a3) ); } template<class This, class A0 , class A1 , class A2 , class A3 , class A4 > struct result<This(A0 , A1 , A2 , A3 , A4)> : meta:: result_of< typename meta:: dispatch_call< Tag(A0 , A1 , A2 , A3 , A4) , EvalContext >::type(A0 , A1 , A2 , A3 , A4) > {}; template<class A0 , class A1 , class A2 , class A3 , class A4> BOOST_FORCEINLINE typename result<functor(A0 , A1 , A2 , A3 , A4)>::type operator()(A0 && a0 , A1 && a1 , A2 && a2 , A3 && a3 , A4 && a4) const { return meta::dispatch( Tag(), EvalContext() , static_cast<typename meta::as_ref<A0>::type>(a0) , static_cast<typename meta::as_ref<A1>::type>(a1) , static_cast<typename meta::as_ref<A2>::type>(a2) , static_cast<typename meta::as_ref<A3>::type>(a3) , static_cast<typename meta::as_ref<A4>::type>(a4) ) ( static_cast<typename meta::as_ref<A0>::type>(a0) , static_cast<typename meta::as_ref<A1>::type>(a1) , static_cast<typename meta::as_ref<A2>::type>(a2) , static_cast<typename meta::as_ref<A3>::type>(a3) , static_cast<typename meta::as_ref<A4>::type>(a4) ); }
