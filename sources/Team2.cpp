#include "Team2.hpp"
#include "Character.hpp"
#include <iostream>
#include <limits>


using namespace std;

namespace ariel{

    Team2::Team2(Character* leader):leader(leader){
        this->add(leader);
    }
    void Team2::add(Character* other){
        if(other->getInTeam()==1){
            throw runtime_error("Character was already in team");
        }
        else if(team.size()<10){
                // If cowboy insert at front
                if(other->getType()==1){
                    team.insert(team.begin(), other);

                }
                // If ninja insert at end
                else if(other->getType()==2){
                    team.push_back(other);
                }
                other->setInTeam();
            }
            else{
                throw runtime_error("There's already 10 team members");
            }
    }
    void Team2::setLeader(Character* newLeader){
        this->leader = newLeader;
    }

    Character* Team2::findVictim(const Team2* other){
    // Find victim
    double closest = numeric_limits<double>::infinity();
    std::vector<Character*>::size_type position = std::numeric_limits<std::vector<Character*>::size_type>::max();
    for(std::vector<Character*>::size_type i = 0; i < other->team.size(); i++){
        if(other->team.at(i)->distance(leader) < closest && other->team.at(i)->isAlive()){
            closest = other->team.at(i)->distance(leader);
            position = i;
        }
    }
    if (position != std::numeric_limits<std::vector<Character*>::size_type>::max()) {
        return other->team.at(position);
    }
        return nullptr;
    }

    void Team2::attack(const Team2* other){
        if (other == nullptr){
            throw invalid_argument("Enemy is null");
        }
        if (other->stillAlive() == 0){
            throw runtime_error("Enemy team is all dead");
        }
        if (this->stillAlive() == 0){
            throw runtime_error("Team is all dead");
        }
        // If team leader is dead - replace them
        if (!leader->isAlive()){
            double closest = numeric_limits<double>::infinity();
            std::vector<Character*>::size_type position = std::numeric_limits<std::vector<Character*>::size_type>::max();
            for (std::vector<Character*>::size_type i = 0; i < team.size(); i++){
                if (team.at(i) == leader){
                    continue;
                }
                if (team.at(i)->distance(leader) < closest && team.at(i)->isAlive()){
                    closest = team.at(i)->distance(leader);
                    position = i;
                }
            }
            if (position != std::numeric_limits<std::vector<Character*>::size_type>::max()){
                leader = team.at(position);
            }
        }
        Character* victim = findVictim(other);
        // All attack victim
        for (std::vector<Character*>::size_type i = 0; i < team.size(); i++){
            if (team.at(i)->isAlive()){
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
                if (!victim->isAlive()){
                    victim = findVictim(other);
                    if (victim == nullptr){
                        break;
                    }
                }
            }
        }
}

    int Team2::stillAlive() const{
        int answer = 0;
        for (std::vector<Character*>::size_type i = 0; i < team.size(); i++){
            if (team.at(i)->isAlive()){
                answer++;
            }
        }
        return answer;
    }

    void Team2::print(){
        for (std::vector<Character*>::size_type i = 0; i < team.size(); i++){
            cout << team.at(i)->print() << endl;
        }
    }


    Team2::~Team2(){   
        for(vector<Character*>::iterator member=team.begin(); member != team.end(); member++) {
                delete *member;       
            }
    }



}