#pragma once
#include <stdio.h>
#include "Point.hpp"

using namespace std;

namespace ariel{

    class Character{

        private:
            Point location;
            string name;

        public:
            Character(Point location, int hits, string name);
            Character();
            bool isAlive();
            double distance(Character &other);
            void hit(int hits);
            string getName();
            Point getLocation();
            void print();
            int hits;

    };
}
