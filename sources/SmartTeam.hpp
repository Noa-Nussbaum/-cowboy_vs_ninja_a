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

    class SmartTeam : public Team{


        public:

            SmartTeam(Character* leader);
            void add(Character* other) override;
            static bool compare(Character *one, Character *two);


            // The rest of the functions already exist in Team, as we are inheritting from it 

    };

}