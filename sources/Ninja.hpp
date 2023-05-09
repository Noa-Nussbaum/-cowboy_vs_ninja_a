#pragma once
#include "Character.hpp"

using namespace std;

namespace ariel{

    class Ninja : public Character{
        

        public:
            Ninja(string name, Point location);
            Ninja();
            void move(Character &other);
            void slash(Character &other);
            int speed;

    };    
}