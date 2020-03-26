//
//  LoShuSquare.cpp
//  Assignment6
//
//  Created by Arvind Kumar on 3/3/20.
//  Copyright © 2020 Arvind Kumar. All rights reserved.
//

#include "LoShuSquare.h"

//Constructor
LoShuSquare::LoShuSquare(int size)
{
    //sets ROWS and COLS to the custom size of user's desire
    ROWS = size;
    COLS = size;
    
    /*create and initialize the dynamically allocated array
     to the size of the ROWS x COLS*/
    a = new int*[ROWS];
    for(int i = 0; i < ROWS; i++)
    {
        a[i] = new int[COLS];
    }
    
    //set all the values to 0
    for(int x = 0; x < ROWS; x++)
    {
        for(int y = 0; y < ROWS; y++)
        {
            a[x][y] = 0;
        }
    }
}

//Destructor
LoShuSquare::~LoShuSquare()
{
    //dynamically delete teh values of array a as it loops through
    for(int i = 0; i < ROWS; i++)
    {
        delete [] a[i];
    }
    delete [] a;
}

//printing the board
void LoShuSquare::printBoard()
{
    //counter for how many pieces are printed across in the row
    int count = 0;
    
    //iterate through
    for(int x = 0; x < ROWS; x++)
    {
        for(int y = 0; y < ROWS; y++)
        {
            //print the value of that piece
            cout << " | " << a[x][y] <<" | ";
            count++;
            /*if counter = to the number of rows, then go to the next line
             to print in a square format then set count back to 0.*/
            if (count == ROWS)
            {
                cout << endl;
                count = 0;
            }
        }
    }
}

//Fills the board
void LoShuSquare::fill(int row, int col, int value)
{
    //if the entered value is a valid value
    if( value > 0 && value < (ROWS*ROWS + 1))
    {
        //insert into the corresponding spot in row;
        a[row][col] = value;
    }
    else
    {
        //else leave as a 0 and return a invalid message
        cout << "The value you entered is invalid, please enter a new value!" << endl;
    }
}

//Check
bool LoShuSquare::check()
{
    //Checks if all the helper method that checks the conditions are true
    if(checkDiagonal() == true && checkVertical() == true && checkHorizontal() == true)
    {
        /*checks if all the sums of the diagonals, horizontal,
         and vertical arrays are equal*/
        if(diagonal == vertical && diagonal == horizontal && horizontal == vertical)
        {
            //return true
            return true;
        }
    }
    //else false
    return false;
}


//HELPER METHODS
bool LoShuSquare::checkDiagonal()
{
    /* create two attributes to calculate the sum
     of the two diagonals in the square*/
    int diagonal1 = 0;
    int diagonal2 = 0;
    
    //iterate through the square
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            /*for the first diagonal, if the value of row, and col
             are equal, then that is one of the points so add the value
             inside that into the first diagonal total.*/
            if(i == j)
            {
                diagonal1+=a[i][j];
            }
        }
    }
    //iterate through the square for the second diagonal
    for(int x = 0; x < ROWS; x++)
    {
        for(int y = 0; y < COLS; y++)
        {
            /*for the second diagonal, if the value of the total number
             of rows-(the current row +1), and col are equal, then that
             is one of the points so add the value inside that
             into the first diagonal total.*/
            if(y == (ROWS-(x+1)))
            {
                diagonal2 += a[x][y];
            }
        }
    }
    //check if both the diagonal sums are equal
    if(diagonal1 == diagonal2)
    {
        //return true, and set the private diagonal sum variable
        diagonal = diagonal1;
        return true;
    }
    //else false
    return false;
    
}

bool LoShuSquare::checkHorizontal()
{
    //creating a local array of the size of the number of rows
    int localArray[ROWS];
    //initialize a sum variable
    int sum = 0;
    //initialize a horizontal sum variable to set the sum of a base to compare
    int horizontalSum = 0;

    //iterate through the square
    
    for(int i = 0; i <ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            //total up the row
            sum =sum + a[i][j];
        }
        //add the row total for that specific row to the local array
        localArray[i] = sum;
        //set sum back to 0
        sum = 0;
       
    }
    
    //setting a base sum to compare to
    horizontalSum = localArray[0];
    
    //check if all the values in the array are the same
    for(int y = 0; y < ROWS; y++)
    {
        if(localArray[y] != horizontalSum)
        {
            //return false if it doesn't
            return false;
        }
    }
    //return true, and set the private horizontal sum variable
    horizontal = horizontalSum;
    return true;
}

bool LoShuSquare::checkVertical()
{
    //creating a local array of the size of the number of cols
    int localArray[COLS];
    //initialize a sum variable
    int sum = 0;
    //initialize a vertical sum variable to set the sum of a base to compare
    int verticalSum = 0;

    //iterate through the square
    for(int i = 0; i <ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            //total up the row
            sum =sum + a[j][i];
        }
        //add the col total for that specific col to the local array
        localArray[i] = sum;
        //set sum back to 0
        sum = 0;
       
    }
    //setting a base sum to compare to
    verticalSum = localArray[0];
    
    //check if all the values in the array are the same
    for(int y = 0; y < ROWS; y++)
    {
        if(localArray[y] != verticalSum)
        {
            //return false if it doesn't
            return false;
        }
    }
    //return true, and set the private vertical sum variable
    vertical = verticalSum;
    return true;
}



