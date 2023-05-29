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

            Character* leader;
            vector<Character*> team;

        public:
            Team(Character* leader);
            virtual void add(Character* other);
            virtual void attack( Team* other);
            int stillAlive() ;
            void print();
            virtual ~Team();
            void setLeader(Character* newLeader);
            // Character* findVictim(const Team* other);
            Character* findNearest(const Character* leader) const ;
            static bool compare(Character *one, Character *two);
            int teamSize();
            vector<Character *> &getTeam();

    };

}