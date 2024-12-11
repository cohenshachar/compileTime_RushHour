//
// Created by יונדב on 30/03/2024.
//

#ifndef OOP_HW5_ENUMSTEST_H
#define OOP_HW5_ENUMSTEST_H

#include "CellType.h"
#include "Direction.h"

void testEnums(){
    //CellType tests
    CellType a = CellType::A,
             b = CellType::B,
             c = CellType::C,
             d = CellType::D,
             e = CellType::E,
             f = CellType::F,
             g = CellType::G,
             h = CellType::H,
             i = CellType::I,
             j = CellType::J,
             k = CellType::K,
             o = CellType::O,
             p = CellType::P,
             q = CellType::Q,
             r = CellType::R,
             empty = CellType::EMPTY;

    /* ---------------------------------------------------------------------- */
    
    //Direction tests
    static_assert(Direction::UP == 0, "Fail 1");
    static_assert(Direction::DOWN == 1, "Fail 2");
    static_assert(Direction::LEFT == 2, "Fail 3");
    static_assert(Direction::RIGHT == 3, "Fail 4");
}
#endif //OOP_HW5_ENUMSTEST_H
