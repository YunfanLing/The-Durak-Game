#include <iostream>
#include <map>
#include <string>
#include "cards.h"
using namespace std;

int main() 
{
  Cards cards;
  cards.setCardsSuit();
  cards.setCardsValue();
  cards.setCards();
  cards.output();
  
}