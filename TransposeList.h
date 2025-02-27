#ifndef HW5_TRANSPOSELIST_H
#define HW5_TRANSPOSELIST_H

#include "List.h"

template<typename TList>
struct AsVerticalList{
    typedef typename PrependList<List<typename TList::head>, typename AsVerticalList<typename TList::next>::list>::list list;
};

template<typename T>
struct AsVerticalList<List<T>>{
typedef List<List<T>> list;
};

template<typename, typename>
struct PrependVerticalList;

template<typename InsertHead, typename... InsertTail, typename MainListHead, typename... MainListTail>
struct PrependVerticalList<List<InsertHead, InsertTail...>, List<MainListHead, MainListTail...>>{
private:
typedef typename PrependList<typename InsertHead::head, MainListHead>::list firstRow;
typedef typename PrependVerticalList<List<InsertTail...>, List<MainListTail...>>::list rest;
public:
typedef typename PrependList<firstRow, rest>::list list;
};

template<typename InsertHead, typename MainListHead>
struct PrependVerticalList<List<InsertHead>, List<MainListHead>>{
typedef List<typename PrependList<typename InsertHead::head, MainListHead>::list> list;
};

template<typename>
struct Transpose;

template<typename RowsHead, typename... RowsTail>
struct Transpose<List<RowsHead, RowsTail...>>{
private:
typedef typename AsVerticalList<RowsHead>::list verticalHead;
public:
typedef typename PrependVerticalList<verticalHead, typename Transpose<List<RowsTail...>>::matrix>::list matrix;
};

template<typename RowsHead>
struct Transpose<List<RowsHead>>{
typedef typename AsVerticalList<RowsHead>::list matrix;
};


#endif //HW5_TRANSPOSELIST_H
