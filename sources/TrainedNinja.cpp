#include "TrainedNinja.hpp"

using namespace std;

namespace ariel{


    TrainedNinja::TrainedNinja(const string name, Point location): Ninja(name, location){
        this->speed = 12;
        this->hits = 120;
    }


}