#include "Cowboy.hpp"
#include "Character.hpp"
using namespace std;

namespace ariel{


    Cowboy::Cowboy(const string &name, const Point &location):Character(name, 110,location),bullets(6){}
    
    Cowboy::Cowboy(Cowboy& other):Character(other), bullets(other.bullets){}
    
    void Cowboy::shoot( Character* other){
        if(this->isAlive() && this->bullets>0){
            other->hit(10);
            this->bullets-=1;
        }
    }
    
    bool Cowboy::hasboolets(){
        return this->bullets>0;
    }
    void Cowboy::reload(){
        this->bullets=6;
    }
    string Cowboy::print(){
        if(!this->isAlive()){
            return "C Name: ("+this->getName()+") , Location: "+this->getLocation().printString();
        }
        return "C Name: "+this->getName()+", Hits: "+std::to_string(this->getHits())+", Location: "+this->getLocation().printString();

    }

    int Cowboy::type() const{
        return 1;
    }



}
