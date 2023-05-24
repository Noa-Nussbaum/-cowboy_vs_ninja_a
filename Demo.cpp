/**
 * Demo file for the exercise on binary tree
 *
 * @author Evgeny Hershkovitch Neiterman
 * @since 2023-03
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
using namespace std;

#include "sources/Team.hpp" //no need for other includes

using namespace ariel;


int main() {
    Point a(32.3,44),b(1.3,3.5);
    
    // assert(a.distance(b) == b.distance(a));
    Cowboy *tom = new Cowboy("Tom", a);
    OldNinja *sushi = new OldNinja("sushi", b);
    YoungNinja *young=new YoungNinja("Yogi", Point(64,57));
    double m = tom->distance(sushi);
    // cout << "tom and sushi " << std::to_string(m)<< endl;

    tom->shoot(sushi);

   sushi->move(tom);
   // cout << "did it crash" <<endl;
   tom->shoot(sushi);
   // cout << "did it crash" <<endl;
   Cowboy cowboy{"Clint", Point{0, 0}}; 

  //  cout << cowboy.getName()<<endl;

    Team team_A(tom); 
    team_A.add(new YoungNinja("Yogi", Point(64,57)));
    // cout << team_A.stillAlive()<< endl;
   //  cout << "This many are alive:"<<team_A.stillAlive() << endl;
    
   //  team_A.print();

   //  Team b(tom); should throw tom is already in team a

     Team team_B(sushi);
     
   //   team_B.add(new TrainedNinja("Hikari", Point(12,81)));

    cout << "A still alive 1" <<team_A.stillAlive() << endl;
    cout << "B still alive" <<team_B.stillAlive() << endl;
     while(team_A.stillAlive() > 0 && team_B.stillAlive() > 0){
        team_A.attack(&team_B);
        cout << "A still alive 2" <<team_A.stillAlive() << endl;
        team_B.attack(&team_A);
        cout << "A still alive 3" <<team_A.stillAlive() << endl;
        cout << "B still alive" <<team_B.stillAlive() << endl;
        team_A.print();
        team_B.print();
     }
   //   cout << "2 still good" << endl;
      cout << team_A.stillAlive() << endl;
     if (team_A.stillAlive() > 0) cout << "winner is team_A" << endl;
     else cout << "winner is team_B" << endl;
   
     cout << "3 still good" << endl;
     return 0; // no memory issues. Team should free the memory of its members. both a and b teams are on the stack. 

}
