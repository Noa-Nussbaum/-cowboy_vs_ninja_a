#pragma once
#include "Ninja.hpp"

using namespace std;

namespace ariel{

    class TrainedNinja : public Ninja {
        
    public:

        TrainedNinja(const string &name,const Point &location);
        TrainedNinja(TrainedNinja& other);

};

}

