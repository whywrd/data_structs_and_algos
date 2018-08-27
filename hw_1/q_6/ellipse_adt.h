/*
CS 110c 
Homework 1
Question 6
FILE: ellipse_adt.h

Ellipse ADT. 
An ellipse is uniquely identified by it's center, semi major
and semi minor axis. However, these data members can be calculated from other
data ie its foci. Therefore the ADT does not specify any hard requirements for
the data members, and by extension their setters, but it does require getters
for retreiving information about the underlying ellipse. In addition, the only operations 
supported by an ellipse are area and perimeter.
*/

#ifndef ELLIPSE_ADT_H_
#define ELLIPSE_ADT_H_

class EllipseADT {
    public:

        // get the x coordinate of the ellipse's center
        virtual float getX() const =0;

        // set the y coordinate of the ellipse's center
        virtual void setX(float) =0;

        // get the y coordinate of the ellipse's center
        virtual float getY() const =0;

        // set the y coordinate of the ellipse's center
        virtual void setY(float) =0;
        
        // get the length of the semi major axis
        virtual float getSemiMajor() const =0;

        // set the length of the semi major axis
        virtual void setSemiMajor(float) =0;
        
        // get the length of the semi minor axis
        virtual float getSemiMinor() const=0;

        // set the length of the semi minor axis
        virtual void setSemiMinor(float) =0;
        
        // calculate the area of the ellipse
        virtual float area() const =0;
        
        // calculate the perimter of the ellipse
        virtual float perimeter() const =0;
};

#endif
