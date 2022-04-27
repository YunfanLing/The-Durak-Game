#include"Initial/Trump.h"

class Deck
{
public:
  //Attack
  void setAttackCards(int playerName,vector<Hand>Players,int attackNumber);
  void setDeckCards();
  void setBat(){cout<<"Bat?\n";cin>>bat;}
  Hand getAttackCards(){return AttackCards;}
  Hand getDeckCards(){return DeckCards;}
  bool getBat(){return bat;}

  void setLegalAttack(int playerName,vector<Hand>Players,int attackNumber);
  bool getLegalAttack(){return legalAttack;}

  void attack(int playerName,vector<Hand>Players);

  //Defend 
  void setDefendCards(int playerName,vector<Hand>Players,int defendNumber);
  Hand getDefendCards(){return DefendCards;}
  void setTake(){cout<<"Take?\n";cin>>take;}
  bool getTake(){return take;}
  void setLegalDefend(int playerName,vector<Hand>Players,int defendNumber);
  bool getLegalDefend(){return legalDefend;}
  void setSuccessfulDefend(){if(take==0) successfulDefend=1;}
  bool getSuccessfulDefend(){return successfulDefend;}
private:
  //Attack
  Hand AttackCards;
  Hand DeckCards;
  bool bat;
  bool legalAttack;
  //Defend
  Hand DefendCards;
  bool take;
  bool legalDefend;
  bool successfulDefend;
};

void Deck::setAttackCards(int playerName,vector<Hand>Players,int attackNumber)
{
  AttackCards.mv.emplace_back(Players[playerName-1].mv[attackNumber]);
}

void Deck::setDeckCards()
{
  DeckCards.mv.resize(12);
  for(int i=0;i<AttackCards.mv.size();i++)
  {
    DeckCards.mv[2*i]=AttackCards.mv[i];
  }
  for(int i=0;i<DefendCards.mv.size();i++)
  {
    DeckCards.mv[2*i-1]=DefendCards.mv[i];
  }
}

void Deck::setLegalAttack(int playerName,vector<Hand>Players,int attackNumber)
{
  if(AttackCards.mv.size()==0)
    legalAttack=1;
  else
  {
    legalAttack=0;
    for(int i=0;i<DeckCards.mv.size();i++)
    {
      if(DeckCards.getRank(i)==Players[playerName-1].getRank(attackNumber))
        legalAttack=1;
    }    
  }
}

void Deck::attack(int playerName,vector<Hand>Players)
{
  int attackNumber;
  do
  {
    setBat();
    if(getBat()==0)
    {
      do
      {
        cout<<"Enter the number of card in hand to attack\n";
        cin>>attackNumber;
        setLegalAttack(playerName,Players,attackNumber);
        if(getLegalAttack()==1)
        {
          setAttackCards(playerName,Players,attackNumber);
          setDeckCards(); 
          Players[playerName-1].mv.erase(Players[playerName-1].mv.begin()+attackNumber);
        }
        else
        {
          cout<<"Illegal attack please enter again\n";
          setBat();
          if(getBat()==1)
            break;
        }  
      }
      while(getLegalAttack()==0);
      
      Players[playerName-1].output();
      cout<<"\nAttack Cards\n";
      AttackCards.output();
      cout<<"\nDeck Cards\n";
      DeckCards.output();
      cout<<"\nAttacker hand\n";
      Players[playerName-1].output();
    }
  }while(getBat()==0);
}

void Deck::setDefendCards(int playerName,vector<Hand>Players,int defendNumber)
{
  if(playerName==Players.size())
    playerName=0;
  DefendCards.mv.emplace_back(Players[playerName].mv[defendNumber]);
}

void Deck::setLegalDefend(int playerName,vector<Hand>Players,int defendNumber)
{
  if(DefendCards.mv.size()==0)
    legalDefend=1;
  else
  {
    legalDefend=0;
    for(int i=0;i<DeckCards.mv.size();i++)
    {
      if(AttackCards.getRank(i)==Players[playerName-1].getRank(defendNumber))
        legalDefend=1;
    }    
  }
}
