#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
#define lb long double
const ll N = 1000001 , MOD = 1e9 +7 , inf = 1e15;

void file() {
	freopen("banhxe.inp" , "r" , stdin);
	freopen("banhxe.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

struct Point {
	lb x , y , r;
};

int n ;
Point a[N] , res[N];

lb dist(Point u , Point v){
    return sqrt((u.x - v.x) * (u.x - v.x) + (u.y - v.y) * (u.y - v.y));
}

void Dfs(int i) {
 	for(int j = 1 ; j <= n; j++) {
 		if(res[j].r == 0 && dist(a[i] , a[j]) == a[i].r + a[j].r) {
 			res[j].r = -res[i].r;
 			ll X = res[i].x * a[i].r , Y = res[i].y * a[j].r;
 			res[j].x = X / __gcd(X , Y);
 			res[j].y = Y / __gcd(X , Y);
 			Dfs(j);
		 }
	 }
}

int main() {
	file();
 cin >> n ;
 for(int i = 1 ; i <= n ; i++) cin >> a[i].x >> a[i].y >> a[i].r;
 res[1] = {1 , 1 , 1};

 ///for(int i = 1 ; i <= n ; i++)  {
 //	for(int j = 1 ; j <= n ; j++) cout << i << ' ' << j << ' ' << dist(a[i] , a[j]) << ' ' << a[i].r + a[j].r << '\n';
 //}
 Dfs(1);
 
 for(int i = 1 ; i <= n ; i++) {
 	if(res[i].r == 0) cout << "not moving" << '\n';
 	else if(res[i].r == 1) {
 		cout << res[i].x;
 		if(res[i].y != 1) cout << "/" << res[i].y; 
 		cout << ' ' << "clockwise" << '\n';
	 }
	 else {
	    cout << res[i].x;
 		if(res[i].y != 1) cout << "/" << res[i].y; 
 		cout << ' ' << "counterclockwise" << '\n';
	 }
 }
 return 0;
}

