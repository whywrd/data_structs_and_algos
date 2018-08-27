/*
CS 110c 
Homework 1
Question 6

Ellipse class, implements the EllipseInterface.
*/

#ifndef ELLIPSE_H_
#define ELLIPSE_H_

#include "ellipse_interface.h"
#include "point.h"

class Ellipse : EllipseInterface {
    
    private:
        Point center,       // the center of the circle
              semi_major,   // where the semi major axis intersects the perimeter
              semi_minor;   // where the semi minor axis intersects the perimeter
    
    public:
       
        // default constructor. make everything 0.
        Ellipse(){center = semi_major = semi_minor = Point(0, 0);};

        // setters and getters
        void setCenter(Point);
        Point getCenter() const;
        void setSemiMinor(Point);
        Point getSemiMinor() const;
        void setSemiMajor(Point);
        Point getSemiMajor() const;

        // calculate the area of the ellipse
        float area() const;

        // calculate the perimeter of the ellipse
        float perimeter() const;
};


#endif
