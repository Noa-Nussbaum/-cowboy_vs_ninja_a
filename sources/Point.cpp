#include "Point.hpp"

namespace ariel{

    Point::Point(const double& x, const double& y){
        this->x = x;
        this->y = y;
    }

    // Default constructor
    Point::Point(): x(0),y(0){}

    double Point::distance(Point other){
        return 0;
    }

    void Point::print(){
        cout << "Legendary" << endl;
    }

    Point Point::moveTowards(Point source, Point destination, double distance){
        return Point();
    }

}