#pragma once
#include "Character.hpp"
#include "Ninja.hpp"

using namespace std;

namespace ariel{

    class OldNinja : public Ninja{

        OldNinja(string name, Point location){
            this->speed = 8;
            this->hits = 150;
        }

    };
}