#include<iostream>
using namespace std;

struct Player
{
public:
  int playersNumber;
  void setPlayersNumber();
};

void Player::setPlayersNumber()
{
  do 
  {
    cout<<"Please enter the number of the players(Between 2 to 6)\n";
    cin>>playersNumber;    
    if(playersNumber<2||playersNumber>6)
      cout<<"Illegal number please enter again\n";
  }while(playersNumber<2||playersNumber>6);
}