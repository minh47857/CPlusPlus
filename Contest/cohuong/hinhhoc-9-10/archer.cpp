#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
#define lb long double

const ll N = 2e3 + 5 , MOD = 1e9 + 7 , inf = 1e15;
const lb eps = 1e-6;

void file() {
	freopen("archer.inp" , "r" , stdin);
	freopen("archer.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

struct Point {
	lb x , y , z;
	bool operator < (const Point&v) const {
		if(x == v.x) {
			if(y == v.y) return z < v.z;
			else return y < v.y;
		}
		else return x < v.x; 
	}	
} a[N];

bool cmp (Point u , Point v) {
	return (abs(u.x - v.x) <= eps && abs(u.y - v.y) <= eps && abs(u.z - v.z) <= eps);
}

int ans = 0 , n , dem = 1;
vector<Point> Dex;

Point calc(lb x , lb y , lb z , Point u) {
	Point res;
	res.z = 0;
	lb t = u.z / z;
	t = -t;
	res.y = u.y + t * y;
	res.x = u.x + t * x;
	return res;
}


int main() {
	file();
  cin >> n;
  for(int i = 1 ; i <= n ; i++) cin >> a[i].x >> a[i].y >> a[i].z;
  for(int u = 1 ; u <= n ; u++) {
  		for(int i = u + 1 ; i <= n ; i++) {
		lb x = a[i].x - a[u].x , y = a[i].y - a[u].y , z = a[i].z - a[u].z;
		if(a[i].z != 0 && z == 0) continue;
		Point tmp = calc(x , y , z , a[u]);
		Dex.pb({calc(x , y , z , a[u])});
	}
  }
  sort(Dex.begin() , Dex.end());
  for(int i = 1 ; i < Dex.size() ; i++) {
  	if(cmp(Dex[i] , Dex[i - 1])) dem++;
  	else ans = max(ans , dem) , dem = 1;
  }
  ans = max(ans , dem);
  ans = sqrt(ans * 2) + 1;
  cout << ans;
  return 0;
}

