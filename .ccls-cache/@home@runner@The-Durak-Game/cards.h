#include <map>
#include<string>
#include<vector>
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