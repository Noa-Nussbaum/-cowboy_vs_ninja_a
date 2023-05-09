#pragma once
#include "Character.hpp"

using namespace std;

namespace ariel{

    class Cowboy : public Character{
        int bullets;

    public:
        Cowboy(string name, Point location);
        void shoot(Character &other);
        bool hasBoolets();
        void reload();

};
}