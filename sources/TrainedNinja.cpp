#include "TrainedNinja.hpp"

using namespace std;

namespace ariel{

    TrainedNinja::TrainedNinja(const string &name,const Point &location): Ninja(name, 120, location,12){}
    TrainedNinja::TrainedNinja(TrainedNinja& other): Ninja(other){}


}