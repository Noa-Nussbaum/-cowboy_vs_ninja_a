#pragma once
#include <stdio.h>
#include "Point.hpp"

using namespace std;

namespace ariel{

    class Character{

        Point location;
        string name;
        int hits;
        int inTeam;
        int type;

        public:
            Character(string name,int hits,Point location);
            Character(Character &other);
            int getHits() const;
            void setLocation(Point other);
            Point getLocation() const;
            bool isAlive() const;
            double distance(const Character* other) const;
            void hit(int hits);
            Character& operator==(Character&& other) ;
            Character& operator=(const Character& other);
            bool operator==(const Character& other) const;
            string getName();
            Point getLocation();
            virtual string print();
            virtual ~Character() = default;
            int getType();
            void setType(int number);
            void setInTeam();
            int getInTeam();
            
            

    };
}
