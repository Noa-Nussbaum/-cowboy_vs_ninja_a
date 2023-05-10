#include "doctest.h"
#include "sources/Team.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <stdexcept>

using namespace std;

namespace ariel{
    
    TEST_CASE("Point"){
        Point a(1.3,4.5),b(1.3,3.5),c(6.7,4.5);
        CHECK(a.distance(b) == b.distance(a));
        CHECK(a.distance(c) == c.distance(a));
        CHECK(b.distance(c) == c.distance(b));
    }

    TEST_CASE("Initiation"){
        Point a(1.3,4.5),b(1.3,3.5);
        CHECK_NOTHROW(Cowboy *Yvgeni = new Cowboy("Yvgeni", a));
        
        CHECK_NOTHROW(OldNinja *Amusi = new OldNinja("Amusi", b));
        CHECK_NOTHROW(YoungNinja("Alina", Point(64,57)));
        CHECK_NOTHROW(TrainedNinja("Herut", Point(12,81)));

        Cowboy *Yvgeni = new Cowboy("Yvgeni", a);
        CHECK("Yvgeni"==Yvgeni->getName());
        CHECK_NOTHROW(Team team_A(Yvgeni));

        OldNinja *Amusi = new OldNinja("Amusi", b);
        CHECK("Amusi"==Amusi->getName());
    
    }
    

    TEST_CASE("Team fight"){
        Point a(1.3,4.5),b(1.3,3.5);
        Point c(64,57), d(12,81);
        Cowboy *Yvgeni = new Cowboy("Yvgeni", a);
        Team team_A(Yvgeni);

        OldNinja *Amusi = new OldNinja("Amusi", b);
        Team team_B(Amusi);

        YoungNinja *Alina = new YoungNinja("Alina", c);
        TrainedNinja *Herut = new TrainedNinja("Herut", d);

        CHECK(Yvgeni->isAlive()==true);
        CHECK(Amusi->isAlive()==true);
        CHECK(Alina->isAlive()==true);
        CHECK(Herut->isAlive()==true);

        team_A.add(Alina);
        team_B.add(Herut);

        Yvgeni->shoot(Amusi);
        CHECK(Yvgeni->hasBoolets()==true);

        for(int i=0; i<5; i++){
            Yvgeni->shoot(Amusi);
        }
        CHECK(Yvgeni->hasBoolets()==false);

        Amusi->move(Yvgeni);
        Amusi->slash(Yvgeni);

        while(team_A.stillAlive() > 0 && team_B.stillAlive() > 0){
            team_A.attack(&team_B);
            team_B.attack(&team_A);
        }

    }

}
