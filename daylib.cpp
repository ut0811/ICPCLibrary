#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<cmath>
#include<climits>
#include<ctime>
#include<cstring>
#include<stack>
#include<queue>
#include<sstream>
#include<string>

#define ALL(v) (v).begin(),(v).end()
#define REP(i,p,n) for(int i=p;i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define DUMP(list) cout << "{ "; for(auto nth : list){ cout << nth << " "; } cout << "}" << endl;

//曜日計算マクロ{日,月,火,水,木,金,土}
#define DayOfWeek( year, month, day ) \
  ( ((month) <= 2) ? ((((year) - 1) + (((year) - 1) / 4) - (((year) - 1) / 100) + (((year) - 1) / 400) + (((13 * ((month) + 12)) + 8) / 5) + (day)) % 7) : ( ((year) + ((year) / 4) - ((year) / 100) + ((year) / 400) + (((13 * (month)) + 8) / 5) + (day)) % 7) ) 


using namespace std;

//閏年ならtrue
bool is_uruu(int y) {
      return y % 4 == 0 && (y % 100 != 0 || y % 400 == 0);
}

int main(){
  
  int y=2016;
  cout << is_uruu(y) << endl;

  cout << DayOfWeek(2014,1,16) << endl;
}
