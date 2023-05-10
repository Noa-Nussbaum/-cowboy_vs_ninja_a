#pragma once
#include "Ninja.hpp"

using namespace std;

namespace ariel{

    class YoungNinja : public Ninja {
    public:
        int speed; 
        int hits;
        YoungNinja(string name, Point location);
};

}

