#ifndef POINT_H_
#define POINT_H_

#include <iostream>

class Point {
    private:
        float x, y; // the x and y coordinate of the point
    public:
        // default constructor set x and y to 0
        Point(){x = y = 0;};

        // parameterized constructor
        Point(float x_coord, float y_coord) {
            x = x_coord;
            y = y_coord;
        }

        // getters and setters
        float getX() const;
        void setX(float x_coord);
        float getY() const;
        void setY(float y_coord);

        // calculate absolute distance from this to another point
        float distance(const Point&) const;

        // override output operator for printing
        friend std::ostream& operator<<(std::ostream& os, const Point& p);
};

#endif 