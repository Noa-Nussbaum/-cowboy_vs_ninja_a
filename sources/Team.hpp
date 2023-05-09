#pragma once
#include <stdio.h>
#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"

using namespace std;

namespace ariel{

    class Team{

        private:
            Character leader;

        public:
            Team(Character leader);
            Character leader;
            Team();
            void add(Character &other);
            void attack(Team &other);
            bool stillAlive();
            void print();
            ~Team();

    };

}