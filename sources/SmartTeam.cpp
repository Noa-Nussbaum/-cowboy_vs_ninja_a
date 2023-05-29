#include "SmartTeam.hpp"
#include "Character.hpp"
#include <iostream>
#include <limits>


using namespace std;

namespace ariel{

    SmartTeam::SmartTeam(Character* leader):Team(leader){
    }
    
    void SmartTeam::add(Character* other){
        // Similar to regular team adding function but here we add as they come
        if(other->getInTeam()){
            throw runtime_error("Character was already in team");
        }
        // Make sure team isn't full
        else if(teamSize()<10){
                getTeam().push_back(other);
                other->setInTeam();
            }
            else{
                throw runtime_error("There's already 10 team members");
            }
    }


}