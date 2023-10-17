#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 205 ,
	      c1[] = {1 , 0 , 0 , 1} ,
	      c2[] = {0 , 1 , 0 , 1} ;

int n , k , a[N][N];

namespace sub1 {
	ll dp[N][N][5] , ans = 0;
	int f[N];
	void solve() {
		for(int i = 1 ; i <= 2 * n - 1 ; i++) 
		  for(int j = 1 ; j <= min(n + i - 1 , 3 * n - i - 1) ; j++)
		  	f[i] = max(f[i] , a[i][j]);
		for(int i = 0 ; i < 2 * n - 1; i++) {
			int m = min(n + i - 1 , 3 * n - i - 1);
			for(int j = 1 ; j <= m ; j++) 
		  	for(int t = 0 ; t <= 1 ; t++) {
		  		dp[i + 1][j][t] = max(dp[i + 1][j][t] , dp[i][j][t] + a[i + 1][j]);
		  		if(t == 0) dp[i + 1][j][1] = max(dp[i + 1][j][1] , dp[i][j][t] + f[i + 1]);
		  		if(i < n ) {
		  			if(j < m) {
					  	dp[i + 1][j + 1][t] = max(dp[i + 1][j + 1][t] , dp[i][j][t] + a[i + 1][j + 1]);
					  	if(t == 0) dp[i + 1][j + 1][1] = max(dp[i + 1][j + 1][1] , dp[i][j][t] + f[i + 1]);
					  }
				  }
				else {
					if(j > 1) {
						dp[i + 1][j - 1][t] = max(dp[i + 1][j - 1][t] , dp[i][j][t] + a[i + 1][j - 1]);
						if(t == 0) dp[i + 1][j - 1][1] = max(dp[i + 1][j - 1][1] , dp[i][j][t] + f[i + 1]);
					}
				}
			  }
		}
		  
		for(int i = 1 ; i <= n ; i++)
			ans = max({ans , dp[2 * n - 1][i][0] , dp[2 * n - 1][i][1]});
		cout << ans;
	}
}

namespace sub2 {
	pi f[N];
	ll dp[N][N][N][2] , ans = 0;
	void solve() {
		for(int i = 1 ; i <= 2 * n - 1 ; i++) 
		  for(int j = 1 ; j <= min(n + i - 1 , 3 * n - i - 1) ; j++) {
		  	if(a[i][j] >= f[i].fi) f[i] = {a[i][j] , f[i].fi};
		  	else if(a[i][j] > f[i].se) f[i].se = a[i][j];
		  }
		for(int i = 0 ; i < 2 * n - 1 ; i++) {
			int m = min(n + i - 1 , 3 * n - i - 1);
			if(i == 0) m = n;
			for(int j1 = 1 ; j1 <= m ; j1++)
			for(int j2 = j1 + 1 ; j2 <= m ; j2++) 
			for(int t = 0 ; t <= 1 ; t++) 
			for(int p = 0 , f1 , f2 ; p < 4 ; p++) {
				if(i < n) f1 = j1 + c1[p] , f2 = j2 + c2[p];
				else f1 = j1 - c1[p] , f2 = j2 - c2[p];
				if(f1 == f2 || f1 < 1 || f2 > min(n + i , 3 * n - i - 2)) continue;
				int val = max(a[i + 1][f1] , a[i + 1][f2]);
				if(t == 0) 
					dp[i + 1][f1][f2][1] = max(dp[i + 1][f1][f2][1] , dp[i][j1][j2][t] + f[i + 1].fi + ((val == f[i + 1].fi) ? f[i + 1].se : val));
				dp[i + 1][f1][f2][t] = max(dp[i + 1][f1][f2][t] , dp[i][j1][j2][t] + a[i + 1][f1] + a[i + 1][f2]);
			}		
		}
		for(int i = 1 ; i <= n ; i++)
		  for(int j = i + 1 ; j <= n ; j++)
		   ans = max({ans , dp[2 * n - 1][i][j][0] , dp[2 * n - 1][i][j][1]});
		cout << ans;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
	cin >> n >> k;
	for(int i = 1 ; i <= 2 * n - 1 ; i++) 
      for(int j = 1 ; j <= min(n + i - 1 , 3 * n - i - 1); j++)
			cin >> a[i][j];
	if(k == 1) sub1::solve();
	else sub2::solve();
	return 0;
}
