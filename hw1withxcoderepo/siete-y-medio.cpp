#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "cards.h"
using namespace std;

void print_new(Card new_card){
    cout<< "\nNew card:\n\t\t"
    << new_card.get_spanish_rank() << " de "<< new_card.get_spanish_suit()
    << "\t(" << new_card.get_english_rank() << " of "
    << new_card.get_english_suit()<< ")\n\n";
}

int main(){
    srand(time(0));
    ofstream fout;
    fout.open("output.txt");
    fout<<"-----------------------------------------------\n\n";
    int game_number = 1;
    Player person(100); //initialize person with $100
    Player dealer(900); //initializes dealer with $900
    Hand personhand; //empty card vector
    Hand dealerhand; //empty card vector
    int bet;
    char choice;
    while(person.get_money()>0 && dealer.get_money()>0 ){
        cout<<"You have $"<< person.get_money() << ". Enter bet: ";
        cin>>bet;
        if(bet > person.get_money()){
            cout<< "You don't have that much. Enter bet: ";
            cin>>bet;
            cout<< endl;
        }
        fout<< "Game number: " << game_number
            << "\nMoney left: $" << person.get_money()
            << "\nBet: " << bet << "\n\n";
        Card new_card;
        if(personhand.get_total() != 0 )
            print_new(new_card);
        personhand.add_cards(new_card);
        cout<< "Your cards: \n";
        personhand.print_cards(cout);
        choice = 'y';
        while( personhand.get_total()<7.5 && choice == 'y' )
        {
            cout<< "Your total is "<< personhand.get_total() << ". ";
            cout<< "Do you want another card (y/n)? ";
            cin>>choice;
            if(choice == 'y'){
                Card new_card;
                if(personhand.get_total() != 0 )
                    print_new(new_card);
                personhand.add_cards(new_card);
                cout<< "Your cards:\n";
                personhand.print_cards(cout);
                cout<< endl;
            }
            cout<< endl;
            fout<< "Your cards:\n";
            personhand.print_cards(fout);
            fout<< "Your total: " << personhand.get_total() << ".\n\n";
        }
        
        while(dealerhand.get_total() < 5.5){
            Card new_card;
            if(dealerhand.get_total() != 0 )
                print_new(new_card);
            dealerhand.add_cards(new_card);
            cout<<"Dealer's cards:\n";
            dealerhand.print_cards(cout);
            cout<< "The dealer's total is " <<dealerhand.get_total() <<".\n\n";
        }
        double dealertotal = dealerhand.get_total();
        double persontotal = personhand.get_total();
        fout<< "Dealer's cards:\n";
        dealerhand.print_cards(fout);
        fout<< "Dealer's total: " << dealerhand.get_total() << ".\n\n";
        
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
        game_number++;
        fout<<"-----------------------------------------------\n\n";
        personhand.clear_hand();
        dealerhand.clear_hand();
    }
    if( person.get_money() == 0 )
        cout<< "You have $0. GAME OVER!\nCome back when you have more money.";
    else
        cout<< "You win " << bet<< "\n\nCongratulations. You beat the casino!";
    cout<< "\n\nBye!\n";
    fout.close();
    return 0;
}
