#include "Team.hpp"
#include "Character.hpp"
#include <iostream>
#include <limits>


using namespace std;

namespace ariel{

    Team::Team(Character* leader):leader(leader){
        this->add(leader);
    }
    void Team::add(Character* other){
        if(other->getInTeam()==1){
            throw runtime_error("Character was already in team");
        }
        else{
            if(team.size()<10){
                // If cowboy insert at front
                if(other->type()==1){
                    team.insert(team.begin(), other);
                }
                // If ninja insert at end
                else if(other->type()==2){
                    team.push_back(other);
                }
                other->setInTeam();
            }
            else{
                throw runtime_error("There's already 10 team members");
            }
        }
    }
    void Team::setLeader(Character* newLeader){
        this->leader = newLeader;
    }

    void Team::attack(const Team* other){
        if(other == nullptr){
            throw invalid_argument("Enemy is null");
        }
        if(other->stillAlive()==0){
            throw runtime_error("Enemy is all dead");
        }
        if(!leader->isAlive()){
            double closest = numeric_limits<double>::infinity();
            int position = -1;
            for(int i=0; i<team.size(); i++){
                if(team.at(i)==leader){
                    continue;
                }
                if(team.at(i)->distance(leader)<closest){
                    closest = team.at(i)->distance(leader);
                    position = i;
                }
            }
            leader=team.at(position);
        }
    }

    int Team::stillAlive() const{
        int answer=0;
        for(int i=0; i<team.size();i++){
            if(team.at(i)->isAlive()){
                answer++;
            }
        }
        return answer;
    }
    void Team::print(){
        for(int i=0; i<team.size(); i++){
            cout << team.at(i)->print() << endl;
        }
    }

    Team::~Team(){   
        for(vector<Character*>::iterator member=team.begin(); member != team.end(); member++) {
                delete *member;       
            }
    }



}