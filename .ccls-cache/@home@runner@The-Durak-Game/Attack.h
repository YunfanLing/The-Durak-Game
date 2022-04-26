#include"Initial/Trump.h"

class Attack
{
public:
  void setAttackCards(int playerName,vector<Hand>Players);
  void setDeckCards();
  Hand getAttackCards(){return attackCards;}
  Hand getDeckCards(){return deckCards;}
  bool canAttackMore();
private:
  Hand attackCards;
  Hand deckCards;
};

void Attack::setAttackCards(int playerName,vector<Hand>Players)
{
  int attackNumber;
  do
  {
    cout<<"Player"<<playerName<<" which cards you want to attack(Enter the number of order in your hand)\n";
    Players[playerName].output();
    cin>>attackNumber;
    cout<<"Attack"
  }while(canAttackMore());
}
