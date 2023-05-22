#include "OldNinja.hpp"

using namespace std;

namespace ariel{

    OldNinja::OldNinja(const string &name,const Point &location): Ninja(name, 150, location,8){}
    OldNinja::OldNinja(OldNinja& other): Ninja(other){}


}

