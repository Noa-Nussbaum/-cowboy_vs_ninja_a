#pragma once
#include "Character.hpp"
#include "Ninja.hpp"

using namespace std;

namespace ariel{

    class TrainedNinja : public Ninja{

        TrainedNinja(string name, Point location){
            this->speed = 12;
            this->hits = 120;
        }

    };
}