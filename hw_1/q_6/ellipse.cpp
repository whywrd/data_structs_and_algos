/*
CS 110c 
Homework 1
Question 6
FILE: ellipse.cpp

implementation of the ellipse class
*/

#include "ellipse.h"
#include <math.h>  // for pi

/* 
fully parameterized constructor. set the private data members to the specified
values and make sure that the axis lengths are not negative.
*/

Ellipse::Ellipse(float x_coord, float y_coord, float major_length, 
                 float minor_length) {
    if(major_length < 0 || minor_length < 0) {
        throw("minor and major axes cannot be negative");
    }
    if(major_length < minor_length) {
        throw("major length must be greater than minor length");
    }
    x = x_coord;
    y = y_coord;
    semi_major = major_length;
    semi_minor = minor_length;
}






/*
setX
mutator to set the x coordinate of the ellipse's center
*/

void Ellipse::setX(float x_coord) {
    x = x_coord;
}






/*
getX
accessor to get the x coordinate of the ellipse's center
*/

float Ellipse::getX() const {
    return x;
}






/*
setY
mutator to set the y coordinate of the ellipse's center
*/

void Ellipse::setY(float y_coord){
    y = y_coord;
}






/*
getY
accessor to set the y coordinate of the ellipse's center
*/

float Ellipse::getY() const{
    return y;
}






/*
setSemiMajor
Set the semi major axis, need to make sure that the length is not negative
and that the lenght is greater than the semi minor axis.
*/

void Ellipse::setSemiMajor(float length) {
    if(length < 0) {
        throw("axis length cannot be negative");
    }
    if(length < semi_minor) {
        throw("major axis lenght must be greater than minor axis length");
    }
    semi_major = length;
}






/*
getSemiMajor
accessor to get the ellipse's semi major axis length
*/

float Ellipse::getSemiMajor() const{
    return semi_major;
}




/*
setSemiMinor
Set the semi minor axis length. Need to make sure that the length is not
negative and that the length is less than the length of the semi major axis.
*/

void Ellipse::setSemiMinor(float length) {
    if(length < 0) {
        throw("axis length cannot be negative");
    }
    if(length > semi_major) {
        throw("minor axis length must be less than major axis length");
    }
    semi_minor = length;
}






/*
getSemiMinor
accessor to get the length of the ellipse's semi major axis
*/

float Ellipse::getSemiMinor() const {
    return semi_minor;
}






/*
area
Calculate the area of the ellipse
*/

float Ellipse::area() const {
    return M_PI * semi_major * semi_minor;
}






/*
perimeter
calculate the are of the perimeter
*/

float Ellipse::perimeter() const {
    float h, c_1, c_2;
    h = pow(semi_major - semi_minor, 2) / pow(semi_major + semi_minor, 2);
    c_1 = M_PI * (semi_major + semi_minor);
    c_2 = (3 * h)/(10 + (pow(4 - (3 * h), -0.5)));
    return c_1 * (1 + c_2);
}