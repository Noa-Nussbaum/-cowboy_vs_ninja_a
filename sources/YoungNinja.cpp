#pragma once
#include "Character.hpp"
#include "Ninja.hpp"

using namespace std;

namespace ariel{

    class YoungNinja : public Ninja{

        YoungNinja(string name, Point location){
            this->speed = 14;
            this->hits = 100;
        }

    };
}