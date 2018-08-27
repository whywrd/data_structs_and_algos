#include "circle.h"
#include "ellipse.h"
#include "point.h"
#include <iostream>


int main() {
    int x_c, y_c, x_r, y_r;
    Circle e;
    std::cout << "Enter x, y coordinates for center and radius of circle: ";
    std::cin >> x_c >> y_c >> x_r >> y_r;

    e.setCenter(Point(x_c, y_c));
    e.setRadius(Point(x_r, y_r));
    std::cout << "the area of the circle is: " << e.area() << std::endl;
    std::cout << "the perimeter of the circle is: " << e.perimeter() << std::endl;
}