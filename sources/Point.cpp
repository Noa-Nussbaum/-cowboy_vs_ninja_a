#include "Point.hpp"
#include <stdexcept>
#include <cmath>

namespace ariel{

    Point::Point(const double& x, const double& y){
        this->x = x;
        this->y = y;
    }

    // Default constructor
    Point::Point(): x(0),y(0){}

    double Point::distance(const Point& other) const{
        double distance = sqrt(pow(x-other.x,2)+pow(y-other.y,2));
        return distance;
    }

    void Point::print(){
        cout << "("<< this->getX()<<","<< this->getY()<<")" << endl;
    }
    string Point::printString(){
        string answer = "("+std::to_string(this->getX())+","+ std::to_string(this->getY())+")";
        return answer; 
    }

    Point Point::moveTowards(Point source, Point destination, double distance){
        if(distance<0){
            throw std::invalid_argument("Given distance is smaller than 0");
        }
        double length = source.distance(destination);
        if(length<=distance){
            return destination;
        }
        double ratio = distance / length;
        double dx = destination.getX() - source.getX();
        double dy = destination.getY() - source.getY();

        return Point(source.getX() + ratio * dx, source.getY() + ratio * dy);

    }
    double Point::getX(){
        return this->x;
    }

    double Point::getY(){
        return this->y;
    }
    bool Point::operator==(const Point& other) const{
        return (x == other.x && y == other.y);
    }

}