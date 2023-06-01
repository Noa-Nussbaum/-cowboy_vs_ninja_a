#include "SmartTeam.hpp"
#include "Character.hpp"
#include <iostream>
#include <limits>


using namespace std;

namespace ariel{

    SmartTeam::SmartTeam(Character* leader):Team(leader){
    }
    bool SmartTeam::compare(Character *one, Character *two){
        // Comparator for sorting the charactor vector in right order
        // According to number of hits
        return (one->getHits()<=two->getHits());
    }
    
    void SmartTeam::add(Character* other){
        // Similar to regular team adding function but here we add as they come
        if(other->getInTeam()){
            throw runtime_error("Character was already in team");
        }
        // Make sure team isn't full
        else if(teamSize()<10){
                // Let's add teammates according to how 'easy' it is to kill them
                // Aka the number of hits they get before they di
                getTeam().push_back(other);
                stable_sort(getTeam().begin(),getTeam().end(),compare);
                other->setInTeam();
            }
            else{
                throw runtime_error("There's already 10 team members");
            }
    }


}