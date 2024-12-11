#ifndef HW5_LIST_H
#define HW5_LIST_H

template<typename... Tail>
struct List{};

//as we learned in the tutorial
template<typename V, typename... Tail>
struct List<V,Tail...>{
    typedef V head;
    typedef List<Tail...> next;
    constexpr static int size = 1 + sizeof...(Tail);
};

//an empty list size is 0
template<>
struct List<>{
    constexpr static int size = 0;
};

template<typename V, typename Tail>
struct PrependList{};

template<typename V, typename... AList>
struct PrependList<V, List<AList...>>{
    typedef List<V, AList...> list;
};

//the case of an empty list
template<typename V>
struct PrependList<V, List<>>{
    typedef List<V> list;
};

template<int N, typename V>
struct GetAtIndex {};

template<int N, typename V, typename... Tail>
struct GetAtIndex<N,List<V,Tail...>>{
    typedef typename GetAtIndex<N-1, List<Tail...>>::value value;
};

template<typename V, typename... Tail>
struct GetAtIndex<0,List<V,Tail...>> {
    typedef V value;
};

template<int N, typename InsertVal, typename Head>
struct SetAtIndex {};

template<int N, typename InsertVal, typename Head, typename... Tail>
struct SetAtIndex<N, InsertVal, List<Head, Tail...>> {
    typedef typename PrependList<Head, typename SetAtIndex<N-1, InsertVal, List<Tail...>>::list>::list list;
};

template<typename InsertVal, typename Head, typename... Tail>
struct SetAtIndex<0, InsertVal, List<Head, Tail...>>{
    typedef typename PrependList<InsertVal, List<Tail...>>::list list;
};

#endif //HW5_LIST_H
