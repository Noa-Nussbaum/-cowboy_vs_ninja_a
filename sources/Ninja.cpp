#include "Ninja.hpp"
#include "Character.hpp"


using namespace std;

namespace ariel{

    Ninja::Ninja(const string &name, int hits,const Point &location, int speed):Character(name,hits,location), speed(speed){
        // For my convenience
        setType(2);
    }
    
    void Ninja::move(Character* other){
        if(other->isAlive()){
            setLocation(getLocation().moveTowards(getLocation(),other->getLocation(),speed));
        }
    }

    void Ninja::slash(Character* other){
        if(!this->isAlive() || !other->isAlive()){
            throw runtime_error("Attacker/ attacked is already dead");
        }
        if(other==this){
            throw runtime_error("Self harm is not allowed here. Go see a therapist");
        }
        double distance = this->distance(other);
        if(this->isAlive() && distance <1){
            other->hit(40);
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

