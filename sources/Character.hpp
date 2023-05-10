#pragma once
#include <stdio.h>
#include "Point.hpp"

using namespace std;

namespace ariel{

    class Character{


        Point location;
        string name;
        int hits;

        public:
            Character(string name, Point location);
            Character();
            bool isAlive();
            double distance(Character &other);
            void hit(int hits);
            string getName();
            Point getLocation();
            string print();
            

    };
}
