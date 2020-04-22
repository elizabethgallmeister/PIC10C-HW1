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


// Non member functions implementations (if any)


// Stub for main
int main(){
   int availableMoney = 100;
   int bet;
   cout<<"working"<<endl;
   bool done = false;
   while(!done)
   {
       cout<<"You have $"<< availableMoney << ". Enter bet: ";
       cin>>bet;
       if(bet > availableMoney)
       {
           cout<< "You don't have that much. Enter bet: ";
           cout<< endl;
       }
       done = true;
   }
   return 0;
}
