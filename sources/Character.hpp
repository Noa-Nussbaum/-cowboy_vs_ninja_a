#pragma once
#include <stdio.h>
#include "Point.hpp"

using namespace std;

namespace ariel{

    class Character{

        private:
        Point location;
        string name;
        int hits;
        int inTeam;

        public:
            Character(string name,int hits,Point location);
            Character(Character &other);
            Character();
            int getHits() const;
            void setLocation(Point other);
            Point getLocation() const;
            bool isAlive() const;
            double distance(const Character* other) const;
            void hit(int hits);
            bool operator==(const Character& other) const;
            Character& operator==(Character&& other) ;
            Character& operator=(const Character& other);   
            string getName();
            Point getLocation();
            virtual string print();
            virtual ~Character() = default;
            int type() const;
            void setInTeam();
            int getInTeam();
            

    };
}
