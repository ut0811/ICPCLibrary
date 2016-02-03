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

int dx[4] = {1, 0, -1, 0};//{1,0,-1,0,1,1,-1,-1};//8近傍
int dy[4] = {0, 1, 0, -1};//{0,1,0,-1,-1,1,1,-1};//8近傍

int dfs(int x, int y) {
  //(x, y) に対する処理をここに書く

    // 周辺4マスを調べる
    for(int r = 0; r < 4; r++) {
      int nx = x + dx[r];
      int ny = y + dy[r];
      dfs(nx, ny);
    }
}

int main(){

}
