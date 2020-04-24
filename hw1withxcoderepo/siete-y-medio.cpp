#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "cards.h"
using namespace std;

void print_new(Card new_card)
{
    cout<< "New card:\n\t\t"
    << new_card.get_spanish_rank() << " de "<< new_card.get_spanish_suit()
    << "\t(" << new_card.get_english_rank() << " of "
    << new_card.get_english_suit()<< ")\n";
}

int main(){
    Player person(100); //initialize person with $100
    Player dealer(900); //initializes dealer with $900
    Hand personhand; //empty card vector
    Hand dealerhand; //empty card vector
    int bet;
    char choice = 'y';
    while(person.get_money()>0 && dealer.get_money()>0 ){
        cout<<"You have $"<< person.get_money() << ". Enter bet: ";
        cin>>bet;
        if(bet > person.get_money()){
            cout<< "You don't have that much. Enter bet: ";
            cin>>bet;
            cout<< endl;
        }
        Card new_card;
        if(personhand.get_total() != 0 )
            print_new(new_card);
        personhand.add_cards(new_card);
        cout<< "Your cards: \n";
        personhand.print_cards();
        while( personhand.get_total()<7.5 && choice == 'y' )
        {
            cout<< "Your total is "<< personhand.get_total() << ". ";
            cout<< "Do you want another card (y/n)? ";
            cin>>choice;
            if(choice == 'y'){
                cout<< "Your cards:\n";
                Card new_card;
                if(personhand.get_total() != 0 )
                    print_new(new_card);
                personhand.add_cards(new_card);
                personhand.print_cards();
                cout<< endl;
            }
            cout<< endl;
        }
        
        while(dealerhand.get_total() < 5.5){
            Card new_card;
            if(dealerhand.get_total() != 0 )
                print_new(new_card);
            dealerhand.add_cards(new_card);
            cout<<"Dealer's cards:\n";
            dealerhand.print_cards();
            cout<< "The dealer's total is " <<dealerhand.get_total() <<".\n\n";
        }
        double dealertotal = dealerhand.get_total();
        double persontotal = personhand.get_total();
        
        if( (dealertotal <= 7.5 && persontotal < dealertotal) || persontotal > 7.5 ){
            cout<< "Too bad. You lose $" << bet;
            person.increase_money(-1*bet);
            dealer.increase_money(bet);
        }
        else if( (persontotal <= 7.5 && dealertotal < persontotal) || dealertotal > 7.5 ){
            cout<< "You win $" << bet <<".\n";
            person.increase_money(bet);
            dealer.increase_money(-1 * bet);
        }
        else
            cout<< "Nobody wins!\n";
        cout<< endl;
        personhand.clear_hand();
        dealerhand.clear_hand();
    }
    if( person.get_money() == 0 )
        cout<< "You have $0. GAME OVER!\n Come back when you have more money.";
    else
        cout<< "You win " << bet<< "\n\nCongratulations. You beat the casino!";
    cout<< "\n\nBye!";
    return 0;
}
