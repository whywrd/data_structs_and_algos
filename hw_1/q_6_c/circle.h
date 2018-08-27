/*
CS 110c 
Homework 1
Question 6

Cirlce class, implements the EllipseInterface.
*/


#ifndef CIRCLE_H_
#define CIRCLE_H_

#include "ellipse.h"
#include "point.h"

class Circle : private Ellipse {
    
    public:
        
        // Default constructor. Make everything 0.
        Circle() : Ellipse() {};

        // setters and getters
        void setCenter(Point);
        Point getCenter() const;
        void setRadius(Point);
        Point getRadius() const;

        // calculate the circle's area
        float area() const;

        // calculate the circle's perimeter
        float perimeter() const;
};

#endif