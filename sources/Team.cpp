#include "Team.hpp"
#include "Character.hpp"
#include <iostream>
#include <limits>

using namespace std;

namespace ariel{

    Team::Team(Character* leader){
        // Make sure leader isn't already in a team
        if(leader->getInTeam()==1){
            throw std::runtime_error("Team leader already a different team leader");
        }
        // Set leader
        this->leader = leader;
        leader->setInTeam();
        team.push_back(leader);
    }

    bool Team::compare(Character *one, Character *two){
        // Comparator for sorting the charactor vector in right order
        // First cowboys then ninjas
        return (one->getType()==1 && two->getType()==2);
    }

    void Team::add(Character* other){
        // Make sure not in a team
        if (other->getInTeam()==1){
            throw runtime_error("Character was already in team");
        }
        // Make sure team isn't full
        else if (team.size() < 10){
            team.push_back(other);
            stable_sort(team.begin(),team.end(),compare);
            other->setInTeam();
        }
        else{
            throw runtime_error("There are already 10 team members");
        }
    }

    void Team::setLeader(Character* newLeader){
        // Set new leader
        this->leader = newLeader;
        newLeader->setInTeam();
    }

    Character* Team::findNearest(const Character* leader) const {
        // Find nearest relevant leader / victim
        double min = std::numeric_limits<double>::max();
        // Initiate
        Character* victim = nullptr;
        for (Character* teammate:team) {
            // Make sure the member is alive and  not the leader
            if (teammate->isAlive() && teammate!=leader) {
                double distance = teammate->distance(leader);                
                if (distance < min) {
                    // Modify to new smallest distance
                    min = distance;
                    // And to new relevant teammate
                    victim = teammate;
                }
            }
        }
        return victim;
    }

    void Team::attack(Team* other){
        // Make sure no null pointers and alive
        if (other == nullptr || leader == nullptr){
            throw invalid_argument("Enemy is null");
            // If these occur then return
            return;
        }
        if (other->stillAlive() == 0){
            throw runtime_error("Enemy team is all dead");
        }
        // If team leader is dead - replace them
        if (!leader->isAlive()){
            
            leader = this->findNearest(this->leader);
            if(leader == nullptr){
                return;
        }

        }
        // Find victim to attack
        Character* victim = other->findNearest(leader);
        if(victim == nullptr){
            return;
        }

        // Every team member attacks the victim
        for (std::vector<Character*>::size_type i = 0; i < team.size(); i++){
            // Make sure team is alive
            if (team.at(i)->isAlive()){
                // If victim is dead then we're done
                if (!victim->isAlive()){
                    victim = other->findNearest(leader);
                    if (victim == nullptr){
                        return;
                    }
                }
                // If cowboy
                if (team.at(i)->getType() == 1){
                    Cowboy* cowboy = dynamic_cast<Cowboy*>(team.at(i));
                    if (cowboy != nullptr){
                        if (cowboy->hasboolets()){
                            cowboy->shoot(victim);                   
                        }
                        else{
                            cowboy->reload();
                        }
                    }
                }
                // If ninja
                else{
                    Ninja* ninja = dynamic_cast<Ninja*>(team.at(i));
                    if (ninja != nullptr){
                        if (ninja->distance(victim) <= 1){
                            ninja->slash(victim);
                        }
                        else{
                            ninja->move(victim);
                        }
                    }
                }
            }
        }
    }

    int Team::stillAlive() {
    
        int answer = 0;

        for (auto &i: this->team) {
            // Iterate and count
            if (i->isAlive()) {
                answer++;
            }
        }
        return answer;
    }

    void Team::print(){
        for (std::vector<Character*>::size_type i = 0; i < team.size(); i++){
            cout << team.at(i)->print() << endl;
        }
    }

    
    Team::~Team() {
        //Remove all the characters from the team
        for (auto &i: this->team) {
            delete i;
        }
    }

    int Team::teamSize(){
        // For in case I may need it
        return team.size();
    }
   
    vector<Character *> &Team::getTeam() {
        // Gives the team
        return team;
    }


}
