#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;
 
enum FACE { TOP, BOTTOM, FRONT, BACK, LEFT, RIGHT };

class dice {
  private:
    int num[6];

    void roll(FACE a, FACE b, FACE c, FACE d) {
      int tmp = num[a];
      num[a] = num[b];
      num[b] = num[c];
      num[c] = num[d];
      num[d] = tmp;
    }

  public:
    dice() {
      num[TOP] = 1;
      num[BOTTOM] = 6;
      num[FRONT] = 3;
      num[BACK] = 4;
      num[RIGHT] = 5;
      num[LEFT] = 2;
    }

    void set(int top, int front) {
      if(num[RIGHT] == top || num[LEFT] == top)
        west();

      while(num[TOP] != top)
        north();

      while(num[FRONT] != front)
        right();
    }

    int operator[] (FACE f) const { return num[f]; }

    //基本これを用いて回転
    void north() { roll(TOP, BACK, BOTTOM, FRONT); }
    void east() { roll(TOP, LEFT, BOTTOM, RIGHT); }
    void west() { roll(TOP, RIGHT, BOTTOM, LEFT); }
    void south() { roll(TOP, FRONT, BOTTOM, BACK); }
    void right() { roll(BACK, RIGHT, FRONT, LEFT); }
    void left() { roll(BACK, LEFT, FRONT, RIGHT); }
};


int main(){

  dice d;
  d.set(1,3);
  d.north();
  cout << d[TOP] << endl;//参照方法
}
