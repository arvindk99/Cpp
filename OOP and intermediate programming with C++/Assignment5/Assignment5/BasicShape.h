/*
  CIS 22B
    Lab5 - Basic Shape: The Basic Shape class that Circle
    and Rectangle class inherits from. It stores the area
    of the shape and calculates it.
  Author: Arvind Kumar, Others: Amir Tadros, Anh Hoang Mai Le, Timothy Hyatt
  Date: February 22, 2020
*/

#ifndef BasicShape_h
#define BasicShape_h

using namespace std;

class BasicShape
{
protected:
    double area;
public:
    // Default constructor
    BasicShape(){ area = 0; }

    // Returns the area of the shape
    double getArea() { return area; }

    // Calculates the area of the shape
    virtual void calcArea() = 0;
};
#endif /* BasicShape_h */
