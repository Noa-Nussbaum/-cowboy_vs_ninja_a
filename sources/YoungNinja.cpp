#include "YoungNinja.hpp"

using namespace std;

namespace ariel{

        YoungNinja::YoungNinja(const string name, Point location): Ninja(name, location){
            this->speed = 14;
            this->hits = 100;
        }


}