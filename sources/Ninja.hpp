#pragma once
#include "Character.hpp"


using namespace std;

namespace ariel{

    class Ninja : public Character{
        private:
            int speed;
            int type() const;
            
        public:
            Ninja();
            Ninja(const string &name, int hits,const Point &location, int speed);
            Ninja(Ninja& other);
            string print();
            int getSpeed() const;
            void move(Character* other);
            void slash(Character* other);
            
    };  
}