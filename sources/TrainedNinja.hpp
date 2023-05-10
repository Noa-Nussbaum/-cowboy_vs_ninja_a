#pragma once
#include "Ninja.hpp"

using namespace std;

namespace ariel{

    class TrainedNinja : public Ninja {
    public:
        int speed; 
        int hits;
        TrainedNinja(string name, Point location);
};

}

