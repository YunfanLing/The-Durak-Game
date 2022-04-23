#include <iostream>
#include <map>
#include <string>
#include "Cards.h"
#include <algorithm>
#include <random>
using namespace std;

int main() 
{
  Cards cards;
  cards.setCardsSuit();
  cards.setCardsValue();
  cards.setCards();
  cards.output();
  srand(unsigned(time(NULL)));
  random_shuffle(cards.mv.begin(), cards.mv.end());
  cards.output();
  return 0;
}