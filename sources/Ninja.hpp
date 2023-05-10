#pragma once
#include "Character.hpp"


using namespace std;

namespace ariel{

    class Ninja : public Character{

            int speed;
            int hits;
        public:
            Ninja(string name, Point location);
            Ninja();
            void move(Character* other);
            void slash(Character* other);
    };  
}