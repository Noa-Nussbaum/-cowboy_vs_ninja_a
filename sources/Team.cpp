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
        leader->setInTeam();
        team.push_back(leader);
    }

    void Team::add(Character* other){
        if (other->getInTeam() == 1){
            throw runtime_error("Character was already in team");
        }
        else if (team.size() < 10){
            // If cowboy insert at front
            if (other->getType() == 1){
                team.insert(team.begin(), other);
            }
            // If ninja insert at end
            else if (other->getType() == 2){
                team.push_back(other);
            }
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

    // Character* Team::findVictim(const Team* other){
    //     // Find victim
    //     cout << "In 5" << endl;
    //     double closest = numeric_limits<double>::infinity();
    //     vector<Character*>::size_type position = numeric_limits<vector<Character*>::size_type>::max();
    //     for (vector<Character*>::size_type i = 0; i < other->team.size(); i++){
    //         cout << "In 9" << endl;
    //         if (other->team.at(i)->distance(leader) < closest && other->team.at(i)->isAlive()){
    //             closest = other->team.at(i)->distance(leader);
    //             position = i;
    //             cout << "In 8" << endl;
    //         }
    //     }
    //     cout << "In 6" << endl;
    //     if (position != numeric_limits<std::vector<Character*>::size_type>::max()){
    //         return other->team.at(position);
    //     }
    //     cout << "In 7" << endl;
    //     return nullptr;
    // }

    Character* Team::findClosestEnemy(const Character* attacker) const {
        cout << "im in" << endl;
        double minDistance = std::numeric_limits<double>::max();
        Character* victim = nullptr;
        for (Character* member : team) {
            if (member->isAlive() && member != attacker) {
                cout << "im in 3" << endl;
                double distance = member->distance(attacker);
                cout << "distance " << distance << endl;
                cout << "im in 5" << endl;
                if (distance < minDistance) {
                    minDistance = distance;
                    victim = member;
                    cout << "im in 4" << endl;
                }
            }
        }
        cout << "im in 2" << endl;
        return victim;
    }

    void Team::attack(const Team* other){
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
        // Character* victim = findVictim(other);
        Character* victim = other->findClosestEnemy(leader);

        cout << "In 4" << endl;
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
                    // victim = findVictim(other);
                    victim = other->findClosestEnemy(leader);

                    if (victim == nullptr){
                        break;
                    }
                }
            }
        }
    }

    int Team::stillAlive() const{
        int answer = 0;
        for (std::vector<Character*>::size_type i = 0; i < team.size(); i++){
            if (team.at(i)->isAlive()){
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

    Team::~Team(){
        for (std::vector<Character*>::iterator member = team.begin(); member != team.end(); member++){
            delete *member;
        }
    }

}
