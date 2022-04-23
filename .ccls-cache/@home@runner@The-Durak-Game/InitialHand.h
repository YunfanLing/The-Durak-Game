#include<string>
#include<iostream>
#include<vector>
#include<tuple>
#include"Cards.h"
using namespace std;

struct InitialHand
{
public:
  vector<tuple<string,string,int>>mv;
  void deal();
  void output();
};

void InitialHand::deal()
{
  for(int i=0;i<6;i++)
    mv.push_back(cards.mv[j]);  
}


void InitialHand::output()
{
  cout<<"show all the cards\n";
  cout<<mv.size()<<endl;
  for (const auto& i : mv) 
  {
  cout << get<0>(i) << " " << get<1>(i) << ", " << get<2>(i) << endl;
  }
}