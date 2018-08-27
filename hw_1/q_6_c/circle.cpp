/*
CS 110c
Homework 1
Question 6

Circle class implementation
*/

#include "circle.h"
#include <math.h>  // for pi


void Circle::setCenter(Point point) {
    Ellipse::setCenter(point);
}






Point Circle::getCenter() const { 
    return Ellipse::getCenter();
}





/*
setRadius
Set the underlying ellipse's major and minor axes to rad.
*/

void Circle::setRadius(Point point) {
    Ellipse::setSemiMajor(point);
    Ellipse::setSemiMinor(point);
}






Point Circle::getRadius() const {
    return Ellipse::getSemiMajor();
}






/*
area
Calculate the area of the circle
*/

float Circle::area() const {
    return Ellipse::area();
}






/*
perimeter
Calculate the perimeter of the circle
*/

float Circle::perimeter() const {
    return Ellipse::perimeter();
}