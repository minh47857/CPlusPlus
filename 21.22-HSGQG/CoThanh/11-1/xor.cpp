#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define eps 1e-6
#define pi pair<int , int>

const int N = 2e4 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

using namespace std;

void file() {
	freopen("bset.inp" , "r" , stdin);
	freopen("bset.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int ans = 0 , n , k , a[N] , dp[15][N];

int main() {
	file();
	cin >> n >> k;
	k = min(14 , k);
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	dp[0][0] = 1;
	for(int i = 0 ; i < n ; i++) {
		for(int j = k ; j >= 1 ; j--) {
			int mk = (((1 << 14) - 1) ^ a[i + 1]);
			for(int mask = mk ; mask > 0 ; mask = (mask - 1) & mk) 
				dp[j + 1][mask | a[i + 1]] = (dp[j + 1][mask | a[i + 1]] + dp[j][mask]) % MOD;	
		}
		dp[1][a[i + 1]] = (dp[1][a[i + 1]] + 1) % MOD;
	}
	for(int i = 1 ; i <= k ; i++)
	  for(int j = 1 ; j < (1 << 14) ; j++)
	    if(dp[i][j]) ans = (ans + 1LL * dp[i][j] * j % MOD) % MOD;
	cout << ans;
	return 0;
}


