#ifndef HW5_GAMEBOARD_H
#define HW5_GAMEBOARD_H

#include "List.h"
#include "BoardCell.h"

template<typename Board>
struct GameBoard{
    typedef Board board;
    constexpr static int length = board::size;
    constexpr static int width = board::head::size;
};


#endif //HW5_GAMEBOARD_H
