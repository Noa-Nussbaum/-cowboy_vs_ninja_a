#include "Team.hpp"
#include "Character.hpp"

using namespace std;

namespace ariel{

    Team::Team(Character* leader){}
    void Team::add(Character* other){}
    void Team::attack(const Team* other){}
    bool Team::stillAlive(){
        return true;
    }
    void Team::print(){}

    Team::~Team(){          
    }



}