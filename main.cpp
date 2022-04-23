#include <iostream>
#include <map>
#include <string>
#include "Cards.h"
#include "Player.h"
#include "InitialHand.h"
#include <algorithm>
#include <random>
using namespace std;

int main() 
{
  Cards cards;
  cards.setCardsSuit();
  cards.setCardsValue();
  cards.setCards();
  cards.output();
  srand(unsigned(time(NULL)));
  random_shuffle(cards.mv.begin(), cards.mv.end());
  cards.output();

  Player Number;
  Number.setPlayersNumber();
  cout << Number.playersNumber<<endl;

  InitialHand Player1,Player2,Player3,Player4,Player5,Player6;

  //Initial hand.
  //for(int i=0;i<Number.playersNumber;i++)
  for(int j=0;j<6;j++)
      Player1.mv.push_back(cards.mv[j]);  
  Player1.output();
  
  return 0;
}