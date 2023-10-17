#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
#define lb long double
const ll N = 1000001 , MOD = 1e9 + 7 , inf = 1e15;

void file() {
	freopen("TUGIAC.inp" , "r" , stdin);
	freopen("TUGIAC.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

struct Point {
	lb x , y;
	Point() {x = y = 0;}
	Point (lb x , lb y) : x(x), y(y) {}
	Point operator + (const Point&a) const{return Point(x + a.x , y + a.y);}
	Point operator - (const Point&a) const{return Point(x - a.x , y - a.y);}
	lb operator % (const Point&a) const{return x * a.y - y * a.x ;}
};

Point a[10];
lb area = 0;
int l , r , t;

int ccw(Point a , Point b , Point c){
    lb t = (b - a) % (c - b);
    if(t == 0) return 0;
    if(t < 0) return -1;
    return 1;
} 

bool check() {
	if(a[1].x == a[3].x && a[1].y == a[3].y) return true;
	if(a[2].x == a[4].x && a[2].y == a[4].y) return true;
	if(ccw(a[1] , a[2] , a[3]) * ccw(a[1] , a[4] , a[3]) == 0) return true;
	return false;
}

Point Its(lb a1 , lb b1 , lb c1 , lb a2 , lb b2 , lb c2) {
	lb x = (b1 * c2 -b2 * c1) / (a1 * b2 - a2 * b1);
	lb y = (a2 * c1 - a1 * c2) / (a1 * b2 - a2 * b1);
	return {x , y};
}

lb S(Point a , Point b , Point c) {
	return  abs((b - a) % (c - a)) * 1.0 / 2;
}

int main() {
//	file();
   for(int i = 1 ; i <= 4 ; i++) 
      cin >> a[i].x >> a[i].y , a[i + 4] = a[i];
   
   if(check()) {
   	cout << 0;
   	return 0;
   }
   
  for(int i = 1 ; i <= 4 ; i++) {
  	if(ccw(a[i] , a[i + 1] , a[i + 2]) < 0) r++;
  	else l++;
  }
  
  if(abs(r - l) == 4) t = 1;
  else if(abs(r - l) == 0) t = 3;
  else t = 2;
  cout << t << '\n';
  
  if(t != 3) {
  	for(int i = 1 ; i <= 4 ; i++) area = area + (a[i] % a[i + 1]);
  area = abs(area);
  area = area * 1.0 / 2;
  }
  
  else {
  	
  	lb a1 = a[1].y - a[2].y , b1 = a[2].x - a[1].x , c1 = - (a1 * a[1].x + b1 * a[1].y);
  	lb a2 = a[3].y - a[4].y , b2 = a[4].x - a[3].x , c2 = - (a2 * a[3].x + b2 * a[3].y);
  	  
	  Point p = Its(a1 , b1 , c1 , a2 , b2 , c2);
	  cout << p.x << ' ' << p.y << '\n';
  	area = S(a[1] , a[4] , p) + S(a[2] , a[3] , p);
  }
	cout << fixed << setprecision(3) << area;
}

