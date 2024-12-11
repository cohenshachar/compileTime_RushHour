//
// Created by יונדב on 30/03/2024.
//

#ifndef OOP_HW5_FAILTEST_H
#define OOP_HW5_FAILTEST_H

#include "RushHour.h"
#include <iostream>

    typedef GameBoard< List<
            List < BoardCell< EMPTY , RIGHT , 0>, BoardCell< EMPTY , RIGHT , 0>, BoardCell< EMPTY , RIGHT , 0>, BoardCell< EMPTY , RIGHT , 0>, BoardCell< O , DOWN , 3>, BoardCell< EMPTY , RIGHT , 0> >,
            List < BoardCell< EMPTY , RIGHT , 0>, BoardCell< EMPTY , RIGHT , 0>, BoardCell< A , RIGHT , 2>, BoardCell< A , LEFT , 2>, BoardCell< O , DOWN , 3>, BoardCell< EMPTY , RIGHT , 0> >,
            List < BoardCell< EMPTY , RIGHT , 0>, BoardCell< EMPTY , RIGHT , 0>, BoardCell< X , RIGHT , 2>, BoardCell< X , LEFT , 2>, BoardCell< O , UP , 3>, BoardCell< EMPTY , RIGHT , 0> >,
            List < BoardCell< EMPTY , RIGHT , 0>, BoardCell< EMPTY , RIGHT , 0>, BoardCell< EMPTY , RIGHT , 0>, BoardCell< EMPTY , RIGHT , 0>, BoardCell< EMPTY , RIGHT , 0>, BoardCell< EMPTY , RIGHT , 0> >,
            List < BoardCell< EMPTY , RIGHT , 0>, BoardCell< EMPTY , RIGHT , 0>, BoardCell< B , DOWN , 2>, BoardCell< P , RIGHT , 3>, BoardCell< P , RIGHT , 3>, BoardCell< P , LEFT , 3> >,
            List < BoardCell< EMPTY , RIGHT , 0>, BoardCell< EMPTY , RIGHT , 0>, BoardCell< B , UP , 2>, BoardCell< EMPTY , RIGHT , 0>, BoardCell< C , RIGHT , 2>, BoardCell< C , LEFT , 2> >
    > > gameBoard1;
    
void testFail(){
    //Remove the comment from each line separately and make sure your compilation fails through static_assert!
    
    //int emptyMove = Move<EMPTY, UP, 3>::amount;
    
    //typedef typename MoveVehicle<gameBoard1, -1, 3, RIGHT, 2>::board oobRow;
    //typedef typename MoveVehicle<gameBoard1, 2, 6, RIGHT, 2>::board oobCol;
    //typedef typename MoveVehicle<gameBoard1, 4, 0, RIGHT, 1>::board moveEmpty;
    //typedef typename MoveVehicle<gameBoard1, 1, 2, RIGHT, 1>::board moveIntoAnotherVehicle;
    //typedef typename MoveVehicle<gameBoard1, 1, 2, UP, 1>::board directionMismatch;
    
    std::cout << "(Fail conditions not tested - make sure to check out FailTest.h!)" << std::endl;
}

#endif //OOP_HW5_FAILTEST_H
