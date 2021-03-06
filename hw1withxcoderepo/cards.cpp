#include "cards.h"
#include <cstdlib>
#include <iostream>

/*
You might or might not need these two extra libraries
#include <iomanip>
#include <algorithm>
*/



//Default constructor for the Card class.
Card::Card(){
   int r = 1 + rand() % 4;
   switch (r) {
      case 1: suit = OROS; break;
      case 2: suit = COPAS; break;
      case 3: suit = ESPADAS; break;
      case 4: suit = BASTOS; break;
      default: break;
   }

   r = 1 + rand() % 10;
   switch (r) {
      case  1: rank = AS; break;
      case  2: rank = DOS; break;
      case  3: rank = TRES; break;
      case  4: rank = CUATRO; break;
      case  5: rank = CINCO; break;
      case  6: rank = SEIS; break;
      case  7: rank = SIETE; break;
      case  8: rank = SOTA; break;
      case  9: rank = CABALLO; break;
      case 10: rank = REY; break;
      default: break;
   }
}

// Accessor: returns a string with the suit of the card in Spanish
string Card::get_spanish_suit() const {
   string suitName;
   switch (suit) {
      case OROS:
         suitName = "oros";
     break;
      case COPAS:
         suitName = "copas";
     break;
      case ESPADAS:
         suitName = "espadas";
     break;
      case BASTOS:
         suitName = "bastos";
     break;
      default: break;
   }
   return suitName;
}

// Accessor: returns a string with the rank of the card in Spanish
string Card::get_spanish_rank() const {
   string rankName;
   switch (rank) {
      case AS:
         rankName = "As";
     break;
      case DOS:
         rankName = "Dos";
     break;
      case TRES:
         rankName = "Tres";
     break;
      case CUATRO:
         rankName = "Cuatro";
     break;
      case CINCO:
         rankName = "Cinco";
     break;
      case SEIS:
         rankName = "Seis";
     break;
      case SIETE:
         rankName = "Siete";
     break;
      case SOTA:
         rankName = "Sota";
     break;
      case CABALLO:
         rankName = "Caballo";
     break;
      case REY:
         rankName = "Rey";
     break;
      default: break;
   }
   return rankName;
}



// Accessor: returns a string with the suit of the card in English
string Card::get_english_suit() const {
    string suitName;
    switch (suit) {
    case OROS:
        suitName = "Coins";
     break;
    case COPAS:
        suitName = "Cups";
     break;
    case ESPADAS:
        suitName = "Swords";
     break;
    case BASTOS:
        suitName = "Clubs";
     break;
    default: break;
   }
   return suitName;
}

// Accessor: returns a string with the rank of the card in English
string Card::get_english_rank() const {
    string rankName;
    switch (rank) {
        case AS:
            rankName = "Ace";
    break;
        case DOS:
            rankName = "Two";
    break;
        case TRES:
            rankName = "Three";
    break;
        case CUATRO:
            rankName = "Four";
    break;
        case CINCO:
            rankName = "Five";
    break;
        case SEIS:
            rankName = "Six";
    break;
        case SIETE:
            rankName = "Seven";
    break;
        case SOTA:
            rankName = "Jack";
    break;
        case CABALLO:
            rankName = "Knight";
    break;
        case REY:
            rankName = "King";
    break;
        default: break;
   }
   return rankName;
}

// Assigns a numerical value to card based on rank.
// AS=1, DOS=2, ..., SIETE=7, SOTA=10, CABALLO=11, REY=12
int Card::get_rank() const {
   return static_cast<int>(rank) + 1 ;
}

// Comparison operator for cards
// Returns TRUE if card1 < card2
bool Card::operator < (Card card2) const {
   return rank < card2.rank;
}
    
void Hand::add_cards(Card new_card){
    current_cards.push_back(new_card);
}

void Hand::sort_cards(){
    for( int i = 0; i < current_cards.size()-1; i++ ){
        if( current_cards[i+1]<current_cards[i] )
            swap(current_cards[i], current_cards[i+1]);
    }
}

void Hand::print_cards(ostream& out){
    sort_cards(); //probably have to reassign this but
    for( int i = 0; i < current_cards.size(); i++ ){
        out<< "\t\t" << current_cards[i].get_spanish_rank()<< " de "
            << current_cards[i].get_spanish_suit()
            << "\t("<< current_cards[i].get_english_rank()<< " of "
            << current_cards[i].get_english_suit() <<")\n";
    }
}
    
double Hand::get_total(){
    double sum = 0;
    for( int i = 0; i < current_cards.size(); i++ ){
    double addedVal = current_cards[i].get_rank();
        if( addedVal >= 10 )
            addedVal = .5;
        sum += addedVal;
    }
    return sum;
}
    
void Hand::clear_hand(){
    current_cards.clear();
}
    
int Player::get_money() const{
    return money;
}

void Player::increase_money(int amount){
    money += amount;
}
