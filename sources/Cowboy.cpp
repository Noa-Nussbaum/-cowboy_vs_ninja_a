#include "Cowboy.hpp"
using namespace std;

namespace ariel{


    Cowboy::Cowboy(string name, Point location): Character(name, location){}
    void Cowboy::shoot( Character* other){}
    
    bool Cowboy::hasBoolets(){
        return true;
    }
    void Cowboy::reload(){

    }


}
