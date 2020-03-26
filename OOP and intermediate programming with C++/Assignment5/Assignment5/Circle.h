/*
  CIS 22B
    Lab5 - Circle: This class inherits from the Basic Shape
    class and constructs a class which calculates the area of
    a circle.
  Author: Timothy Hyatt - Others: Amir Tadros, Anh Hoang Mai Le, Arvind Kumar
  Date: February 22, 2020
*/

#ifndef Circle_h
#define Circle_h
# define M_PI           3.14159265358979323846  /* pi */

class Circle: public BasicShape
{
private:
    long centerX;
    long centerY;
    double radius;

public:
    // Default constructor
    Circle() { centerX = centerY = 0; radius = 0;}

    // Constructor with arguments
    Circle(long x, long y, double r)
    {
        centerX = x;
        centerY = y;
        radius = r;
        calcArea();
    }

    /*
      Gets the the center x coordinate
      Return value: long - The center x coord
    */
    long getCenterX(){ return centerX; }

    /*
      Gets the the center y coordinate
      Return value: long - The center y coord
    */
    long getCenterY(){ return centerY; }

    /*
      Calculate the area of the circle by multiplying
      the radius to the power of 2 and PI.
      Return value: void
    */
    void calcArea()
    {
        area = M_PI * radius * radius;
    }
};

#endif /* Circle_h */
