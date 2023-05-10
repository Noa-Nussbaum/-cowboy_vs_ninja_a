#include "OldNinja.hpp"

using namespace std;

namespace ariel{

    OldNinja::OldNinja(string name, Point location) : Ninja(name, location) {
        this->speed = 8;
        this->hits = 150;
    }

}

