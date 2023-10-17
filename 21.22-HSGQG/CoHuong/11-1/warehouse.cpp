#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define eps 1e-6
#define pi pair<int , int>

const int N = 1005 , MOD = 1e9 + 7 , M = 105;

using namespace std;

void file() {
	freopen("warehouse.inp" , "r" , stdin);
	freopen("warehouse.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int n , T , D , a[N] , t[N] , dp[N][M] , ans = 0;

int main() {
	file();
	cin >> n >> T >> D;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	for(int i = 1 ; i <= n ; i++) cin >> t[i];
	for(int i = 0 ; i <= n ; i++)
		for(int j = 0 ; j <= T ; j++) {
			ans = max(ans , dp[i][j]);
			for(int k = i + 1 ; k <= min(n , i + D) ; k++) 
				if(t[k] + j <= T) 
					dp[k][j + t[k]] = max(dp[k][j + t[k]] , dp[i][j] + a[k]);	
		}
	cout << ans;
	return 0;
}


