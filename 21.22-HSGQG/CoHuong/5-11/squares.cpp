#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("squares.inp" , "r" , stdin);
	freopen("squares.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int m , n , k;

namespace sub2 {
	int ans = 0 , d[35][35];
	bool check(int x , int y) {
		if(x < 1 || x > m || y < 1 || y > n || d[x][y]) return false;
		return true;
	}
	
	void solve() {
		for(int i = 1 , u , v ; i <= k ; i++) cin >> u >> v , d[u][v] = 1;
		for(int i = 1 ; i <= m ; i++)
		  for(int j = 1 ; j <= n ; j++) 
		  	for(int u = i + 1 ; u <= m ; u++)
		       for(int v = j ; v <= n ; v++) {
		  	   	    int nx = u - i , ny = v - j;
		  	   	    if(!d[i][j] && !d[u][v] && check(u - ny , v + nx) && check(i - ny , j + nx)) ans++;
				}
		cout << ans;
	}
}

namespace sub3 {
	ll ans = 0;
	bool check(int x , int y) {
		if(x < 1 || x > m || y < 1 || y > n) return false;
		return true;
	}
	
	void solve() {
		for(int i = 1 ; i <= m ; i++)
		  for(int j = 1 ; j <= n ; j++) {
		  	int best = m;
		  	for(int v = j ; v <= n ; v++) {
		  	    	for(int u = best ; u > i ; u--) {
		  	    		best = u;
		  	    		int nx = u - i , ny = v - j;
		  	   	          if(check(u - ny , v + nx) && check(i - ny , v + nx)) {
		  	   	    	  ans += (best - i);
		  	   	    	  break;
						}
					}
		  	   	    
				}
		  }
		  	    
		cout << ans;
	}
}

int main() {
	file();
	cin >> m >> n >> k;
	if(m <= 30) sub2::solve();
	else sub3::solve();
}

