//
// Created by יונדב on 30/03/2024.
//

#ifndef OOP_HW5_MOVEVEHICLETEST_H
#define OOP_HW5_MOVEVEHICLETEST_H

#include "MoveVehicle.h"

void testMove(){
    typedef Move<X, UP, 3> move1;
    typedef Move<A, DOWN, 2> move2;
    typedef Move<B, LEFT, 1> move3;
    typedef Move<C, RIGHT, 4> move4;
    
    /* ---------------------------------------------------------------------- */
    
    //type tests
    static_assert(move1::type == X, "Fail 1");
    static_assert(move2::type == A, "Fail 2");
    static_assert(move3::type == B, "Fail 3");
    static_assert(move4::type == C, "Fail 4");
    
    /* ---------------------------------------------------------------------- */
    
    //direction tests
    static_assert(move1::direction == UP, "Fail 5");
    static_assert(move2::direction == DOWN, "Fail 6");
    static_assert(move3::direction == LEFT, "Fail 7");
    static_assert(move4::direction == RIGHT, "Fail 8");
    
    /* ---------------------------------------------------------------------- */
    
    //amount tests
    static_assert(move1::amount == 3, "Fail 9");
    static_assert(move2::amount == 2, "Fail 10");
    static_assert(move3::amount == 1, "Fail 11");
    static_assert(move4::amount == 4, "Fail 12");
    
}

void testMoveVehicle(){
    typedef GameBoard< List<
            List < BoardCell< O , DOWN , 3>, BoardCell< EMPTY , RIGHT , 0>, BoardCell< EMPTY , RIGHT , 0>, BoardCell< EMPTY , RIGHT , 0>, BoardCell< H , DOWN , 3>, BoardCell< EMPTY , RIGHT , 0> >,
            List < BoardCell< O , DOWN , 3>, BoardCell< EMPTY , RIGHT , 0>, BoardCell< A , RIGHT , 2>, BoardCell< A , LEFT , 2>, BoardCell< H , DOWN , 3>, BoardCell< EMPTY , RIGHT , 0> >,
            List < BoardCell< O , UP , 3>, BoardCell< EMPTY , RIGHT , 0>, BoardCell< EMPTY , RIGHT , 0>, BoardCell< X , LEFT , 2>, BoardCell< X , LEFT , 2>, BoardCell< EMPTY , RIGHT , 0> >,
            List < BoardCell< EMPTY , RIGHT , 0>, BoardCell< EMPTY , RIGHT , 0>, BoardCell< EMPTY , RIGHT , 0>, BoardCell< EMPTY , RIGHT , 0>, BoardCell< EMPTY , RIGHT , 0>, BoardCell< EMPTY , RIGHT , 0> >,
            List < BoardCell< EMPTY , RIGHT , 0>, BoardCell< EMPTY , RIGHT , 0>, BoardCell< B , DOWN , 2>, BoardCell< P , RIGHT , 3>, BoardCell< P , RIGHT , 3>, BoardCell< P , LEFT , 3> >,
            List < BoardCell< EMPTY , RIGHT , 0>, BoardCell< EMPTY , RIGHT , 0>, BoardCell< B , UP , 2>, BoardCell< EMPTY , RIGHT , 0>, BoardCell< C , RIGHT , 2>, BoardCell< C , LEFT , 2> >
    > > gameBoard;

    typedef GameBoard< List<
            List < BoardCell< EMPTY , RIGHT , 0 >, BoardCell< EMPTY , RIGHT , 0 >, BoardCell< EMPTY , RIGHT , 0>, BoardCell< X , RIGHT , 1 >, BoardCell< EMPTY , RIGHT , 0>, BoardCell< EMPTY , RIGHT , 0>, BoardCell< EMPTY , RIGHT , 0>>
    >> gameBoard2;
    
    typedef MoveVehicle<gameBoard2, 0, 3, RIGHT, 1>::board b1; // Valid move on simple board
    static_assert(b1::board::head::head::type == EMPTY, "Fail 1");
    static_assert(b1::board::head::next::head::type == EMPTY, "Fail 2");
    static_assert(b1::board::head::next::next::head::type == EMPTY, "Fail 3"); 
    static_assert(b1::board::head::next::next::next::head::type == EMPTY, "Fail 4");
    static_assert(b1::board::head::next::next::next::next::head::type == X, "Fail 5"); //Check that it moved
    static_assert(b1::board::head::next::next::next::next::head::length == 1, "Fail 5");
    static_assert(b1::board::head::next::next::next::next::next::head::type == EMPTY, "Fail 6");
    static_assert(b1::board::head::next::next::next::next::next::next::head::type == EMPTY, "Fail 7");
    
    typedef MoveVehicle<gameBoard, 2, 4, LEFT, 2>::board b2; // Valid move left
    static_assert(b2::board::next::next::head::head::type == O, "Fail 8");
    static_assert(b2::board::next::next::head::next::head::type == X, "Fail 9");
    static_assert(b2::board::next::next::head::next::head::length == 2, "Fail 9");
    static_assert(b2::board::next::next::head::next::next::head::type == X, "Fail 10");
    static_assert(b2::board::next::next::head::next::next::next::head::type == EMPTY, "Fail 11");
    static_assert(b2::board::next::next::head::next::next::next::next::head::type == EMPTY, "Fail 12");
    static_assert(b2::board::next::next::head::next::next::next::next::next::head::type == EMPTY, "Fail 13");

    typedef MoveVehicle<gameBoard, 2, 0, DOWN, 2>::board b3; // Valid move down
    static_assert(b3::board::head::head::type == EMPTY, "Fail 14");
    static_assert(b3::board::next::head::head::type == EMPTY, "Fail 15");
    static_assert(b3::board::next::next::head::head::type == O, "Fail 16");
    static_assert(b3::board::next::next::next::head::head::type == O, "Fail 17");
    static_assert(b3::board::next::next::next::next::head::head::type == O, "Fail 17");
    static_assert(b3::board::next::next::next::next::next::head::head::type == EMPTY, "Fail 18");
    
    typedef MoveVehicle<gameBoard, 4, 2, UP, 1>::board b4; // Valid move up
    static_assert(b4::board::next::next::next::head::next::next::head::type == B, "Fail 19");
    static_assert(b4::board::next::next::next::head::next::next::head::length == 2, "Fail 20");
    static_assert(b4::board::next::next::next::next::head::next::next::head::type == B, "Fail 21");
    static_assert(b4::board::next::next::next::next::next::head::next::next::head::type == EMPTY, "Fail 22");
}
#endif //OOP_HW5_MOVEVEHICLETEST_H
