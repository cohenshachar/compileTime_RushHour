//
// Created by יונדב on 30/03/2024.
//

#ifndef OOP_HW5_GAMEBOARDTEST_H
#define OOP_HW5_GAMEBOARDTEST_H

#include "GameBoard.h"
#include "BoardCell.h"

void testGameBoard(){
    typedef GameBoard< List<
            List < BoardCell< EMPTY , RIGHT , 1>, BoardCell< EMPTY , RIGHT , 0>, BoardCell< EMPTY , RIGHT , 0>, BoardCell< EMPTY , RIGHT , 0>, BoardCell< O , DOWN , 3>, BoardCell< EMPTY , RIGHT , 0> >,
            List < BoardCell< EMPTY , RIGHT , 2>, BoardCell< EMPTY , RIGHT , 0>, BoardCell< A , RIGHT , 2>, BoardCell< A , LEFT , 2>, BoardCell< O , DOWN , 3>, BoardCell< EMPTY , RIGHT , 0> >,
            List < BoardCell< EMPTY , RIGHT , 3>, BoardCell< EMPTY , RIGHT , 0>, BoardCell< X , RIGHT , 2>, BoardCell< X , LEFT , 2>, BoardCell< O , UP , 3>, BoardCell< EMPTY , RIGHT , 0> >,
            List < BoardCell< EMPTY , RIGHT , 0>, BoardCell< EMPTY , RIGHT , 0>, BoardCell< EMPTY , RIGHT , 0>, BoardCell< EMPTY , RIGHT , 0>, BoardCell< EMPTY , RIGHT , 0>, BoardCell< EMPTY , RIGHT , 0> >,
            List < BoardCell< EMPTY , RIGHT , 0>, BoardCell< EMPTY , RIGHT , 0>, BoardCell< B , DOWN , 2>, BoardCell< P , RIGHT , 3>, BoardCell< P , RIGHT , 3>, BoardCell< P , LEFT , 3> >,
            List < BoardCell< EMPTY , RIGHT , 0>, BoardCell< EMPTY , RIGHT , 0>, BoardCell< B , UP , 2>, BoardCell< EMPTY , RIGHT , 0>, BoardCell< C , RIGHT , 2>, BoardCell< C , LEFT , 2> >
    > > gameBoard1;

    typedef GameBoard< List<
            List < BoardCell< P , LEFT , 1> >,
            List < BoardCell< C , DOWN , 4> >,
            List < BoardCell< EMPTY , RIGHT , 0> >,
            List < BoardCell< EMPTY , RIGHT , 0> >,
            List < BoardCell< EMPTY , RIGHT , 0> >,
            List < BoardCell< EMPTY , RIGHT , 0> >,
            List < BoardCell< X , RIGHT , 1> >
    > > gameBoard2;

    /* ---------------------------------------------------------------------- */
    
    //width tests
    static_assert(gameBoard1::width == 6, "Fail 1");
    static_assert(gameBoard2::width == 1, "Fail 2");

    /* ---------------------------------------------------------------------- */
    
    //length tests
    static_assert(gameBoard1::length == 6, "Fail 3");
    static_assert(gameBoard2::length == 7, "Fail 4");

    /* ---------------------------------------------------------------------- */
    
    //board tests
    static_assert(gameBoard1::board::head::size == 6, "Fail 5"); //First row
    static_assert(gameBoard1::board::next::head::next::size == 5, "Fail 6"); //Second row from second cell
    static_assert(gameBoard1::board::head::head::type == EMPTY, "Fail 7"); //(0,0) cell type
    static_assert(gameBoard1::board::next::head::next::next::head::type == A, "Fail 8"); //(1,2) cell type
    static_assert(gameBoard1::board::next::head::next::next::next::head::direction == LEFT, "Fail 9"); //(1,3) cell direction
    static_assert(gameBoard1::board::next::next::head::next::next::head::length == 2, "Fail 10"); //(2,2) cell length

    static_assert(gameBoard2::board::head::size == 1, "Fail 11"); //First row
    static_assert(gameBoard2::board::next::next::next::next::next::next::head::head::type == X, "Fail 12"); //(0,6) cell type
    static_assert(gameBoard2::board::next::next::next::next::next::next::head::head::direction == RIGHT, "Fail 13"); //(0,6) cell direction
    static_assert(gameBoard2::board::next::next::next::next::next::next::head::head::length == 1, "Fail 14"); //(0,6) cell length
    
}
#endif //OOP_HW5_GAMEBOARDTEST_H
