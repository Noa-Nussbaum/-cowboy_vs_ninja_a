#include "Character.hpp"

namespace ariel{

    Character::Character(string name,int hits,Point location):name(name),location(location),hits(hits),inTeam(0){}
    Character::Character(): name("Noa"), location(Point()),inTeam(0),hits(0){
        inTeam=0;
    }
    Character::Character(Character &other) : name(other.name), location(other.location), hits(other.hits), inTeam(0) {}

    bool Character::isAlive() const{
        if(hits>0){
            return true;
        }
        return false;
    }
    double Character::distance(const Character* other) const{
        return other->distance(this);
    }
    void Character::hit(int number){
        this->hits -=number;
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
    void Character::setInTeam(){
        this->inTeam=1;
    }
    int Character::getInTeam(){
        return inTeam;
    }

    int Character::getType(){
        return type;
    }

    void Character::setType(int number){
        this->type=number;
    }


};