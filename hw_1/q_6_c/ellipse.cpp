/*
implementation of the ellipse class
*/

#include "ellipse.h"
#include <math.h>  // for pi


void Ellipse::setCenter(Point point) {
    center = point;
}






Point Ellipse::getCenter() const {
    return center;
}






void Ellipse::setSemiMajor(Point major) {
    semi_major = major;
}






Point Ellipse::getSemiMajor() const{
    return semi_major;
}






void Ellipse::setSemiMinor(Point minor) {
    semi_minor = minor;
}






Point Ellipse::getSemiMinor() const {
    return semi_minor;
}






/*
area
Calculate the area of the ellipse
*/

float Ellipse::area() const {
    float major_length, minor_length;
    major_length = semi_major.distance(center);
    minor_length = semi_minor.distance(center);
    return M_PI * major_length * minor_length;
}






/*
perimeter
calculate the are of the perimeter
*/

float Ellipse::perimeter() const {
    float h, c_1, c_2, major_length, minor_length;
    major_length = semi_major.distance(center);
    minor_length = semi_minor.distance(center);
    h = pow(major_length - minor_length, 2) / pow(major_length + minor_length, 2);
    c_1 = M_PI * (major_length + minor_length);
    c_2 = (3 * h)/(10 + (pow(4 - (3 * h), -0.5)));
    return c_1 * (1 + c_2);
}