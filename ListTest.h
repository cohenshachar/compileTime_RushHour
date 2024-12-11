//
// Created by יונדב on 30/03/2024.
//
#ifndef OOP_HW5_LISTTEST_H
#define OOP_HW5_LISTTEST_H

#include "List.h"
#include "Int.h"
#include <iostream>

using namespace std;

void testList() {
    //List tests
    typedef List<Int<1>, Int<2>, Int<3>> list;
    static_assert(list::head::value == 1, "Fail 1"); // = Int<1>

    typedef typename list::next listTail; // = List<Int<2>, Int<3>>
    static_assert(listTail::head::value == 2, "Fail 2"); // = Int<2>

    typedef typename listTail::next listTailTail; // = List<Int<3>>
    static_assert(listTailTail::head::value == 3, "Fail 3"); // = Int<3>

    static_assert(list::size == 3, "Fail 4");
    static_assert(List<>::size == 0, "Fail 5"); // Empty list
    static_assert(listTailTail::next::size == 0, "Fail 6"); // Empty list
    
    /* ---------------------------------------------------------------------- */
    
    //PrependList tests
    typedef typename PrependList<Int<4>, list>::list newList; // = List< Int<4>, Int<1>, Int<2>, Int<3>>
    static_assert(newList::head::value == 4, "Fail 7");
    static_assert(newList::next::head::value == 1, "Fail 8");
    static_assert(newList::next::next::head::value == 2, "Fail 9");
    static_assert(newList::next::next::next::head::value == 3, "Fail 10");
    static_assert(newList::size == 4, "Fail 11");

    /* ---------------------------------------------------------------------- */
    
    //GetAtIndex tests
    static_assert(GetAtIndex<0, list>::value::value == 1, "Fail 12");
    static_assert(GetAtIndex<1, list>::value::value == 2, "Fail 13");
    static_assert(GetAtIndex<2, list>::value::value == 3, "Fail 14");

    /* ---------------------------------------------------------------------- */
    
    //SetAtIndex tests
    typedef typename SetAtIndex<0, Int<5>, list>::list newList2; // = List<Int<5>, Int<2>, Int<3>>
    static_assert(newList2::head::value == 5, "Fail 15");
    static_assert(newList2::next::head::value == 2, "Fail 16");
    static_assert(newList2::next::next::head::value == 3, "Fail 17");
    static_assert(newList2::size == 3, "Fail 18");

    typedef typename SetAtIndex<1, Int<6>, list>::list newList3; // = List<Int<1>, Int<6>, Int<3>>
    static_assert(newList3::head::value == 1, "Fail 19");
    static_assert(newList3::next::head::value == 6, "Fail 20");
    static_assert(newList3::next::next::head::value == 3, "Fail 21");
    static_assert(newList3::size == 3, "Fail 22");

    typedef typename SetAtIndex<2, Int<7>, list>::list newList4; // = List<Int<1>, Int<2>, Int<7>>
    static_assert(newList4::head::value == 1, "Fail 23");
    static_assert(newList4::next::head::value == 2, "Fail 24");
    static_assert(newList4::next::next::head::value == 7, "Fail 25");
    static_assert(newList4::size == 3, "Fail 26");
}
#endif //OOP_HW5_LISTTEST_H
