#include "point.h"
#include <math.h>
#include <iostream>

// getters and setters

float Point::getX() const {
    return x;
}





void Point::setX(float x_coord) {
    x = x_coord;
}






float Point::getY() const {
    return y;
}






void Point::setY(float y_coord) {
    y = y_coord;
}







/*
distance
calculate the absolute distance between this point and another point
*/

float Point::distance(const Point& other) const {
    float x_diff, y_diff;
    x_diff = x - other.x;
    y_diff = y - other.y;
    return pow(pow(x_diff, 2) + pow(y_diff, 2), 0.5);
}






/*
redirection operator overload
output in form (x, y)
*/

std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}