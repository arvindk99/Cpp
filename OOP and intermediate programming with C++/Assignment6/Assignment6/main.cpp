//
//  main.cpp
//  This is the tester for the LoShuSquare class
//
//  Created by Hellen Pacheco on 6/9/19.
//  Copyright © 2018 Hellen Pacheco. All rights reserved.
//

#include <iostream>
#include "LoShuSquare.h"
using namespace std;

int main(int argc, const char * argv[]) {
    
    //attributes to check if all cases match
    bool isMagic = false;
    //attribute for custom size
    int size;
    //attributes to specify the value for each element in the square
    int row, col, value;
    
    //Prompting user for a square size
    cout << "Please enter a size for your Magic Square: ";
    cin >> size;

    //Creating a square object with the custom size
    LoShuSquare magic(size);

    //printing initial board
    magic.printBoard();
    
    // do/while loop to run until the board is a magic square
    do
    {
        //collects the input for each row, and col
        for (row = 0; row < size; row++)
        {
            cout << "Please enter values for row " << row+1 << " separated by space: ";
            for (col = 0; col < size; col++)
            {
                cin >> value;
                magic.fill(row, col, value);
            }
            //prints the board with the users new values
            magic.printBoard();
            //checks if the square is a magic square
            if (magic.check())
            {
                isMagic = true;
                cout << "Congratulations, this is a magic square!" << endl;
            }
            else
            {
                cout << "This is not a magic square. Try again. " << endl;
            }
        }
    } while (!magic.check());
    return 0;
}

/*
 Please enter a size for your Magic Square: 4
  | 0 |  | 0 |  | 0 |  | 0 |
  | 0 |  | 0 |  | 0 |  | 0 |
  | 0 |  | 0 |  | 0 |  | 0 |
  | 0 |  | 0 |  | 0 |  | 0 |
 Please enter values for row 0 separated by space: 8 11 14 1
  | 8 |  | 11 |  | 14 |  | 1 |
  | 0 |  | 0 |  | 0 |  | 0 |
  | 0 |  | 0 |  | 0 |  | 0 |
  | 0 |  | 0 |  | 0 |  | 0 |
 This is not a magic square. Try again.
 Please enter values for row 1 separated by space: 13 2 7 12
  | 8 |  | 11 |  | 14 |  | 1 |
  | 13 |  | 2 |  | 7 |  | 12 |
  | 0 |  | 0 |  | 0 |  | 0 |
  | 0 |  | 0 |  | 0 |  | 0 |
 This is not a magic square. Try again.
 Please enter values for row 2 separated by space: 3 16 9 6
  | 8 |  | 11 |  | 14 |  | 1 |
  | 13 |  | 2 |  | 7 |  | 12 |
  | 3 |  | 16 |  | 9 |  | 6 |
  | 0 |  | 0 |  | 0 |  | 0 |
 This is not a magic square. Try again.
 Please enter values for row 3 separated by space: 10 5 4 15
  | 8 |  | 11 |  | 14 |  | 1 |
  | 13 |  | 2 |  | 7 |  | 12 |
  | 3 |  | 16 |  | 9 |  | 6 |
  | 10 |  | 5 |  | 4 |  | 15 |
 Congratulations, this is a magic square!
 Program ended with exit code: 0
 */
