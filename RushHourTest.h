//
// Created by יונדב on 31/03/2024.
//

#ifndef OOP_HW5_RUSHHOURTEST_H
#define OOP_HW5_RUSHHOURTEST_H

#include "RushHour.h"

void testRushHour(){
    typedef GameBoard< List<
            List < BoardCell< EMPTY , RIGHT , 1>, BoardCell< EMPTY , RIGHT , 0>, BoardCell< EMPTY , RIGHT , 0>, BoardCell< EMPTY , RIGHT , 0>, BoardCell< O , DOWN , 3>, BoardCell< EMPTY , RIGHT , 0> >,
            List < BoardCell< EMPTY , RIGHT , 2>, BoardCell< EMPTY , RIGHT , 0>, BoardCell< A , RIGHT , 2>, BoardCell< A , LEFT , 2>, BoardCell< O , DOWN , 3>, BoardCell< EMPTY , RIGHT , 0> >,
            List < BoardCell< EMPTY , RIGHT , 3>, BoardCell< EMPTY , RIGHT , 0>, BoardCell< X , RIGHT , 2>, BoardCell< X , LEFT , 2>, BoardCell< O , UP , 3>, BoardCell< EMPTY , RIGHT , 0> >,
            List < BoardCell< EMPTY , RIGHT , 0>, BoardCell< EMPTY , RIGHT , 0>, BoardCell< EMPTY , RIGHT , 0>, BoardCell< EMPTY , RIGHT , 0>, BoardCell< EMPTY , RIGHT , 0>, BoardCell< EMPTY , RIGHT , 0> >,
            List < BoardCell< EMPTY , RIGHT , 0>, BoardCell< EMPTY , RIGHT , 0>, BoardCell< B , DOWN , 2>, BoardCell< P , RIGHT , 3>, BoardCell< P , RIGHT , 3>, BoardCell< P , LEFT , 3> >,
            List < BoardCell< EMPTY , RIGHT , 0>, BoardCell< EMPTY , RIGHT , 0>, BoardCell< B , UP , 2>, BoardCell< EMPTY , RIGHT , 0>, BoardCell< C , RIGHT , 2>, BoardCell< C , LEFT , 2> >
    > > gameBoard;

    typedef List<
            Move < B, UP, 1 > , Move < C, LEFT, 4 > , Move < A, LEFT, 2 > , Move < X, LEFT, 2 > , Move < B, UP, 3 > , Move < P, LEFT, 3 > , Move < O, DOWN, 1 >
    > badMoves;

    typedef GameBoard< List<
            List < BoardCell< EMPTY , RIGHT , 0 >, BoardCell< EMPTY , RIGHT , 0 >, BoardCell< EMPTY , RIGHT , 0>, BoardCell< X , RIGHT , 1 >, BoardCell< EMPTY , RIGHT , 0>, BoardCell< EMPTY , RIGHT , 0>, BoardCell< EMPTY , RIGHT , 0>>
    >> solvedBoard;

    //test incorrect solve
    static_assert(CheckSolution<gameBoard, badMoves>::result == false, "Fail 1"); // Game should not be solved
    static_assert(CheckSolution<gameBoard, List<Move < B, UP, 1 >>>::result == false, "Fail 2");
    static_assert(CheckSolution<gameBoard, List<> >::result == false, "Fail 3");
    
    //test simple solve
    static_assert(CheckSolution<solvedBoard, List<Move < X, RIGHT, 1 >>>::result == true, "Fail 4");
    static_assert(CheckSolution<solvedBoard, List<Move < X, LEFT, 3 >>>::result == true, "Fail 4");
    static_assert(CheckSolution<solvedBoard, List<>>::result == true, "Fail 4");
    static_assert(CheckSolution<solvedBoard, List<Move < X, RIGHT, 3 >>>::result == true, "Fail 4");
}
#endif //OOP_HW5_RUSHHOURTEST_H
