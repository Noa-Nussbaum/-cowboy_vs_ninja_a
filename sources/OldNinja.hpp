#pragma once
#include "Ninja.hpp"

using namespace std;

namespace ariel{

    class OldNinja : public Ninja {
    public:
        int speed; 
        int hits;
        OldNinja(string name, Point location);
};

}

