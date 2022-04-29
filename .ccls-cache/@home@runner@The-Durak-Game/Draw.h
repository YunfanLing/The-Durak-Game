#include"GameOver.h"

class Draw
{
public:
  void setDrawOrNot(vector<Hand>Players,int cardCount);
  void setDrawHowManyCards(vector<Hand>Players);
  void setCardsEnd(int cardCount);
  vector<bool> getDrawOrNot(){return drawOrNot;}
  vector<int> getDrawHowManyCards(){return drawHowManyCards;}
  bool getCardsEnd(){return cardsEnd;}
  void draw(vector<Hand>&Players, int& cardCount,int playerAttack,Cards AfterShuffle);
  
private:
  vector<bool> drawOrNot;
  vector<int> drawHowManyCards;
  bool cardsEnd;  
};

void Draw::setDrawOrNot(vector<Hand>Players,int cardCount)
{
  if(cardCount==36)
  {
    cout<<"\n-------Cards run out--------\n";
    for(int i=0;i<Players.size();i++)
    {
      drawOrNot.push_back(0);
    }
  }
  else
  {
    for(int i=0;i<Players.size();i++)
    {
      if(Players[i].mv.size()<6)
        drawOrNot.push_back(1);
      else
        drawOrNot.push_back(0);
    }
  }
}

void Draw::setDrawHowManyCards(vector<Hand>Players)
{
  for(int i=0;i<Players.size();i++)
  {
    int m=(6-Players[i].mv.size())*drawOrNot[i];
    drawHowManyCards.push_back(m);
  }
}

void Draw::setCardsEnd(int cardCount)
{
  if(cardCount==36)
  {
    cout<<"The cards run out\n";
    cardsEnd=1;
  }
  else
    cardsEnd=0;    
}

//The main attacker draws as many cards as necessary first, followed by any other attackers in clockwise order, 

void Draw::draw(vector<Hand>&Players, int& cardCount,int playerAttack,Cards AfterShuffle)
{
  setDrawOrNot(Players,cardCount);
  setDrawHowManyCards(Players);
  setCardsEnd(cardCount);
  //Attacker draw
  for(int i=0;i<drawHowManyCards[playerAttack-1];i++)
  {
    if(getCardsEnd()==1)
      break;
    Players[playerAttack-1].mv.emplace_back(AfterShuffle.mv[cardCount]);
    cardCount++;
    setCardsEnd(cardCount);
  }
  //Other Player draw
  int otherPlayer;
  for(int i=0;i<Players.size()-1;i++)
  {
    if(getCardsEnd()==1)
      break;
    if(playerAttack+i+1==Players.size())
    {
      otherPlayer=playerAttack+i+1;
      for(int j=0;j<drawHowManyCards[otherPlayer-1];j++)
      {
        if(getCardsEnd()==1)
          break;
        Players[otherPlayer-1].mv.emplace_back(AfterShuffle.mv[cardCount]);
        cardCount++;
        setCardsEnd(cardCount);
      }
    }
    else
    {
      otherPlayer=(playerAttack+i+1)%Players.size();
      for(int j=0;j<drawHowManyCards[otherPlayer-1];j++)
      {
        if(getCardsEnd()==1)
          break;
        Players[otherPlayer-1].mv.emplace_back(AfterShuffle.mv[cardCount]);
        cardCount++;
        setCardsEnd(cardCount);
      }
    }
  }
  drawOrNot.clear();
  drawHowManyCards.clear();
}