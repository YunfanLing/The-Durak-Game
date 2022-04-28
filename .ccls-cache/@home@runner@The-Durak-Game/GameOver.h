#include"Attacker.h"

class GameOver
{
public:
  void setGameOverAndDurak(vector<Hand>Players);
  bool getGameOver(){return gameOver;}
  int getDurak(){return durak;}
private:
  bool gameOver;
  int durak;
};

void GameOver::setGameOverAndDurak(vector<Hand>Players)
{
  int playerLeftOnDeck;
  for(int i=0;i<Players.size();i++)
  {
    if(Players[i].mv.size()!=0)
      playerLeftOnDeck+=1;
  }
  if(playerLeftOnDeck==1)
  {
    for(int i=0;i<Players.size();i++)
    {
      if(Players[i].mv.size()!=0)
        durak=i;
    }
    cout<<"\n-------Game Over---------\n";
    cout<<"Player"<<durak<<" is the durak\n";
    exit(0);
  } 
}