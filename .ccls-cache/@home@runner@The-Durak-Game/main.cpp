#include <iostream>
#include <string>
//#include "Initial/Trump.h"
#include "Deck.h"
using namespace std;

int playersNumber();
Hand firstDeal(Cards cards,int i);
int cardCount=0;

int main() 
{
  Cards AfterShuffle;
  AfterShuffle.shuffleCards();
  //AfterShuffle.output();
  const int NUMBER_OF_PLAYERS=playersNumber();

  //InitialHand Hand;
  vector<Hand>Players;
  for(int i=0;i<NUMBER_OF_PLAYERS;i++)
  {
    cout<<"Hand of Player"<<i+1<<" after first deal\n";
    Players.push_back(firstDeal(AfterShuffle,i+1));
    Players[i].output();
  }
  cout<<cardCount<<endl;
  //Get Durak card;
  Trump TrumpCard;
  TrumpCard.setTrumpCard(AfterShuffle,cardCount);
  cout<<"\n\nThe trump card is\n";
  
  TrumpCard.output();
  
  int playerAttackFirst=TrumpCard.whoAttackFirst(Players);
  cout<<playerAttackFirst<<endl;
  Deck OnDeck;
  OnDeck.attack(playerAttackFirst,Players);
  
  return 0;
}

int playersNumber()
{
  int playersNumber;
  do 
  {
    cout<<"Please enter the number of the players(Between 2 to 6)\n";
    cin>>playersNumber;    
    if(playersNumber<2||playersNumber>6)
      cout<<"Illegal number please enter again\n";
  }while(playersNumber<2||playersNumber>6);
  return playersNumber;
}

Hand firstDeal(Cards Cards,int i)
{
  Hand Result;
  for(int j=0+6*(i-1);j<6+6*(i-1);j++)
  {
    Result.mv.push_back(Cards.mv[j]);
    cardCount++;
  }
  return Result;
}


