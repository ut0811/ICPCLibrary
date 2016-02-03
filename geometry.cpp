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
#include<set>
#include<array>

#define ALL(v) (v).begin(),(v).end()
#define REP(i,p,n) for(int i=p;i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define DUMP(list) cout << "{ "; for(auto nth : list){ cout << nth << " "; } cout << "}" << endl
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i);

using namespace std;

typedef double Real;

const Real EPS = 1e-8;

int sign(Real d){
  return d > EPS ? 1 : d < -EPS ? -1 : 0;
}

struct Point{
  Real x,y;

  Point(Real x_ = 0,Real y_ = 0):x(x_),y(y_){}

  Point operator+(const Point &p) const {return Point(x+p.x,y+p.y);}
  Point operator-(const Point &p) const {return Point(x-p.x,y-p.y);}
  Point operator*(Real s) const {return Point(x*s,y*s);}
  Point operator/(Real s) const {return Point(x/s,y/s);}
  bool operator<(const Point &p) const{return sign(x-p.x) == -1 || (sign(x-p.x) == 0 && sign(y-p.y) == -1);}
  bool operator==(const Point &p) const{return sign(x-p.x) == 0 && sign(y-p.y) == 0;}

};

istream &operator>>(istream &is,Point &p){return is >> p.x >> p.y;}//??\???????°???????
ostream &operator<<(ostream &os ,const Point &p){return os << '(' << p.x << ", " << p.y << ')';}//??????????°???????

struct Segment : public array<Point,2>{
  Segment(const Point &a,const Point &b){ at(0) = a; at(1) = b;}
};

struct Line : public array<Point,2>{
  Line(const Point &a,const Point &b){at(0) = a; at(1) = b;}
};

struct Circle{
  Point c;
  Real r;

  Circle(const Point &c_, Real r_):c(c_),r(r_){}
};

typedef vector<Point> Polygon;

Point rotate90(const Point &p){
  return Point(-p.y,p.x);
}

Point rotate(const Point &p,Real theta){
  const Real s = sin(theta),c = cos(theta);
  return Point(c*p.x-s*p.y,s*p.x+c*p.y);
}

Real angle(const Point &p){
  return atan2(p.y,p.x);
}

Real dot(const Point &a,const Point &b){ //??????????????????
  return a.x*b.x+a.y*b.y;
}

Real cross(const Point &a,const Point &b){ //??????????????????
  return a.x*b.y-a.y*b.x;
}


Real norm(const Point &p){
  return p.x*p.x+p.y*p.y;
}

Real abs(const Point &p){
  return sqrt(norm(p));
}

enum { CCW=1,CW=-1,BACK=2,FRONT=-2,ON=0 };
int ccw(const Point &a,const Point &b,const Point &c){
  const Point p = b-a;
  const Point q = c-a;
  const int sgn = sign(cross(p,q));

  if(sgn == 1) return CCW;
  if(sgn == -1) return CW;
  if(sign(dot(p,q)) == -1) return BACK;
  if(sign(norm(p) - norm(q)) == -1) return FRONT;
  return ON;
}

Point project(const Line &l,const Point &p){ //?°???±
  Real t = dot(p-l[0], l[1]-l[0]) / norm(l[0] - l[1]);
  return l[0] + (l[1] - l[0]) * t;
}

Point refrect(const Line &l,const Point &p){ //????°?
  const Point c = project(l,p);
  return c+(c-p);
}

bool intersect(const Segment &a,const Segment &b){
  return ccw(a[0],a[1],b[0])*ccw(a[0],a[1],b[1]) <= 0
    && ccw(b[0],b[1],a[0])*ccw(b[0],b[1],a[1]) <= 0;
}

bool intersect(const Segment &s,const Point &p){
  return ccw(s[0],s[1],p) == ON;
}

bool intersect(const Line &l,const Segment &s){
  return sign(cross(l[1]-l[0],s[0]-l[0])) * cross(l[1]-l[0],s[1]-l[0]) <= 0;
}

bool intersect(const Line &l,const Point &p){
  return abs(ccw(l[0],l[1],p)) != 1;
}

bool intersect(const Line &a,const Line &b){ //????????????
  return sign(cross(a[1]-a[0],b[1]-b[0])) != 0
    ||  sign(cross(a[1]-a[0],b[1]-a[0]) == 0);
}

Real dist(const Point &a,const Point &b){
  return abs(a-b);    
}

Real dist(const Line &l,const Point &p){
  const Point a = l[1]-l[0];
  const Point b = p-l[0];
  return abs(cross(a,b))/abs(a);
}

Real dist(const Line &l,const Segment &s){
  if(intersect(l,s)) return 0;
  return min(dist(l,s[0]),dist(l,s[1]));
}

Real dist(const Line &a,const Line &b){
  if(intersect(a,b)) return 0;
  return dist(a,b[0]);
}

Real dist(const Segment &s,const Point &p){
  if(sign(dot(s[1]-s[0],p-s[0]))==-1) return dist(s[0],p);
  if(sign(dot(s[0]-s[1],p-s[1]))==-1) return dist(s[1],p);
  return dist(Line(s[0],s[1]),p);
}

Real dist(const Segment &a,const Segment &b){
  if(intersect(a,b)) return 0;
  return min({dist(a,b[0]),dist(a,b[1]),dist(b,a[0]),dist(b,a[1])});
}

int main(){

  cout.setf(ios::fixed);
  cout.precision(10);

  int q;
  cin >> q;
  rep(i,q){
    Point p1,p2,p3,p4;
    cin >> p1 >> p2 >> p3 >> p4;
    cout << dist(Segment(p1,p2),Segment(p3,p4)) << endl;
  }
  return 0;
}
