/*
CS 110c 
Homework 1
Question 6

Ellipse Interface. The only operations supported by an ellipse are area and
perimeter. Everything else is a data member, getter or setter.
*/

#ifndef ELLIPSE_INTERFACE_H_
#define ELLIPSE_INTERFACE_H_

class EllipseInterface {
    public:
        // calculate the area of the ellipse
        virtual float area() const =0;
        // calculate the perimter of the ellipse
        virtual float perimeter() const =0;
};

#endif
