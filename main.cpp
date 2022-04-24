#include <iostream>
#include <map>
#include <string>
#include "Cards.h"
#include "Player.h"
#include "InitialHand.h"
#include <algorithm>
#include <random>
using namespace std;

void playersNumber();
void shuffleCards(Cards cards);
void deal(InitialHand Player,Cards cards,int i);

int main() 
{
  Cards AfterShuffle;
  AfterShuffle.shuffleCards();
  playersNumber();


  InitialHand Player1,Player2,Player3,Player4,Player5,Player6;

  //Initial hand.
  //for(int i=0;i<Number.playersNumber;i++)
  /*cout<<"Initial cards for Player1\n";
  deal(Player1,cards,1);
  cout<<"Initial cards for Player2\n";
  deal(Player2,cards,2);
  cout<<"Initial cards for Player3\n";
  deal(Player3,cards,3);
  cout<<"Initial cards for Player4\n";
  deal(Player4,cards,4);
  cout<<"Initial cards for Player5\n";
  deal(Player5,cards,5);
  cout<<"Initial cards for Player6\n";
  deal(Player6,cards,6);*/
  
  return 0;
}

void playersNumber()
{
  int playersNumber;
  do 
  {
    cout<<"Please enter the number of the players(Between 2 to 6)\n";
    cin>>playersNumber;    
    if(playersNumber<2||playersNumber>6)
      cout<<"Illegal number please enter again\n";
  }while(playersNumber<2||playersNumber>6);
  const int NUMBER_OF_PLAYERS=playersNumber;
}
void deal(InitialHand Player,Cards cards,int i)
{
  for(int j=0+6*(i-1);j<6+6*(i-1);j++)
    Player.mv.push_back(cards.mv[j]);  
  Player.output();
}