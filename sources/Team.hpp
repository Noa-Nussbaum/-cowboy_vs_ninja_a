#pragma once
#include <stdio.h>
#include "Point.hpp"
#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include <vector>
#include <algorithm>

using namespace std;

namespace ariel{

    class Team{

        private:
            Character* leader;
            vector<Character*> team;

        public:
            Team(Character* leader);
            void add(Character* other);
            void attack(const Team* other);
            int stillAlive() const;
            void print();
            ~Team();
            void setLeader(Character* newLeader);
            // Character* findVictim(const Team* other);
            Character* findClosestEnemy(const Character* attacker) const ;

    };

}