#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
#define lb long double
#define eps 1e-6

const ll N = 1005 , MOD = 1e9 + 7 , inf = 1e15;

void file() {
	freopen("DTAMGIAC.inp" , "r" , stdin);
	freopen("DTAMGIAC.out" , "w" , stdout);
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

Point a[N] , b[N] , c[N];
pair<lb , int> area[N];
int n , ans , dp[N];

lb S(Point a , Point b , Point c) {
	return  abs((b - a) % (c - a)) * 1.0 / 2;
}

bool check(Point p , Point a , Point b , Point c) {
	if(abs(S(a , b , c) - S(a , b , p) - S(a , c , p) - S(b , c , p)) <= eps) return true;
	return false;
}

int main() {
	file();
  cin >> n ;
  for(int i = 1 ; i <= n ; i++) 
    cin >> a[i].x >> a[i].y >> b[i].x >> b[i].y >> c[i].x >> c[i].y , dp[i] = 1,
    area[i] = {S(a[i] , b[i] , c[i]) , i};
    
  sort(area + 1 , area + n + 1);
  for(int i = 1 ; i <= n ; i++) 
  	 for(int j = 1 ; j < i ; j++) {
  	 	int u = area[i].se , v = area[j].se;

  	 	if(check(a[v] , a[u] , b[u] , c[u]) && check(b[v] , a[u] , b[u] , c[u]) && check(c[v] , a[u] , b[u] , c[u])) 
		   dp[i] = max(dp[i] , dp[j] + 1);
		   ans = max(ans , dp[i]);
	   }
  cout << ans;
  return 0;
  	   
		 
  
}

