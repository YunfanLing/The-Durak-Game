#include <iostream>
#include"cards.h"
#include <string>
using namespace std;
#include<vector>

void Cards::setCardsValue()
{
  cardsName.push_back("6");
  cardsName.push_back("7");
  cardsName.push_back("8");
  cardsName.push_back("9");
  cardsName.push_back("10");
  cardsName.push_back("J");
  cardsName.push_back("Q");
  cardsName.push_back("K");
  cardsName.push_back("A");

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
    for(int j=0;j<9;j++)
    {
      int value=j+6;
      cards.emplace_back(cardsSuit[i],cardsName[j],value);      
    }
  }
}

void Cards::output()
{
  cout<<"show all the cards\n";
  cout<<cards.size()<<endl;
  for (const auto& i : cards) 
  {
  cout << get<0>(i) << " " << get<1>(i) << ", " << get<2>(i) << endl;
  }

}