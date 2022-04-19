#include <iostream>
#include"cards.h"
#include <string>
using namespace std;
#include<vector>

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
    for(int j=0;j<9;j++)
    {
      int value=j+6;
      string cardName=cardsSuit[i]+" "+cardsValue[j];
      mp.insert({cardName,value});
      cards.push_back(mp);
      mp.clear();
    }
  }
}

void Cards::output()
{
  cout<<"show all the cards\n";
  cout<<cards.size()<<endl;
  vector<multimap<string,int>>::iterator it;
  for(int i=0;i<cards.size();i++)
  {
    cout << cards[i]<<endl;
  }

}