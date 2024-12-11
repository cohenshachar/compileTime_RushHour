//
// Created by יונדב on 30/03/2024.
//

#ifndef OOP_HW5_BOARDCELLTEST_H
#define OOP_HW5_BOARDCELLTEST_H

#include "BoardCell.h"

void testBoardCell(){
    typedef BoardCell<CellType::X, Direction::UP, 5> XUp5;
    typedef BoardCell<CellType::A, Direction::DOWN, 3> ADown3;
    typedef BoardCell<CellType::B, Direction::LEFT, 4> BLeft4;
    typedef BoardCell<CellType::C, Direction::RIGHT, 2> CRight2;
    typedef BoardCell<CellType::EMPTY, Direction::UP, 0> EmptyUp0;

    /* ---------------------------------------------------------------------- */
    
    //type tests
    static_assert(XUp5::type == CellType::X, "Fail 1");
    static_assert(ADown3::type == CellType::A, "Fail 2");
    static_assert(BLeft4::type == CellType::B, "Fail 3");
    static_assert(CRight2::type == CellType::C, "Fail 4");
    static_assert(EmptyUp0::type == CellType::EMPTY, "Fail 5");

    /* ---------------------------------------------------------------------- */
    
    //direction tests
    static_assert(XUp5::direction == Direction::UP, "Fail 6");
    static_assert(ADown3::direction == Direction::DOWN, "Fail 7");
    static_assert(BLeft4::direction == Direction::LEFT, "Fail 8");
    static_assert(CRight2::direction == Direction::RIGHT, "Fail 9");
    static_assert(EmptyUp0::direction == Direction::UP, "Fail 10");

    /* ---------------------------------------------------------------------- */
    
    //length tests
    static_assert(XUp5::length == 5, "Fail 11");
    static_assert(ADown3::length == 3, "Fail 12");
    static_assert(BLeft4::length == 4, "Fail 13");
    static_assert(CRight2::length == 2, "Fail 14");
    static_assert(EmptyUp0::length == 0, "Fail 15");
}

#endif //OOP_HW5_BOARDCELLTEST_H
