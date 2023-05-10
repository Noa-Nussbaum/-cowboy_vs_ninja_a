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
        double distance(Point other);
        void print();
        Point moveTowards(Point source, Point destination, double distance);
        double getX();
        double getY();



    private:
        double x;
        double y;


};


}