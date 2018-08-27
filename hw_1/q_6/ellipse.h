/*
CS 110c 
Homework 1
Question 6

Ellipse class, implements the EllipseADT.
This implementation uses the coordinates of the center, the semi-major axis 
length and the semi-minor axis length to characterize the ellipse.
*/

#ifndef ELLIPSE_H_
#define ELLIPSE_H_

#include "ellipse_adt.h"

class Ellipse : EllipseADT {
    
    private:
        float x, y;       // the center' cartesian coordinates
        float semi_major; // the length of the semi major axis
        float semi_minor; // the length of the semi minor axis
    
    public:
       
        // default constructor. make everything 0.
        Ellipse(){x = y = semi_major = semi_minor = 0;};

        // constructor given the x and y coordinates of the center
        // and the major and minor semi axes' lengths. Axis lengths cannot
        // be negative.
        Ellipse(float x_coord, float y_coord, float major_length, 
                float minor_length);

        // setters and getters
        float getX() const;
        void setX(float);
        float getY() const;
        void setY(float);
        float getSemiMinor() const;
        void setSemiMinor(float);    // cannot be set to a negative value
        float getSemiMajor() const;
        void setSemiMajor(float);    // canot be set to a negative value

        // calculate the area of the ellipse
        float area() const;

        // calculate the perimeter of the ellipse
        float perimeter() const;
};


#endif
