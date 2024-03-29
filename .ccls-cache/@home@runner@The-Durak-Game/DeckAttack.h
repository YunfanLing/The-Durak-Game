#include"Initial/Trump.h"

class DeckAttack
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
  void setDefendCards(vector<Hand>Players,int defendNumber);
  Hand getDefendCards(){return DefendCards;}
  void setTake(){cout<<"Take?\n";cin>>take;}
  bool getTake(){return take;}
  void setLegalDefend(int defendAttackNumber,vector<Hand>Players,int defendNumber,Trump TheTrumpCard);
  bool getLegalDefend(){return legalDefend;}
  void setSuccessfulDefend(){if(take==0) successfulDefend=1;}
  bool getSuccessfulDefend(){return successfulDefend;}

  void defend(int playerName,vector<Hand>Players,Trump TheTrumpCard);

  void setDefendPlayer(int PlayerName,vector<Hand>Players);
  int getDefendPlayer(){return defendPlayer;}


private:
  //Attack
  Hand AttackCards;
  Hand DeckCards;
  bool bat;
  bool legalAttack;
  //Defend
  int defendPlayer;
  Hand DefendCards;
  bool take;
  bool legalDefend;
  bool successfulDefend;
};

void DeckAttack::setAttackCards(int playerName,vector<Hand>Players,int attackNumber)
{
  AttackCards.mv.emplace_back(Players[playerName-1].mv[attackNumber]);
}

void DeckAttack::setDeckCards()
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

void DeckAttack::setLegalAttack(int playerName,vector<Hand>Players,int attackNumber)
{
  if(AttackCards.mv.size()==0)
    legalAttack=1;
  else if(attackNumber>=Players[playerName-1].mv.size()||attackNumber<0)
    legalAttack=0;
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

void DeckAttack::attack(int playerName,vector<Hand>Players)
{
  int attackNumber;
  do
  {
    cout<<"\nAttacker Player"<<playerName<<" attack\n";
    Players[playerName-1].output();
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

      //cout<<"\nAttack Cards\n";
      //AttackCards.output();
      cout<<"\nDeck Cards\n";
      DeckCards.output();
      cout<<"\nAttacker hand\n";
      Players[playerName-1].output();
    }
  }while(getBat()==0);
}

///////////////////////Defend//////////////////////
void Deck::setDefendPlayer(int playerName,vector<Hand>Players)
{
  if(playerName==Players.size())
  {
    defendPlayer=1;
  }
  else
    defendPlayer=playerName+1;
}

void Deck::setDefendCards(vector<Hand>Players,int defendNumber)
{
  DefendCards.mv.emplace_back(Players[getDefendPlayer()-1].mv[defendNumber]);
}

void Deck::setLegalDefend(int defendAttackNumber,vector<Hand>Players,int defendNumber,Trump TheTrumpCard)
{
  if(defendNumber>=Players[getDefendPlayer()-1].mv.size()||defendNumber<0)
    legalDefend=0;
  else if(defendAttackNumber==0)
  {
    legalDefend=1;
  }
  else
  {
    legalDefend=0;
    //If use trump suit to defend
    if(Players[getDefendPlayer()-1].getSuit(defendNumber)==TheTrumpCard.getSuit())
    {
      if(AttackCards.getSuit(defendAttackNumber)==TheTrumpCard.getSuit())
      {
        if(AttackCards.getRank(defendAttackNumber)<Players[getDefendPlayer()-1].getRank(defendNumber))
          legalDefend=1;
        else
          legalDefend=0;
      }
      else
        legalDefend=1;    
    } 
    //Not trump suit
    else
    {
      if(AttackCards.getSuit(defendAttackNumber)==Players[getDefendPlayer()-1].getSuit(defendNumber))
        if(AttackCards.getRank(defendAttackNumber)<Players[getDefendPlayer()-1].getRank(defendNumber))
          legalDefend=1;   
    }
  }
}

void Deck::defend(int playerName,vector<Hand>Players,Trump TheTrumpCard)
{
  int defendNumber;
  setDefendPlayer(playerName,Players);
  do
  {
    cout<<"\nDefend Player"<<getDefendPlayer()<<" defend\n";
    Players[getDefendPlayer()-1].output();
    setTake();
    if(getTake()==0)
    {
      do
      {
        cout<<"Enter the number of card in hand to defend\n";
        cin>>defendNumber;
        //setLegalDefend(0,Players,defendNumber,TheTrumpCard);
        //if(getLegalDefend()==1)
        if(1)
        {
          setDefendCards(Players,defendNumber);
          //setDeckCards(); 
          Players[getDefendPlayer()-1].mv.erase(Players[playerName-1].mv.begin()+defendNumber);
        }
        else
        {
          cout<<"Illegal attack please enter again\n";
          setTake();
          if(getTake()==1)
            break;
        }  
      }
      while(0);

      //cout<<"\nAttack Cards\n";
      //AttackCards.output();
      cout<<"\nDeck Cards\n";
      DeckCards.output();
      cout<<"\nAttacker hand\n";
      Players[getDefendPlayer()-1].output();
    }
  }while(getTake()==0);
  //}
}

