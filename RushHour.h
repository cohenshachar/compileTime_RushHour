//
// Created by shach on 4/12/2024.
//

#ifndef OOP_HW5_RUSHHOUR_H
#define OOP_HW5_RUSHHOUR_H

#include "MoveVehicle.h"

template<typename Row, int Col, bool stop>
struct CheckWinAux{
    constexpr static CellType tileType = GetAtIndex<Col, Row>::value::type;
    constexpr static bool result = ConditionalInteger<(tileType == EMPTY || tileType == X) && CheckWinAux<Row, Col+1, Col+1 == Row::size>::result, true, false>::value;
};

template<typename Row, int Col>
struct CheckWinAux<Row,Col,true>{
    constexpr static bool result = true;
};

template<typename gameBoard>
struct CheckWin{};

template<typename B>
struct CheckWin<GameBoard<B>>{
    typedef GameBoard<B> gameBoard;
    typedef typename GameBoard<B>::board gameList;
    typedef typename GetAtIndex<FindCar<X,gameBoard>::X_row_idx, gameList>::value X_row;
    constexpr static int X_col = FindCar<X,gameBoard>::X_col_idx;
    constexpr static bool result = CheckWinAux<X_row, X_col, X_col == gameBoard::width-1>::result;
};

template<typename gameBoard, typename... Tail>
struct CheckSolution{};

template<typename B, typename currMove, typename... nextMoves>
struct CheckSolution<GameBoard<B>, List<currMove, nextMoves...>>{
    typedef GameBoard<B> prevBoard;
    constexpr static int car_row = FindCar<currMove::type,prevBoard>::X_row_idx;
    constexpr static int car_col = FindCar<currMove::type,prevBoard>::X_col_idx;
    typedef typename MoveVehicle<prevBoard, car_row, car_col, currMove::direction, currMove::amount>::board currentBoard;
    typedef typename CheckSolution<currentBoard,List<nextMoves...>>::finishedBoard finishedBoard;
    constexpr static bool result =  CheckWin<finishedBoard>::result;
};

template<typename B>
struct CheckSolution<GameBoard<B>, List<>>{
    typedef GameBoard<B> finishedBoard;
    constexpr static bool result = CheckWin<finishedBoard>::result;
};

typedef int (*OP)(int o1, int o2);
template <int T,OP op>
struct Padovan {
    constexpr int getNum() {
        return op(Padovan<T-2,op>::getNum(), Padovan<T-3,op>::getNum());
    }
};
#endif //OOP_HW5_RUSHHOUR_H
