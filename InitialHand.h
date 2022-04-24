#include<string>
#include<iostream>
#include<vector>
#include<tuple>
using namespace std;

struct InitialHand
{
public:
  vector<tuple<string,string,int>>mv;
  void output();
};

void InitialHand::output()
{
  cout<<"Show hand cards\n";
  cout<<mv.size()<<endl;
  for (const auto& i : mv) 
  {
  cout << get<0>(i) << " " << get<1>(i) << ", " << get<2>(i) << endl;
  }
}