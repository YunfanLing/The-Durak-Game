#include"Defender.h"
using namespace std;
class Computer
{
public:
  void setHaveComputer(){cout<<"Do we have computer Player?(Enter 1 to have)\n";cin>>haveComputer;}
  bool getHaveComputer(){return haveComputer;}
  //Attack
  void setBat();
  void setCardsCanAttack(vector<Hand>Players,int playerAttack,Deck OnDeck);
  void setAttackCard();
  bool getBat(){return bat;}
  vector<bool>getCardsCanAttack(){return cardsCanAttack;}
  int getAttackCard(){return attackCard;}

  void attack(vector<Hand>& Players,int playerAttack,Deck& OnDeck);

  //Defend
  void setCardsCanDefend(int defendToWhichCards,vector<Hand>Players,int playerDefend,Deck OnDeck,Trump TrumpCard);
  void setTake(Deck OnDeck);
  void setDefendCard();
  vector<bool> getCardsCanDefend(){return cardsCanDefend;}
  bool getTake(){return take;}
  int getDefendCard(){return defendCard;}

  void defend(int playerDefend,vector<Hand>& Players,Trump TrumpCard,Deck& OnDeck);
  
private:
  bool haveComputer;
  bool bat;
  bool take;
  vector<bool> cardsCanAttack;
  vector<bool> cardsCanDefend;
  int attackCard;
  int defendCard;
};


//Computer Attack

void Computer::setCardsCanAttack(vector<Hand>Players,int playerAttack,Deck OnDeck)
{
  cardsCanAttack.clear();
  cardsCanAttack.resize(Players[playerAttack-1].mv.size());
  if(OnDeck.getAttackCards().mv.size()==0)
  {
    for(int i=0;i<cardsCanAttack.size();i++)
      cardsCanAttack[i]=1;
  }
  else
  {
    for(int i=0;i<Players[playerAttack-1].mv.size();i++)
    {
      for(int j=0;j<OnDeck.getAttackCards().mv.size();j++)
      {
        if(Players[playerAttack-1].getValue(i)==OnDeck.getDeckCards().getValue(j))
          cardsCanAttack[i]=1;
      }
    }
  }
}

void Computer::setBat()
{
  int sum=0;
  for(int i=0;i<cardsCanAttack.size();i++)
  {
    if(cardsCanAttack[i]==1)
      sum++;
  }
  if(sum==0)
    bat=1;
  else
    bat=0;
}

void Computer::setAttackCard()
{
  if(bat==0)
  {
    //Use the first card that can attack to attack
    for(int i=0;i<cardsCanAttack.size();i++)
    {
      if(cardsCanAttack[i]==1)
      {
        attackCard=i;
        break;
      }
    }
  }
}

void Computer::attack(vector<Hand>& Players,int playerAttack,Deck& OnDeck)
{
  do
  {
    setCardsCanAttack(Players,playerAttack,OnDeck);
    setBat();
    if(bat==1)
    {
      break;
    }
    setAttackCard();
    OnDeck.setAttackCards(playerAttack,Players,attackCard);
    //OnDeck.getAttackCards().mv.emplace_back(Players[playerAttack-1].mv[attackCard]);
    //OnDeck.getAttackCards().output();
    Players[playerAttack-1].mv.erase(Players[playerAttack-1].mv.begin()+attackCard);
    OnDeck.setDeckCards();
    //Players[playerAttack-1].output();
    //OnDeck.getDeckCards().output();
  }while(bat==0);
  cout<<"\nDeck Cards\n";
  OnDeck.getDeckCards().output();
  cout<<"\nAttacker hand\n";
  OnDeck.getAttackCards().output();
}

//Computer Defend
void Computer::setCardsCanDefend(int defendToWhichCards,vector<Hand>Players,int playerDefend,Deck OnDeck,Trump TrumpCard)
{
  cardsCanDefend.clear();
  cardsCanDefend.resize(Players[playerDefend-1].mv.size());
  if(OnDeck.getAttackCards().mv.size()==OnDeck.getDefendCards().mv.size())
  {
    for(int i=0;i<Players[playerDefend-1].mv.size();i++)
      cardsCanDefend[i]=0;
  }
  else
  {
    for(int i=0;i<Players[playerDefend-1].mv.size();i++)
    {
      //Card i is Trump card
      if(Players[playerDefend-1].getSuit(i)==TrumpCard.getSuit())
      {
        if(OnDeck.getAttackCards().getSuit(defendToWhichCards)==TrumpCard.getSuit())
        {
          if(Players[playerDefend-1].getValue(i)>OnDeck.getAttackCards().getValue(defendToWhichCards))
            cardsCanDefend[i]=1;
          else
            cardsCanDefend[i]=0;
        }
        else
          cardsCanDefend[i]=1;
      }
      //Card i is not trump card
      else
      {
        if(Players[playerDefend-1].getSuit(i)==OnDeck.getAttackCards().getSuit(defendToWhichCards))
        {
          if(Players[playerDefend-1].getValue(i)>OnDeck.getAttackCards().getValue(defendToWhichCards))
            cardsCanDefend[i]=1;
          else
            cardsCanDefend[i]=0;
        }
        else
          cardsCanDefend[i]=0;
      }
    }
  }
}

void Computer::setTake(Deck OnDeck)
{
  if(OnDeck.getBat()==1)
  {  
    if(OnDeck.getAttackCards().mv.size()==OnDeck.getDefendCards().mv.size())
    { 
      take=1;
    }
    else
    {
      int sum=0;
      for(int i=0;i<cardsCanDefend.size();i++)
    {
      if(cardsCanDefend[i]==1)
        sum++;
    }
    if(sum==0)
    {  
      take=1;
    }
    else
    { 
      take=0;
    }
    }
  }
}

void Computer::setDefendCard()
{
  if(take==0)
  {
    //Use the first card that can attack to defend
    for(int i=0;i<cardsCanDefend.size();i++)
    {
      if(cardsCanDefend[i]==1)
      {
        defendCard=i;
        break;
      }
    }
  }
}

void Computer::defend(int playerDefend,vector<Hand>& Players,Trump TrumpCard,Deck& OnDeck)
{
  setTake(OnDeck);
  for(int i=OnDeck.getDefendCards().mv.size();i<OnDeck.getAttackCards().mv.size();i++)
  {
    setCardsCanDefend(i,Players,playerDefend,OnDeck,TrumpCard);
    setTake(OnDeck);
    if(take==1)
      break;
    setDefendCard();
    OnDeck.setDefendCards(playerDefend,Players,defendCard);
    Players[playerDefend-1].mv.erase(Players[playerDefend-1].mv.begin()+defendCard);
    OnDeck.setDeckCards();
  }
  cout<<"\nDeck Cards\n";
  OnDeck.getDeckCards().output();
  cout<<"\nDefend hand\n";
  OnDeck.getDefendCards().output();
}