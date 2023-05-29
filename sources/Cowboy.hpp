#pragma once
#include "Character.hpp"

using namespace std;

namespace ariel{

    class Cowboy : public Character{
    private:
        int bullets;

    public:
        Cowboy(const string &name, const Point &location);
        Cowboy(Cowboy& other);
        void shoot(Character* other);
        bool hasboolets();
        void reload();
        string print();
 

};
}