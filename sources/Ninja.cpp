#include "Ninja.hpp"
#include "Character.hpp"


using namespace std;

namespace ariel{

    // Ninja::Ninja(string name, Point location) : Character(name, location){
    //     // initialize any Ninja-specific member variables here
    // }

    // Ninja::Ninja(){
    //     // initialize any Ninja-specific member variables here
    // }

    Ninja::Ninja(const string &name, int hits,const Point &location, int speed):Character(name,hits,location), speed(speed){
        setType(2);
    }
    
    Ninja::Ninja(Ninja& other):Character(other), speed(other.speed){
        setType(2);
    }

    void Ninja::move(Character* other){
        if(other->isAlive()){
            setLocation(getLocation().moveTowards(getLocation(),other->getLocation(),speed));
            cout << "did move work?" <<endl;
        }
    }

    void Ninja::slash(Character* other){
        double distance = this->distance(other);
        if(this->isAlive() && distance <1){
            other->hit(31);
        }
    }

    string Ninja::print(){
        if(!this->isAlive()){
            return "N Name: ("+this->getName()+") , Location: "+this->getLocation().printString();
        }
        return "N Name: "+this->getName()+", Hits: "+std::to_string(this->getHits())+", Location: "+this->getLocation().printString();

    }
    int Ninja::getSpeed() const{
        return speed;
    }

    

}

