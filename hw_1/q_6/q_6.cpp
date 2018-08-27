#include "circle.h"
#include "ellipse.h"
#include <iostream>


int main() {
    int x, y, minor, major;
    Circle e;
    std::cout << "Enter x, y and major axis and minor axis of ellipse: ";
    std::cin >> x >> y >> major >> minor;

    e = Circle(x, y, major);
    std::cout << "the area of the ellipse is: " << e.area() << std::endl;
    std::cout << "the perimeter of the ellipse is: " << e.perimeter() << std::endl;
}