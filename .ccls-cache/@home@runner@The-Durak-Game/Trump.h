#include"Cards.h"
#include"InitialHand.h"

class Trump
{
public:
  void setTrumpCard(Cards AfterShuffle,int cardCount);
  vector<tuple<string,string,int>> getTrumpCard(){return TheTrumpCard;}
  int whoAttackFirst(vector<InitialHand>Players);
  int hasTrumpSuit(int i,vector<tuple<string,string,int>>mv,string trumpSuit);
private:
  vector<tuple<string,string,int>>TheTrumpCard;
};

void Trump::setTrumpCard(Cards AfterShuffle,int cardCount)
{
  TheTrumpCard.emplace_back(AfterShuffle.mv[35]);
}

//Who first attack
//bool hasTrumpSuit(int i,vector<tuple<string,string,int>>mv,string trumpSuit);
int Trump::whoAttackFirst(vector<InitialHand>Players)
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

int Trump::hasTrumpSuit(int i,vector<tuple<string,string,int>>mv,string trumpSuit)
{
  int hasTrumpSuit=0;
  for(int j=0;j<mv.size();j++)
    if(get<0>(mv[j])==trumpSuit)
      hasTrumpSuit=1;
  return hasTrumpSuit;
}