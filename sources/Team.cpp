#include "Team.hpp"
#include "Character.hpp"
#include <iostream>
#include <limits>

using namespace std;

namespace ariel{

    Team::Team(Character* leader){
        if(leader->getInTeam()==1){
            throw std::runtime_error("Team leader already a different team leader");
        }
        this->leader = leader;
        leader->setInTeam();
        team.push_back(leader);
    }

    bool Team::compare(Character *one, Character *two){
        return (one->getType()==1 && two->getType()==2);
    }

    void Team::add(Character* other){
        if (other->getInTeam()==1){
            throw runtime_error("Character was already in team");
        }
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
        this->leader = newLeader;
        newLeader->setInTeam();
    }

    Character* Team::findVictim(const Character* leader) const {
        double minDistance = std::numeric_limits<double>::max();
        Character* victim = nullptr;
        for (Character* member : team) {
            if (member->isAlive() && member != leader) {
                double distance = member->distance(leader);
                if (distance < minDistance) {
                    minDistance = distance;
                    victim = member;
                }
            }
        }
        return victim;
    }

    void Team::attack(Team* other){
        if (other == nullptr || leader == nullptr){
            throw invalid_argument("Enemy is null");
            return;
        }
        if (other->stillAlive() == 0){
            throw runtime_error("Enemy team is all dead");
        }
        // If team leader is dead - replace them
        if (!leader->isAlive()){
            
            leader = this->findVictim(this->leader);
            if(leader == nullptr){
                return;
        }
            
        }
        
        Character* victim = other->findVictim(leader);
        if(victim == nullptr){
            return;
        }

        // All attack victim
        for (std::vector<Character*>::size_type i = 0; i < team.size(); i++){
            if (team.at(i)->isAlive()){
                if (!victim->isAlive()){
                    victim = other->findVictim(leader);
                    if (victim == nullptr){
                        return;
                    }
                }
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
        //remove all the characters from the team
        for (auto &i: this->team) {
            delete i;
        }
    }

    int Team::teamSize(){
        return team.size();
    }
   
    vector<Character *> &Team::getTeam() {
        return team;
    }


}
