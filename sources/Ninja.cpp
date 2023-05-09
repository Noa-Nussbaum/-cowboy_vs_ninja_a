#pragma once
#include "Character.hpp"

using namespace std;

namespace ariel{

    class Ninja : public Character{
        Ninja::Ninja(string name, Point location){}
        Ninja::Ninja(){}
        void Ninja::move(Character &other){}
        void Ninja::slash(Character &other){}
    };
}