#pragma once
#include <stdio.h>
#include "Point.hpp"
#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "Team.hpp"
#include <vector>
#include <algorithm>

using namespace std;

namespace ariel{

    class Team2 : public Team{

        private:
            Character* leader;
            vector<Character*> team;

        public:
            Team2(Character* leader);
            void add(Character* other);
            // void attack(const Team2* other);
            // int stillAlive() const;
            // void print();
            // ~Team2();
            // void setLeader(Character* newLeader);
            // Character* findVictim(const Team2* other);

    };

}