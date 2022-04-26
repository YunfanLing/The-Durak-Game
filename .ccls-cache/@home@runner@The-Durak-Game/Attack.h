#include"Initial/Trump.h"

class Attack
{
public:
  void setAttackCards(int playerName,vector<Hand>Players);
  void setDeckCards();
  Hand getAttackCards(){return AttackCards;}
  Hand getDeckCards(){return DeckCards;}
  bool bat();
private:
  Hand AttackCards;
  Hand DeckCards;
};

void Attack::setAttackCards(int playerName,vector<Hand>Players)
{
  AttackCards.mv.resize(6);
  int attackNumber;
  setDeckCards();
  do
  {
    int i=0;
    cout<<"Player"<<playerName<<" which cards you want to attack(Enter the number of order in your hand)\n";
    Players[playerName].output();
    do
    {
      
    }while()
    cin>>attackNumber;
    AttackCards.mv.emplace_back(Players[playerName].mv[attackNumber]);//out the attack card
    Players[playerName].mv.erase(Players[playerName].mv.begin()+attackNumber);//erase the attack from the attacker hand
    DeckCards.mv[2*i]=Players[playerName].mv[attackNumber];//Add the attack card to deck as the even number of the vector
    cout<<"Attack cards shows below\n";
    i++;
  }while(bat()==0);
}

void Attack::setDeckCards()
{
  DeckCards.mv.resize(12);
}

bool thisCardCanAttack(int attackNumber)
{
  
}

bool Attack::bat()
{
  bool batOrNot;
  for(int i=0;i<AttackCards.mv.size();i++)
    for(int j=0;j<DeckCards.mv.size();i++)
      if(AttackCards.getRank(i)==DeckCards.getRank(i))
      {
        batOrNot=0;
        cout<<"Bat?(Enter 1 to bat 0 to attack)\n";//1 to bat 0 to continue attack
        cin>>batOrNot;
      }
      else
        batOrNot=1;
  return batOrNot;
}