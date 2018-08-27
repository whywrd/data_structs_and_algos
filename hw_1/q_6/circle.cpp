/*
CS 110c
Homework 1
Question 6
FILE: circle.cpp

Circle class implementation
*/

#include "circle.h"
#include <math.h>  // for pi

/*
Fully parameterized constructor. Call Ellipse's fully parameterized
constructor, but use rad for both the major and minor axes.
*/

Circle::Circle(float x_coord, float y_coord, float rad) 
    : Ellipse(x_coord, y_coord, rad, rad) {
}






/* 
setX
set the x coordinate of the circle's center
*/

void Circle::setX(float x_coord) {
    Ellipse::setX(x_coord);
}





/*
getX
accessor for getting the x coordinate of the circle
*/

float Circle::getX() const { 
    return Ellipse::getX();
}






/*
setY
mutator to set the y coordinate of the circle's center
*/

void Circle::setY(float y_coord) {
    Ellipse::setY(y_coord);
}






/*
getY
accessor to get the y coordinate of the circle's center
*/

float Circle::getY() const {
    return Ellipse::getY();
}





/*
setRadius
Set the underlying ellipse's major and minor axes to rad.
*/

void Circle::setRadius(float rad) {
    Ellipse::setSemiMajor(rad);
    Ellipse::setSemiMinor(rad);
}






/*
getRadius
accessor to get the circles radius, this is equivalent to getting
the underlying ellipse's major or minor axis.
*/

float Circle::getRadius() const {
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