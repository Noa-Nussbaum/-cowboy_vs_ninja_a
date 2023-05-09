#include "Team.hpp"
#include "Character.hpp"

using namespace std;

namespace ariel{

    class Team{

        Team::Team(Character leader){
        }
        Team::Team(){}
        void Team::add(Character &other){}
        void Team::attack(Team &other){}
        int Team::stillAlive(){
            return 10;
        }
        void Team::print(){}

        Team::~Team(){          
        }


    };
}