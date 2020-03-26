//
//  LoShuSquare.h
//  Assignment6
//
//  Created by Arvind Kumar on 3/3/20.
//  Copyright © 2020 Arvind Kumar. All rights reserved.
//

#ifndef LoShuSquare_h
#define LoShuSquare_h
#include <iostream>
#include <string>
using namespace std;

class LoShuSquare
{
private:
    //Variables to dynamically allocate gameboard size
    int ROWS = 0;
    int COLS = 0;
    int size;
    
    //the sums in each direction
    
    int horizontal, vertical, diagonal;
    
    //Helper methods for the check function
    
    /*
     PRE- Nothing
     POST- boolean value
     PURPOSE- check if the diagonals condition is met
     */
    bool checkDiagonal();
    
    /*
    PRE- Nothing
    POST- boolean value
    PURPOSE- check if the horizontal condition is met
    */
    bool checkHorizontal();
    
    /*
    PRE- Nothing
    POST- boolean value
    PURPOSE- check if the vertical condition is met
    */
    bool checkVertical();
    
public:
    //initialize the array
    int** a;  // allocates an array of pointers (each pointing to a row)
    
    //Constructor
    LoShuSquare(int);
    //Destructor
    ~LoShuSquare();
    
    /*
    PRE- collects three ints, row, col, value
    POST- nothing
    PURPOSE- Collect the row, col, for the index and input
     value into array[row][col]
    */
    void fill(int, int, int);
    
    /*
    PRE- Nothing
    POSE- Nothing
    PURPOSE- print out the current status of the board;
    */
    void printBoard();
    
    /*
    PRE- nothing
    POSE- boolean value
    PURPOSE- checks if all the conditions are met and the square
     is a LoShu magic square
    */
    bool check();
    
    
    //setting the value of rows
    void setROWS(int r) { ROWS = r; }
    
    //setting the value of cols
    void setCOLS(int c) { ROWS = c; }
    
    //getting the value of rows
    int getROWS() { return ROWS; }
    
    //getting the value of cols
    int getCOLS() { return COLS; }
};
#endif /* LoShuSquare_h */



