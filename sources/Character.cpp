#include "Character.hpp"

namespace ariel{

    Character::Character(Point location, int hits, string name){
        this->location = location;
        this->hits = hits;
        this->name = name;
    }
    Character::Character(): location(Point()), hits(0), name("Noa"){}

    bool Character::isAlive(){
        return true;
    }
    double Character::distance(Character &other){
        return 0;
    }
    void Character::hit(int hits){

    }
    string Character::getName(){
        return this->name;
    }
    Point Character::getLocation(){
        return this->location;
    }
    void Character::print(){
        
    }


};