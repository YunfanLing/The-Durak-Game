#include<iostream>
#include<string>
#include<vector>
#include<tuple>
using namespace std;

struct Cards
{
  public:
  void setCardsValue();
  void setCardsSuit();
  void setCards();
  void output();
  vector<string>cardsName;
  vector<string>cardsSuit;
  vector<tuple<string,string,int>>mv;
};

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
      mv.emplace_back(cardsSuit[i],cardsName[j],value);      
    }
  }
}

void Cards::output()
{
  cout<<"show all the cards\n";
  cout<<mv.size()<<endl;
  for (const auto& i : mv) 
  {
  cout << get<0>(i) << " " << get<1>(i) << ", " << get<2>(i) << endl;
  }

}