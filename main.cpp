#include <iostream>
#include <map>
#include <string>
#include <tuple> 
#include "Durak.h"
using namespace std;

int playersNumber();
InitialHand firstDeal(Cards cards,int i);
int cardCount=0;
int main() 
{
  Cards AfterShuffle;
  AfterShuffle.shuffleCards();
  //AfterShuffle.output();
  const int NUMBER_OF_PLAYERS=playersNumber();

  //InitialHand Player1,Player2,Player3,Player4,Player5,Player6;
  vector<InitialHand>Players;
  for(int i=0;i<NUMBER_OF_PLAYERS;i++)
  {
    
    cout<<"Hand of Player"<<i+1<<" after first deal\n";
    Players.push_back(firstDeal(AfterShuffle,i+1));
    Players[i].output();
  }
  cout<<cardCount<<endl;
  //Durak card;
  Durak DurakCard;
  DurakCard.setDuarkCard(AfterShuffle,cardCount);
  cout<<get<0>(DurakCard.getDurakCard()[0])<<' '<<get<1>(DurakCard.getDurakCard()[0]);
  //Initial hand.
  //for(int i=0;i<Number.playersNumber;i++)

  
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
InitialHand firstDeal(Cards Cards,int i)
{
  InitialHand Result;
  for(int j=0+6*(i-1);j<6+6*(i-1);j++)
  {
    Result.mv.push_back(Cards.mv[j]);
    cardCount++;
  }
  return Result;
}