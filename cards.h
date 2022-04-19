#include <map>
#include<string>
#include<vector>
using namespace std;

class Cards
{
  public:
  void setCardsValue();
  void setCardsSuit();
  void setCards();
  void output();
  private:
  vector<string>cardsName;
  vector<string>cardsSuit;
  vector<tuple<string,string,int>>cards;
};