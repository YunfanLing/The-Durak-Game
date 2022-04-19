#include <iostream>
#include"cards.h"
#include <string>
using namespace std;

void Cards::setCardsValue()
{
  cardsValue.push_back("6");
  cardsValue.push_back("7");
  cardsValue.push_back("8");
  cardsValue.push_back("9");
  cardsValue.push_back("10");
  cardsValue.push_back("J");
  cardsValue.push_back("Q");
  cardsValue.push_back("K");
  cardsValue.push_back("A");

}

void Cards::setCardsSuit()
{
  cardsSuit.push_back("SPADES");
  cardsSuit.push_back("HEARTS");
  cardsSuit.push_back("CLUBS");
  cardsSuit.push_back("DIAMONDS");
}

void Cards::setCards()
{
  for(int i=0;i<4;i++)
  {
    string suit=cardsSuit[i];
    for(int j=0;j<9;j++)
    {
      string value=cardsValue[j];
      cards.insert({suit,value});
    }
  }
}

void Cards::output()
{
  cout<<"show all the cards\n";
  for(auto ptr=cards.begin();ptr!=cards.end();ptr++)
    cout<<ptr->first<<" "<<ptr->second<<endl;
}