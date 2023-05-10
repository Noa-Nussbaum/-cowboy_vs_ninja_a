#pragma once
#include <stdio.h>
#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"

using namespace std;

namespace ariel{

    class Team{

        public:
            Team(Character*leader);
            Character leader;
            void add(Character* other);
            void attack(const Team* other);
            bool stillAlive();
            void print();
            ~Team();

    };

}