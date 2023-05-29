#include "Team2.hpp"
#include "Character.hpp"
#include <iostream>
#include <limits>


using namespace std;

namespace ariel{

    Team2::Team2(Character* leader):Team(leader){
    }
    
    void Team2::add(Character* other){
        if(other->getInTeam()){
            throw runtime_error("Character was already in team");
        }
        else if(teamSize()<10){
                
                getTeam().push_back(other);
                
                // }
                other->setInTeam();
            }
            else{
                throw runtime_error("There's already 10 team members");
            }
    }


}