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

int main(){


  const int INF = 1e+6; //でかい数字で初期化
  const int n = 100; //ノード数
  int d[n][n];
  fill(d, d + n * n, INF);

  for(int i = 0; i < m; ++i)
  {
    // 本来なら何かしらの入力からノード間のパス情報を取得する
    const int from = pathInfo[i].from;
    const int to = pathInfo[i].to;
    const int distance = pathInfo[i].d;
    // 片方向、両方向のどちらでもワーシャルフロイド法は対応することが出来る
    d[from][to] = distance;
    d[to][from] = distance;
  }

  for(int k = 0; k < n; ++k)
    for(int i = 0; i < n; ++i)
      for(int j = 0; j < n; ++j) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);


  //場所を指定するだけでそこに最短経路が入っている。

}
