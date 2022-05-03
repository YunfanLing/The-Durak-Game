#include"Deck.h"

class Attacker
{
public:
  void setAttackerPlayer(Deck OnDeck,int playerAttack,vector<Hand>Players);
  int getAttackerPlayer(){cout<<"Player"<<attackerPlayer<<" attack\n";return attackerPlayer;}
private:
  int attackerPlayer;
};

void Attacker::setAttackerPlayer(Deck OnDeck,int playerAttack,vector<Hand>Players)
{
  if(OnDeck.getSuccessfulDefend())
    attackerPlayer=OnDeck.getDefendPlayer();
  else
  {
    if(Players.size()!=2)
      attackerPlayer=(playerAttack+2)%(Players.size());
    else
    {
      if(OnDeck.getDefendPlayer()==2)
        attackerPlayer=1;
      else
        attackerPlayer=2;
    }
  }  
}