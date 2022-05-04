#include <iostream>
#include <string>
//#include "Initial/Trump.h"
//#include "Deck.h"
//#include "Attacker.h"
//#include"GameOver.h"
//#include"Draw.h"
#include"Computer.h"
//#include"Defender.h"
using namespace std;

int playersNumber();
Hand firstDeal(Cards cards,int i);
int cardCount=0;

int main() 
{
  Cards AfterShuffle;
  Trump TrumpCard;
  Deck OnDeck;
  Attacker Attack;
  GameOver GameOver;
  Draw Draw;
  Computer Computer;
  Defender Defender;
  AfterShuffle.shuffleCards();
  //AfterShuffle.output();
  const int NUMBER_OF_PLAYERS=playersNumber();
  Computer.setHaveComputer();
  if(Computer.getHaveComputer()==1)
    cout<<"-----Set Player2 as the computer player-----\n";
  else
    cout<<"-------There is no computer player--------\n";
  //InitialHand Hand;
  vector<Hand>Players;
  for(int i=0;i<NUMBER_OF_PLAYERS;i++)
  {
    cout<<"Hand of Player"<<i+1<<" after first deal\n";
    Players.push_back(firstDeal(AfterShuffle,i+1));
    Players[i].output();
  }
  cout<<cardCount<<endl;
  
  //Get Durak card;
  TrumpCard.setTrumpCard(AfterShuffle,cardCount);
  cout<<"\n\n-------The trump card is---------\n";
  TrumpCard.output();
  //Who attack first
  cout<<"\n\n--------------------------------\n";
  cout<<"          First Round            \n";
  int playerAttack=TrumpCard.whoAttackFirst(Players);

  if(Computer.getHaveComputer()==0)
  {
  //No computer player
  int playerDefend=Defender.defenderPlayer(playerAttack);
  do 
  {
    OnDeck.attack(playerAttack,Players);
    GameOver.judgeEnd(Players);
    OnDeck.defend(playerAttack,Players,TrumpCard);
    GameOver.judgeEnd(Players);
    OnDeck.setSuccessfulDefend();
  }while(OnDeck.getTake()==0);
  /*OnDeck.attack(playerAttack,Players);
  GameOver.judgeEnd(Players);
  OnDeck.defend(playerAttack,Players,TrumpCard);
  GameOver.judgeEnd(Players);
  OnDeck.setSuccessfulDefend();*/
  OnDeck.takeDiscardsDeckCards(Players,playerDefend);
  Draw.draw(Players,cardCount,playerAttack,AfterShuffle);
  Attack.setAttackerPlayer(OnDeck,playerAttack,Players);
  //Draw.draw(Players,cardCount,playerAttack,AfterShuffle);
  playerAttack=Attack.getAttackerPlayer();
  playerDefend=Defender.defenderPlayer(playerAttack);
  cout<<"\nCards left "<<36-cardCount<<endl;
  //OnDeck.getAttackCards().output();
  //OnDeck.getDeckCards().output();
  //OnDeck.getDefendCards().output();
  //while(gameEnd);
  while(1)
  {
    cout<<"\n\n------------------------------\n";
    cout<<"             Next Round            \n";
    do 
    {
      OnDeck.attack(playerAttack,Players);
      GameOver.judgeEnd(Players);
      OnDeck.defend(playerAttack,Players,TrumpCard);
      GameOver.judgeEnd(Players);
      OnDeck.setSuccessfulDefend();
    }while(OnDeck.getTake()==0);
    
    /*OnDeck.attack(playerAttack,Players);
    GameOver.judgeEnd(Players);
    OnDeck.defend(playerAttack,Players,TrumpCard);
    GameOver.judgeEnd(Players);
    OnDeck.setSuccessfulDefend();*/
    OnDeck.takeDiscardsDeckCards(Players,playerDefend);
    Draw.draw(Players,cardCount,playerAttack,AfterShuffle);
    Attack.setAttackerPlayer(OnDeck,playerAttack,Players);
    //Draw.draw(Players,cardCount,playerAttack,AfterShuffle);
    playerAttack=Attack.getAttackerPlayer();
    playerDefend=Defender.defenderPlayer(playerAttack);
    //OnDeck.getAttackCards().output();
    //OnDeck.getDeckCards().output();
    //OnDeck.getDefendCards().output();
    cout<<"\nCards left "<<36-cardCount<<endl;
  }
  }
  else
  {
    int playerDefend=Defender.defenderPlayer(playerAttack);
    do 
    {
      if(playerAttack==1)
      {
        cout<<"==You attack computer==\n";
        OnDeck.attack(playerAttack,Players);
        GameOver.judgeEnd(Players);
      }
      else
      {
        cout<<"==Computer attack==\n";
        Computer.attack(Players,playerAttack,OnDeck);
        GameOver.judgeEnd(Players);
      }
      if(playerDefend==1)
      {
        cout<<"==You defend computer==\n";
        OnDeck.defend(playerAttack,Players,TrumpCard);
        GameOver.judgeEnd(Players);
      }
      else
      {
        cout<<"==Computer defend==\n";
        Computer.defend(playerDefend,Players,TrumpCard,OnDeck);
        GameOver.judgeEnd(Players);
      }
      OnDeck.setSuccessfulDefend();
    }while(Computer.getTake()!=1&&OnDeck.getTake()!=1);
    OnDeck.takeDiscardsDeckCards(Players,playerDefend);
    Draw.draw(Players,cardCount,playerAttack,AfterShuffle);
    Attack.setAttackerPlayer(OnDeck,playerAttack,Players);
    playerAttack=Attack.getAttackerPlayer();
    playerDefend=Defender.defenderPlayer(playerAttack);
    cout<<"\nCards left "<<36-cardCount<<endl;
    cout<<playerAttack<<endl;
    cout<<playerDefend<<endl;

    do 
    {
      cout<<"\n\n------------------------------\n";
      cout<<"             Next Round            \n";
      do 
      {
        if(playerAttack==1)
        {
          cout<<"==You attack computer==\n";
          OnDeck.attack(playerAttack,Players);
          GameOver.judgeEnd(Players);
        }
        else
        {
          cout<<"==Computer attack==\n";
          Computer.attack(Players,playerAttack,OnDeck);
          GameOver.judgeEnd(Players);
        }
        if(playerDefend==1)
        {
          cout<<"==You defend computer==\n";
          OnDeck.defend(playerAttack,Players,TrumpCard);
          GameOver.judgeEnd(Players);
        }
        else
        {
          cout<<"==Computer defend==\n";
          Computer.defend(playerDefend,Players,TrumpCard,OnDeck);
          GameOver.judgeEnd(Players);
        }
        OnDeck.setSuccessfulDefend();
      }while(Computer.getTake()!=1&&OnDeck.getTake()!=1);
      OnDeck.takeDiscardsDeckCards(Players,playerDefend);
      Draw.draw(Players,cardCount,playerAttack,AfterShuffle);
      Attack.setAttackerPlayer(OnDeck,playerAttack,Players);
      playerAttack=Attack.getAttackerPlayer();
      playerDefend=Defender.defenderPlayer(playerAttack);
      cout<<"\nCards left "<<36-cardCount<<endl;
    }while(1);
  }
  return 0;
}

int playersNumber()
{
  int playersNumber;
  do 
  {
    cout<<"Please enter the number of the players(Between 2 to 6)\n";
    cin>>playersNumber;    
    if(playersNumber<2||playersNumber>6)
      cout<<"Illegal number please enter again\n";
  }while(playersNumber<2||playersNumber>6);
  return playersNumber;
}

Hand firstDeal(Cards Cards,int i)
{
  Hand Result;
  for(int j=0+6*(i-1);j<6+6*(i-1);j++)
  {
    Result.mv.push_back(Cards.mv[j]);
    cardCount++;
  }
  return Result;
}


