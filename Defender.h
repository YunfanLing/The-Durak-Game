#include"Draw.h"
struct Defender
{
public:
  int defenderPlayer(int playerAttack);
};

int Defender::defenderPlayer(int playerAttack)
{
  int result;
  if(playerAttack==1)
    result=2;
  else
    result=1;
  return result;
}