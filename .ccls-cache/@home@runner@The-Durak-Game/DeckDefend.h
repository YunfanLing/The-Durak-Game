#include"DeckAttack.h"

class DeckDefend
{
public:
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
  //Defend
  int defendPlayer;
  Hand DefendCards;
  bool take;
  bool legalDefend;
  bool successfulDefend;  


};

///////////////////////Defend//////////////////////
void DeckDefend::setDefendPlayer(int playerName,vector<Hand>Players)
{
  if(playerName==Players.size())
  {
    defendPlayer=1;
  }
  else
    defendPlayer=playerName+1;
}

void DeckDefend::setDefendCards(vector<Hand>Players,int defendNumber)
{
  DefendCards.mv.emplace_back(Players[getDefendPlayer()-1].mv[defendNumber]);
}

void DeckDefend::setLegalDefend(int defendAttackNumber,vector<Hand>Players,int defendNumber,Trump TheTrumpCard)
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