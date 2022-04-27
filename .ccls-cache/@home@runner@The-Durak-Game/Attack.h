#include"Initial/Trump.h"

class Deck
{
public:
  void setAttackCards(int playerName,vector<Hand>Players);
  void setDeckCards();
  Hand getAttackCards(){return AttackCards;}
  Hand getDeckCards(){return DeckCards;}
  bool thisCardCanAttack(int attackNumber);
  bool bat();
private:
  Hand AttackCards;
  Hand DeckCards;
};

void Deck::setAttackCards(int playerName,vector<Hand>Players)
{
  AttackCards.mv.resize(6);
  int attackNumber;
  setDeckCards();
  //Check whether the card Player use to attack on deck.
  do
  {
    int i=0;
    Players[playerName].output();
    do
    {
      cout<<"Player"<<playerName<<" which cards you want to attack(Enter the number of order in your hand)\n";
      cin>>attackNumber; 
    }while(thisCardCanAttack(attackNumber)==0);
    AttackCards.mv.emplace_back(Players[playerName].mv[attackNumber]);
    //erase the attack card from the player hand
    Players[playerName].mv.erase(Players[playerName].mv.begin()+attackNumber);
    //Add the attack card to deck as the even number of the vector
    DeckCards.mv[2*i]=Players[playerName].mv[attackNumber];
    cout<<"Attack cards shows below\n";
    i++;
  }while(bat()==0);
}

void Deck::setDeckCards()
{
  DeckCards.mv.resize(12);
}

bool Deck::thisCardCanAttack(int attackNumber)
{
  bool canAttack=0;
  for(int i=0;i<DeckCards.mv.size();i++)
    if(DeckCards.getRank(i)==AttackCards.getRank(attackNumber))
      canAttack=1;
  return canAttack;
}

bool Deck::bat()
{
  bool batOrNot;
  for(int i=0;i<AttackCards.mv.size();i++)
    for(int j=0;j<DeckCards.mv.size();i++)
      if(AttackCards.getRank(i)==DeckCards.getRank(i))
      {
        cout<<"Bat?(Enter 1 to bat 0 to attack)\n";//1 to bat 0 to continue attack
        cin>>batOrNot;
      }
      else
        batOrNot=1;
  return batOrNot;
}