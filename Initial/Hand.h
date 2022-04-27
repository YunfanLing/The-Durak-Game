#include<string>
#include<iostream>
#include<vector>
#include<tuple>
using namespace std;

struct Hand
{
public:
  vector<tuple<string,string,int>>mv;
  void output();
  string getSuit(int i);
  string getRank(int i);
  int getValue(int i);
};

void Hand::output()
{
  cout<<"Show cards\n";
  //cout<<mv.size()<<endl;//The number of cards of this hand
  for (const auto& i : mv) 
  {
  cout << get<0>(i) << " " << get<1>(i) << ", " << get<2>(i) << endl;
  }
}

string Hand::getSuit(int i)
{
  string suit;
  suit=get<0>(mv[i]);
  return suit;
}

string Hand::getRank(int i)
{
  string rank;
  rank=get<1>(mv[i]);
  return rank;
}

int Hand::getValue(int i)
{
  int value;
  value=get<2>(mv[i]);
  return value;
}