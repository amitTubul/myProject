#pragma once
#include <iostream>
#include <stdio.h>
#include <cmath>

namespace amit{

    class Point{
    private:
        double _x,_y;

    public:
        Point(double xCordinate, double yCordinate);// constructor
        double distance(const Point& other) const;// distance between 2 points
        std::string print() const;// print the coordinates
        double getX() const;
        double getY() const;
    };

}