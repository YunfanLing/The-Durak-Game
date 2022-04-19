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
  vector<string>cardsValue;
  vector<string>cardsSuit;
  multimap<string,int> mp;
  vector<multimap<string,int>>cards;
};