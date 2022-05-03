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
  {
    if(playerAttack==1)
      attackerPlayer=2;
    else
      attackerPlayer=1;
  }
  else
  {
    if(playerAttack==1)
      attackerPlayer=1;
    else
      attackerPlayer=2;
  }

}