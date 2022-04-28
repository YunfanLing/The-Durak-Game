#include"Deck.h"

class Deal
{
public:
  void setDealOrNot(vector<Hand>Players,int cardCount);
  vector<bool> getDealOrNot(){return dealOrNot;}
  
private:
  vector<bool> dealOrNot;
};

void Deal::setDealOrNot(vector<Hand>Players,int cardCount)
{
  if(cardCount==36)
  {
    cout<<"\n-------Cards run out--------\n";
    for(int i=0;i<Players.size();i++)
    {
      dealOrNot.push_back(0);
    }
  }
  else
  {
    for(int i=0;i<Players.size();i++)
    {
      if(Players[i].mv.size()<6)
        dealOrNot.push_back(1);
      else
        dealOrNot.push_back(0);
    }
  }
}
//The main attacker draws as many cards as necessary first, followed by any other attackers in clockwise order, 