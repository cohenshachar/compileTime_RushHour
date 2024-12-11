#ifndef HW5_BOARDCELL_H
#define HW5_BOARDCELL_H

#include "Direction.h"
#include "CellType.h"

template<enum CellType C, enum Direction D, int L>
struct BoardCell{
    constexpr static CellType type = C;
    constexpr static Direction direction = D;
    constexpr static int length = L;
};


#endif //HW5_BOARDCELL_H
