#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "cards.h"
using namespace std;

// Global constants (if any)
// Non member functions declarations (if any)
void drawcards(){};
// Non member functions implementations (if any)


// Stub for main
int main(){
    Player* person = new Player(100); //initialize person with $100
    Hand personhand(); //lol is this ok
    Hand dealerhand(); //^^^uhhh
    int bet;
    bool done = false;
    while(!done)
   {
       cout<<"You have $"<< person->get_money() << ". Enter bet: ";
       cin>>bet;
       if(bet > person->get_money())
       {
           cout<< "You don't have that much. Enter bet: ";
           cin>>bet;
           cout<< endl;
       }
       drawcards();
       cout<< "Your cards: \n";
       //cout<< "\t " << get_spanish_rank() << " of " << get_spanish_suit();
       done = true;
   }
   return 0;
}
