#include "Character.hpp"

namespace ariel{

    // Character::Character(string name, Point location){
    //     this->location = location;
    //     this->name = name;
    // }
    Character::Character(string name,int hits,Point location):name(name),location(location),hits(hits){
    }
    Character::Character(): name("Noa"), location(Point()){}
    Character::Character(Character &other) : name(other.name), location(other.location), hits(other.hits) {
}


    bool Character::isAlive() const{
        return hits>0;
    }
    double Character::distance(const Character* other) const{
        return other->distance(this);
    }
    void Character::hit(int hits){
        this->hits =-hits;
    }
    string Character::getName(){
        return this->name;
    }
    Point Character::getLocation(){
        return this->location;
    }
    string Character::print(){
        return "Name: "+this->getName()+", Hits: "+std::to_string(this->hits)+", Location: "+this->getLocation().printString();
    }
    int Character::getHits() const{
        return hits;
    }
    void Character::setLocation(Point other){
        location=other;
    }
    
    Point Character::getLocation() const{
        return location;
    }
    


};