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


        public:

            Team2(Character* leader);
            void add(Character* other) override;

            // The rest of the functions already exist in Team, as we are inheritting from it 

    };

}