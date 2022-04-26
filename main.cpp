#include <iostream>
#include <map>
#include <string>
#include <tuple> 
#include "Trump.h"
using namespace std;

int playersNumber();
InitialHand firstDeal(Cards cards,int i);

int hasTrumpSuit(int i,vector<tuple<string,string,int>>mv,string trumpSuit);
int whoAttackFirst(vector<InitialHand>Players,vector<tuple<string,string,int>>TheTrumpCard);
int cardCount=0;

int main() 
{
  Cards AfterShuffle;
  AfterShuffle.shuffleCards();
  //AfterShuffle.output();
  const int NUMBER_OF_PLAYERS=playersNumber();

  //InitialHand Hand;
  vector<InitialHand>Players;
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
  cout<<"The trump card is\n";
  cout<<get<0>(TrumpCard.getTrumpCard()[0])<<' '<<get<1>(TrumpCard.getTrumpCard()[0])<<endl;

  cout<<whoAttackFirst(Players,TrumpCard.getTrumpCard())<<endl;
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

//Who first attack
//bool hasTrumpSuit(int i,vector<tuple<string,string,int>>mv,string trumpSuit);
int whoAttackFirst(vector<InitialHand>Players,vector<tuple<string,string,int>>TheTrumpCard)
{
  string trumpSuit=get<0>(TheTrumpCard[0]);
  int playerName;
  vector<int>playerHasTrumpSuit;
  //Check whether Player has trump suit
  for(int i=0;i<Players.size();i++)
  {
    playerHasTrumpSuit.push_back(hasTrumpSuit(i,Players[i].mv,trumpSuit));
  }
  bool noneTrump; 
  for(int i=0;i<playerHasTrumpSuit.size();i++)
  {
    cout<<"Player"<<playerHasTrumpSuit[i]<<endl;
    if(playerHasTrumpSuit[i]==1)
      noneTrump=0;
  }  
    
  //If none of the player has trump suit then Player1 start the game
  if(noneTrump==1)
  {
    playerName=1;
    cout<<"Player"<<playerName<<" start the game\n";
  }
  else
  {
    vector<tuple<string,string,int>>lowestTrumpCard;
    lowestTrumpCard.emplace_back(trumpSuit,"A",14);
    for(int i=0;i<playerHasTrumpSuit.size();i++)
      if(playerHasTrumpSuit[i]==1)
      {
        for(int j=0;j<Players[i].mv.size();j++)
          if(get<0>(Players[i].mv[j])==trumpSuit)
            if(get<2>(Players[i].mv[j])<get<2>(lowestTrumpCard[0]))
            {
              lowestTrumpCard[0]=Players[i].mv[j];
              playerName=i+1;
            }                     
      }
  } 
  return playerName;
}

int hasTrumpSuit(int i,vector<tuple<string,string,int>>mv,string trumpSuit)
{
  int hasTrumpSuit=0;
  for(int j=0;j<mv.size();j++)
    if(get<0>(mv[j])==trumpSuit)
      hasTrumpSuit=1;
  return hasTrumpSuit;
}
