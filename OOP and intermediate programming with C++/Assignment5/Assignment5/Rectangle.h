/*
  CIS 22B
    Lab5 - Rectangle: This class inherits from the Basic Shape
    class and constructs a rectangle that returns the area of the
    rectangle as well as it's width and length.
  Author: Amir Tadros
  Other Group Members: Anh Hoang Mai Le, Arvind Kumar, Timothy Hyatt
  Date: February 22, 2020
*/

#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED

class Rectangle : public BasicShape {
private:
    long int width;
    long int length;
public:
    /* Constructor which takes in
    the desired width and length of
    the rectangle and calls the calcArea
    function.*/
    Rectangle(long int w, long int l){
        width = w;
        length = l;
        calcArea();
    }

    /* Function which takes no parameters
    and returns the local width variable.*/
    long int getWidth(){return (width);}

    /* Function which takes no parameters
    and returns the local length variable.*/
    long int getLength(){return (length);}

    /* Function which takes no parameters
    and calculates the area of the rectangle
    and assigns that value to the inherited
    area variable. Returns nothing.*/
    void calcArea()
    {
        area = width * length;
    }
};

#endif // RECTANGLE_H_INCLUDED
