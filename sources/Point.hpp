#pragma once
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

using namespace std;

namespace ariel{

class Point{

    public:
        Point(const double& x, const double& y);
        Point();
        double distance(const Point& other)const;
        void print();
        string printString();
        static Point moveTowards(Point source, Point destination, double distance);
        double getX();
        double getY();
        bool operator==(const Point& other) const;



    private:
        double x;
        double y;


};


}