#include"Initial/Trump.h"

class Deck
{
public:
  //Attack
  void setAttackCards(int playerName,vector<Hand>Players,int attackNumber);
  void setDeckCards();
  void setBat(){cout<<"Bat?\n";cin>>bat;}
  void setLegalAttack(int playerName,vector<Hand>Players,int attackNumber);
  Hand getAttackCards(){return AttackCards;}
  Hand getDeckCards(){return DeckCards;}
  bool getBat(){return bat;}
  bool getLegalAttack(){return legalAttack;}

  void attack(int playerName,vector<Hand>& Players);

  //Defend 
  void setDefendCards(int defendPlayer,vector<Hand>Players,int defendNumber);
  void setTake(){cout<<"Take?\n";cin>>take;}
  void setLegalDefend(vector<Hand>Players,int defendNumber,Trump TheTrumpCard);
  void setSuccessfulDefend();
  void setDefendPlayer(int playerName,vector<Hand>Players);
  Hand getDefendCards(){return DefendCards;}
  bool getTake(){return take;}
  bool getLegalDefend(){return legalDefend;}
  bool getSuccessfulDefend(){return successfulDefend;}
  int getDefendPlayer(){return defendPlayer;}
  void takeDiscardsDeckCards(vector<Hand>&Players);
  void defend(int playerName,vector<Hand>& Players,Trump TheTrumpCard);



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
    DeckCards.mv[2*i+1]=DefendCards.mv[i];
  }
}

void Deck::setLegalAttack(int playerName,vector<Hand>Players,int attackNumber)
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

void Deck::attack(int playerName,vector<Hand>& Players)
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

void Deck::setDefendCards(int defendPlayer,vector<Hand>Players,int defendNumber)
{
  DefendCards.mv.emplace_back(Players[defendPlayer-1].mv[defendNumber]);
}

void Deck::setLegalDefend(vector<Hand>Players,int defendNumber,Trump TheTrumpCard)
{
  setDefendCards(defendPlayer,Players,defendNumber);
  if(defendNumber>=Players[getDefendPlayer()-1].mv.size()||defendNumber<0)
    legalDefend=0;
  else
  {
    legalDefend=0;
    for(int i=0;i<DefendCards.mv.size();i++)
    {
      //If use trump suit to defend
      if(Players[getDefendPlayer()-1].getSuit(defendNumber)==TheTrumpCard.getSuit())
      {
        if(AttackCards.getSuit(i)==TheTrumpCard.getSuit())
        {
          if(AttackCards.getValue(i)<Players[getDefendPlayer()-1].getValue(defendNumber))
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
        if(AttackCards.getSuit(i)==Players[getDefendPlayer()-1].getSuit(defendNumber))
          if(AttackCards.getValue(i)<Players[getDefendPlayer()-1].getValue(defendNumber))
            legalDefend=1;   
      }
    }
  }
  if(legalDefend==0)
    DefendCards.mv.erase(DefendCards.mv.end());
}

void Deck::defend(int playerName,vector<Hand>& Players,Trump TheTrumpCard)
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
        setLegalDefend(Players,defendNumber,TheTrumpCard);
        if(getLegalDefend()==1)
        {
          //setDefendCards(Players,defendNumber);
          setDeckCards(); 
          getDefendCards().output();
          getDeckCards().output();
          Players[getDefendPlayer()-1].mv.erase(Players[getDefendPlayer()-1].mv.begin()+defendNumber);
        }
        else
        {
          cout<<"Illegal defend please enter again\n";
          setTake();
          if(getTake()==1)
            break;
        }  
      }while(getLegalDefend()==0);

      //cout<<"\nAttack Cards\n";
      //AttackCards.output();
      cout<<"\nDeck Cards\n";
      DeckCards.output();
      cout<<"\nDefender hand\n";
      Players[getDefendPlayer()-1].output();
    }
    setSuccessfulDefend();
  }while(getTake()==0&&getSuccessfulDefend()==0);
}

void Deck::setSuccessfulDefend()
{
  if(AttackCards.mv.size()==DefendCards.mv.size())
  {
    successfulDefend=1;
  }
  else
    successfulDefend=0;
}

void Deck::takeDiscardsDeckCards(vector<Hand>&Players)
{
  if(successfulDefend==0)
  {
    for(int i=0;i<AttackCards.mv.size();i++)
      Players[getDefendPlayer()-1].mv.emplace_back(AttackCards.mv[i]);
    for(int i=0;i<DefendCards.mv.size();i++)
      Players[getDefendPlayer()-1].mv.emplace_back(DefendCards.mv[i]);
    cout<<"Fail to defend "<<"Player"<<getDefendPlayer()<<" take all the cards on the deck\n";
    Players[getDefendPlayer()-1].output();
    DeckCards.mv.clear();
    AttackCards.mv.clear();
    DefendCards.mv.clear();
  }
  else
  {
    cout<<"Player"<< getDefendPlayer()<<" successfully defend the attack\n";
    cout<<"Cards on the deck discard\n";
    DeckCards.mv.clear();
    AttackCards.mv.clear();
    DefendCards.mv.clear();
  }
}
