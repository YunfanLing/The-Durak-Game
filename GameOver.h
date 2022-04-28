#include"Attacker.h"

class GameOver
{
public:
  void setPlayerLeftOnDeck(vector<Hand>Players);
  void setGameOver(vector<Hand>Players);
  void setDurak(vector<Hand>Players);
  int getPlayerLeftOnDeck(){return playerLeftOnDeck;}
  bool getGameOver(){return gameOver;}
  int getDurak(){return durak;}
  void judgeEnd(vector<Hand>Players);
private:
  int playerLeftOnDeck;
  bool gameOver;
  int durak;
  
};

void GameOver::setPlayerLeftOnDeck(vector<Hand>Players)
{
  playerLeftOnDeck=0;
  for(int i=0;i<Players.size();i++)
  {
    if(Players[i].mv.size()!=0)
    {
      playerLeftOnDeck+=1;
    }
  }
}

void GameOver::setGameOver(vector<Hand>Players)
{
  if(playerLeftOnDeck==1)
  {
    gameOver=1;
    cout<<"\n-------Game Over---------\n";
  }
  else
    gameOver=0;
}

void GameOver::setDurak(vector<Hand>Players)
{
  if(gameOver==1)
  {
    for(int i=0;i<Players.size();i++)
    {
      if(Players[i].mv.size()!=0)
      {
        durak=i+1;
        cout<<"\n     Player"<<durak<<" is the durak   \n";
        cout<<"---------------------------------------\n";
        exit(0);
      }
    }
  }
}

void GameOver::judgeEnd(vector<Hand>Players)
{
  setPlayerLeftOnDeck(Players);
  setGameOver(Players);
  setDurak(Players);
}