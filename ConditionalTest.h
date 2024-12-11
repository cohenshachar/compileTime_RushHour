//
// Created by יונדב on 30/03/2024.
//

#ifndef OOP_HW5_CONDITIONALTEST_H
#define OOP_HW5_CONDITIONALTEST_H

#include "Utilities.h"
#include "Int.h"

void testConditional(){
    //ConditionalInteger tests
    static constexpr int valTrue = ConditionalInteger<(0 != 1), 0, 1>::value; // = 0
    static_assert(valTrue == 0, "Fail 1");
    static constexpr int valFalse = ConditionalInteger<(0 == 1), 0, 1>::value; // = 1
    static_assert(valFalse == 1, "Fail 2");

    /* ---------------------------------------------------------------------- */
    
    //Conditional tests
    typedef Conditional<(0 != 1), Int<0>, Int<1>>::value valTrue2; // = Int<0>
    static_assert(valTrue2::value == 0, "Fail 3");
    typedef Conditional<(0 == 1), Int<0>, Int<1>>::value valFalse2; // = Int<1>
    static_assert(valFalse2::value == 1, "Fail 4");
}

#endif //OOP_HW5_CONDITIONALTEST_H