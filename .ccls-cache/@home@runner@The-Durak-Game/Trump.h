#include"Cards.h"
#include"InitialHand.h"

class Trump
{
public:
  void setTrumpCard(Cards AfterShuffle,int cardCount);
  vector<tuple<string,string,int>> getTrumpCard(){return TheTrumpCard;}
  //int firstTurn(vector<InitialHand>Players);
private:
  vector<tuple<string,string,int>>TheTrumpCard;
};

void Trump::setTrumpCard(Cards AfterShuffle,int cardCount)
{
  TheTrumpCard.emplace_back(AfterShuffle.mv[cardCount]);
}

/*int Trump::firstTurn(vector<InitialHand>Players)
{
  int playerName;
  //If one of the player ha
  return playerName;
}*/