#include "Point.hpp"

namespace amit{
    Point::Point(double xCordinate, double yCordinate):_x(xCordinate),_y(yCordinate){}
    double Point::distance(const Point& other) const{
        return sqrt(pow(this->_x-other.getX(),2)+pow(this->_y-other.getY(),2));
    }
    std::string Point::print() const {
        return "("+ std::to_string(_x)+","+ std::to_string(_y) + ")";
    }
    double Point::getX() const {return _x;}
    double Point::getY() const {return _y;}
}