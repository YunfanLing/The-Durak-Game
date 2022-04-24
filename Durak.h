#include"Cards.h"
#include"InitialHand.h"

class Durak
{
public:
  void setDuarkCard(Cards AfterShuffle,int cardCount);
  vector<tuple<string,string,int>> getDurakCard(){return TheCard;}
private:
  vector<tuple<string,string,int>>TheCard;
};

void Durak::setDuarkCard(Cards AfterShuffle,int cardCount)
{
  TheCard.emplace_back(AfterShuffle.mv[cardCount]);
}