/*
CS 110c 
Homework 1
Question 6
FILE: cirlce.h

Cirlce class extends Ellipse. The only difference between a circle and a
ellipse is that it's foci are the same ie it's major and minor axes have
the same length. When this is the case it's major and minor axes are equal
and their length is the radius. Therefore, inherite privately from Ellipse
and provide an interface to the underlying structure that requires the major
and minor semi axis to be equal ie merge them into a radius. 
*/


#ifndef CIRCLE_H_
#define CIRCLE_H_

#include "ellipse.h"

class Circle : private Ellipse {
    
    public:
        
        // Default constructor
        Circle() : Ellipse() {};
        
        // Fully parameterized constructor. Make sure radius is not negative
        Circle(float x_coord, float y_coord, float rad);

        // setters and getters
        void setX(float);
        float getX() const;
        void setY(float);
        float getY() const;
        void setRadius(float);  // radius cannot be negative
        float getRadius() const;

        // calculate the circle's area
        float area() const;

        // calculate the circle's perimeter
        float perimeter() const;
};

#endif