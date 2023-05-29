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
        // Euclidean distance formula
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
        // Lots of logic here
        if(distance<0){
            throw std::invalid_argument("Given distance is smaller than 0");
        }
        // Find distance between source and destination
        double length = source.distance(destination);

        // If in the range then return it
        if(length <= distance){
            return destination;
        }
        double relation = distance / length;
        double x = destination.getX() - source.getX();
        double y = destination.getY() - source.getY();

        return Point(source.getX() + relation * x, source.getY() + relation * y);

    }
    double Point::getX(){
        return this->x;
    }

    double Point::getY(){
        return this->y;
    }
    bool Point::operator==(const Point& other) const{
        // Compare each component seperately
        return (x == other.x && y == other.y);
    }

}