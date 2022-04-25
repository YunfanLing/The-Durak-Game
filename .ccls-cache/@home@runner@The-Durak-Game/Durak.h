#include"Cards.h"
#include"InitialHand.h"

class Trump
{
public:
  void setDuarkCard(Cards AfterShuffle,int cardCount);
  vector<tuple<string,string,int>> getDurakCard(){return TheCard;}
  int firstTurn(vector<InitialHand>Players);
private:
  vector<tuple<string,string,int>>TheCard;
};

void Durak::setDuarkCard(Cards AfterShuffle,int cardCount)
{
  TheCard.emplace_back(AfterShuffle.mv[cardCount]);
}

int Durak::firstTurn(vector<InitialHand>Players)
{
  int playerName;
  //If one of the player ha
  return playerName;
}