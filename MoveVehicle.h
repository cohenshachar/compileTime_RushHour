#ifndef HW5_MOVEVEHICLE_H
#define HW5_MOVEVEHICLE_H

#include "CellType.h"
#include "Direction.h"
#include "GameBoard.h"
#include "Utilities.h"
#include "TransposeList.h"

using namespace std;

// Find_Car_Helper Class Declaration
// This class recursively iterates over the board's cells and finds the coordinates of a cell containing an end (the front or back) of the car "type" (note that the first end to be found depends on the direction of the search).
// type - the car to find
// type2 - the car on the current cell
// (row, col) - the coordinates of the current cell
// done - search is done
// B - main list of the board
template <CellType type, int row, int col, bool done, typename B>
struct Find_Car_Helper{
    typedef GameBoard<B> gameBoard;
    typedef typename gameBoard::board mainList;
    static constexpr bool last_col = (gameBoard::width == col + 1);
    static constexpr bool last_cell_in_board = (gameBoard::length == row + 1) && last_col;

    static_assert (!(!done && last_cell_in_board), "type was not found!");

    static constexpr int next_row = ConditionalInteger<last_col, row+1, row>::value; // this is the next cell's row
    static constexpr int next_col = ConditionalInteger<last_col, 0, col+1>::value; // this is the next cell's column

    typedef typename GetAtIndex<next_row, mainList>::value next_row_list;
    typedef typename GetAtIndex<next_col, next_row_list>::value next_cell;
    typedef Find_Car_Helper<type, next_row, next_col, type == next_cell::type, mainList> next_helper;

    static constexpr int X_row = ConditionalInteger<done, row, next_helper::X_row >::value;
    static constexpr int X_col = ConditionalInteger<done, col, next_helper::X_col >::value;
};

// Find_Car_Helper Specialization - stopping condition
template <CellType type, int row, int col, typename B>
struct Find_Car_Helper<type, row, col, true, B>{
    static constexpr int X_row = row;
    static constexpr int X_col = col;
};

// FindCar Class Declaration
// (uses Find_Car_Helper to find car "type" in board "Bo" - read Find_Car_Helper for more info)
template<CellType type, typename Bo>
struct FindCar{
    typedef Bo game_board;
    typedef typename game_board::board mainList;
    typedef typename mainList::head::head first_cell;

    typedef Find_Car_Helper<type,0,0,type == first_cell::type,mainList> car_loc;
    static constexpr int X_row_idx = car_loc::X_row;
    static constexpr int X_col_idx = car_loc::X_col;
};

// direction Class Declaration
// This class computes the further end of a car respect to "c" given the end found using FindCar.
// (e.g. if "c"=RIGHT, the further end of the car is the left end...)
// c - a direction
// (Ro, Col) - end of the car from top left
// len - the car's length
template<Direction c,int Ro,int Col,int len>
struct Dir{};

// direction Specialization (you need to implement more specializations similarly)
template< int Ro,int Col,int len>
struct Dir<RIGHT,Ro,Col,len> {
    static constexpr int axis=Ro;
    static constexpr int p_c=Col+len-1;
    static constexpr int p_f=Col;
};
template< int Ro,int Col,int len>
struct Dir<LEFT,Ro,Col,len> {
    static constexpr int axis=Ro;
    static constexpr int p_c=Col;
    static constexpr int p_f=Col+len-1;
};
template< int Ro,int Col,int len>
struct Dir<UP,Ro,Col,len> {
    static constexpr int axis=Col;
    static constexpr int p_c=Ro;
    static constexpr int p_f=Ro+len-1;
};
template< int Ro,int Col,int len>
struct Dir<DOWN,Ro,Col,len> {
    static constexpr int axis=Col;
    static constexpr int p_c=Ro+len-1;
    static constexpr int p_f=Ro;
};

// direct Class Declaration
// This class recursively moves a car "Am" steps on the board in a certain direction
// d - the direction of the movement
// counter - recursive counter (remaining amount of steps)
// myL - main list of the board
// my_cell - a cell on the current board containing the car to be moved
// (Ro, Co) - coordinates of the further end of the car respect to "d" (e.g. if "d"=RIGHT, the further end of the car is the left end...)
template<Direction d,int counter,typename myL,typename my_cell,int list,int index_start,int index_end>
struct direct{};

// direct Specialization (you need to implement more specializations similarly)
template<int counter,typename myL,typename my_cell,int Ro,int Co_c,int Co_f>
struct direct<RIGHT,counter,myL,my_cell,Ro, Co_c, Co_f>{
    typedef typename direct<RIGHT,counter-1,myL,my_cell,Ro, Co_c, Co_f>::movedGameList gameList; // main list of the board after we moved the car "count"-1 steps
    static constexpr int newCo_c = Co_c+counter;
    static constexpr int newCo_f = Co_f+counter;
    typedef typename GetAtIndex<Ro,gameList>::value board_row;
    static_assert((newCo_c >= 0 && newCo_c < board_row::size), "Error, move out of bounds MoveVehicle");
    typedef typename GetAtIndex<newCo_c,board_row>::value to_celli;
    static_assert(to_celli::type == EMPTY, "Error,Collision cell MoveVehicle");
    typedef typename SetAtIndex<newCo_c,my_cell,board_row>::list FirstUpdateRowList;
    typedef typename SetAtIndex<newCo_f-1,BoardCell<EMPTY,RIGHT, 0>,FirstUpdateRowList>::list SecondUpdateRowList;
    typedef typename SetAtIndex<Ro,SecondUpdateRowList,gameList>::list movedGameList;
};
// direct Specialization (you need to implement more specializations similarly)
template<typename myL,typename my_cell,int Ro,int Co_c,int Co_f>
struct direct<RIGHT,0,myL,my_cell,Ro, Co_c, Co_f>{
    typedef myL movedGameList;
};

template<int counter,typename myL,typename my_cell,int Ro,int Co_c,int Co_f>
struct direct<LEFT,counter,myL,my_cell,Ro, Co_c, Co_f>{
    typedef typename direct<LEFT,counter-1,myL,my_cell,Ro, Co_c, Co_f>::movedGameList gameList; // main list of the board after we moved the car "count"-1 steps
    static constexpr int newCo_c = Co_c-counter;
    static constexpr int newCo_f = Co_f-counter;
    typedef typename GetAtIndex<Ro,gameList>::value board_row;
    static_assert((newCo_c >= 0 && newCo_c < board_row::size), "Error, move out of bounds MoveVehicle");
    typedef typename GetAtIndex<newCo_c,board_row>::value to_celli;
    static_assert(to_celli::type == EMPTY, "Error,Collision cell MoveVehicle");
    typedef typename SetAtIndex<newCo_c,my_cell,board_row>::list FirstUpdateRowList;
    typedef typename SetAtIndex<newCo_f+1,BoardCell<EMPTY,RIGHT, 0>,FirstUpdateRowList>::list SecondUpdateRowList;
    typedef typename SetAtIndex<Ro,SecondUpdateRowList,gameList>::list movedGameList;
};

// direct Specialization (you need to implement more specializations similarly)
template<typename myL,typename my_cell,int Ro,int Co_c,int Co_f>
struct direct<LEFT,0,myL,my_cell,Ro, Co_c, Co_f>{
    typedef myL movedGameList;
};
template<int counter, typename myL,typename my_cell,int Co,int Ro_c,int Ro_f>
struct direct<UP,counter,myL,my_cell,Co, Ro_c, Ro_f>{
    typedef typename Transpose<typename direct<LEFT,counter,typename Transpose<myL>::matrix,my_cell,Co, Ro_c, Ro_f>::movedGameList>::matrix movedGameList;
};
template<int counter,typename myL,typename my_cell,int Co,int Ro_c,int Ro_f>
struct direct<DOWN,counter,myL,my_cell,Co, Ro_c, Ro_f>{
    typedef typename Transpose<typename direct<RIGHT,counter,typename Transpose<myL>::matrix,my_cell,Co, Ro_c, Ro_f>::movedGameList>::matrix movedGameList;
};

// MoveVehicle Class Declaration
template<typename gameBoard, int R, int C, Direction D, int A>
struct MoveVehicle{};

// MoveVehicle Specialization
template<typename B, int R1, int C1, Direction Dl, int A>
struct MoveVehicle<GameBoard<B>,R1,C1,Dl,A>{

    typedef GameBoard<B> PrevBoard;
    typedef typename PrevBoard::board mainList;

    static_assert(((R1 >= 0 &&  R1 < PrevBoard::length) && (C1 >= 0 && C1 < PrevBoard::width)), "Error, out of bounds MoveVehicle");

    typedef typename GetAtIndex<C1,typename GetAtIndex<R1,mainList>::value>::value my_cell;
    static_assert(my_cell::type != EMPTY, "Error,empty cell MoveVehicle");
    static_assert(!((my_cell::direction == UP || my_cell::direction == DOWN) && (Dl == RIGHT || Dl == LEFT)), "Error,car is vertical, wrong direction MoveVehicle");
    static_assert(!((my_cell::direction == LEFT || my_cell::direction == RIGHT) && (Dl == UP || Dl == DOWN)), "Error,car is horizontal, wrong direction MoveVehicle");

    static constexpr int R2= FindCar<my_cell::type,PrevBoard>::X_row_idx;
    static constexpr int C2= FindCar<my_cell::type,PrevBoard>::X_col_idx;

    // the further end:
    static constexpr int C3= Dir<Dl,R2,C2,my_cell::length>::p_c;
    static constexpr int F3= Dir<Dl,R2,C2,my_cell::length>::p_f;
    static constexpr int AX3= Dir<Dl,R2,C2,my_cell::length>::axis;

    typedef typename direct<Dl,A,B,my_cell,AX3,C3,F3>::movedGameList o1;
    typedef GameBoard<o1> board;
};


// MoveVehicle Class Declaration
template<CellType T, Direction D, int A>
struct Move{
    static_assert(T != EMPTY, "Error Row,Move");
    constexpr static CellType type = T;
    constexpr static Direction direction = D;
    constexpr static int amount = A;
};

#endif //HW5_MOVEVEHICLE_H