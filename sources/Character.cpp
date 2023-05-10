#include "Character.hpp"

namespace ariel{

    Character::Character(string name, Point location){
        this->location = location;
        this->name = name;
    }
    Character::Character(): name("Noa"), location(Point()){}

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
    string Character::print(){
        return "Noa";
    }


};