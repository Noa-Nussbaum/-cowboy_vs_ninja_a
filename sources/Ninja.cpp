#include "Ninja.hpp"


using namespace std;

namespace ariel{

    Ninja::Ninja(string name, Point location) : Character(name, location){
        // initialize any Ninja-specific member variables here
    }

    Ninja::Ninja(){
        // initialize any Ninja-specific member variables here
    }

    void Ninja::move(Character* other){
        // implementation of move function
    }

    void Ninja::slash(Character* other){
        // implementation of slash function
    }
}

