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

using namespace std;


//インラインにすることでオーバーヘッドが解消できるらしい

//string -> int
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}

//プリミティブ型 -> string
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

//文字列分割
vector<string> split(const string &s, char delim) {
  vector<string> elems;
  stringstream ss(s);
  string item;
  while (getline(ss, item, delim)) {
    if (!item.empty()) {
      elems.push_back(item);
    }
  }
  return elems;
}

int main(){

  vector<string> strs = split("a.b.c",'.');

  rep(i,strs.size()){
    cout << strs[i] << endl;
  }

  double num = 3.14;

  cout << toInt("0256") << endl;
  cout << toString(20) << endl;
}
