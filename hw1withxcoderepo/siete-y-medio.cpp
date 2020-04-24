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
    Player person(100); //initialize person with $100
    Player dealer(900); //initializes dealer with $900
    Hand personhand; //empty card vector
    Hand dealerhand; //empty card vector
    int bet;
    char choice = 'y';
    bool done = false;
    while(!done)
    {
        cout<<"You have $"<< person.get_money() << ". Enter bet: ";
        cin>>bet;
        if(bet > person.get_money())
        {
            cout<< "You don't have that much. Enter bet: ";
            cin>>bet;
            cout<< endl;
        }
        personhand.add_cards();
        cout<< "Your cards: \n\t\t";
        personhand.print_cards();
        cout<< "Your total is "<< personhand.get_total() << ". ";
        while( personhand.get_total()<7.5 && choice == 'y' )
        {
            cout<< "Do you want another card (y/n)? ";
            cin>>choice;
            if(choice == 'y'){
                personhand.add_cards();
                cout<< "New card:\n";
                personhand.print_cards();
                cout<< "Your new total is "<< personhand.get_total()<< ".";
            }
        }
        dealerhand.add_cards();
        while(dealerhand.get_total() < 5.5)
        {
            dealerhand.add_cards();
        }
        cout<<"Dealer's cards: ";
        dealerhand.print_cards();
        cout<< "The dealer's total is " <<dealerhand.get_total() <<".";
        
        //if(personhand.get_total() > 7.5)
        //if loss, person.increase_money( -1*bet );
        done = true;
    }
    return 0;
}
