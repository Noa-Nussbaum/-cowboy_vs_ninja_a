#include "YoungNinja.hpp"

using namespace std;

namespace ariel{

        
        YoungNinja::YoungNinja(const string &name,const Point &location): Ninja(name, 100, location,14){}
        YoungNinja::YoungNinja(YoungNinja& other): Ninja(other){}


}