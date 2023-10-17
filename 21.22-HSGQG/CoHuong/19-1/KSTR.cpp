#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define eps 1e-6
#define pi pair<int , int>
#define Bit(x , k) ((x >> k) & 1)

const int N = 5e4 + 5 , MOD = 123457 , M = 1030;

using namespace std;

void file() {
	freopen("KSTR.inp" , "r" , stdin);
	freopen("KSTR.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int k , n , a[N] , dp[N][M] , ans = 0;

int main() {
	file();
	cin >> k >> n;
	for(int i = 1 , t ; i <= n ; i++) {
		cin >> t;
		while(t--) {
			int x ; cin >> x;
			a[i] += (1 << x);
		}
	}
	for(int i = n + 1 ; i >= 1 ; i--) {
		dp[i - 1][a[i - 1]] = (dp[i - 1][a[i - 1]] + 1) % MOD;
		for(int mask = 0 ; mask < 1024; mask++) {
			int nmask = a[i - 1] & mask;
			nmask ^= a[i - 1];
			dp[i - 1][mask] = (dp[i - 1][mask] + dp[i][mask]) % MOD;
			dp[i - 1][nmask] = (dp[i - 1][nmask] + dp[i][mask]) % MOD;
		}
	}
	for(int i = 0 ; i < 1024 ; i++) 
		if(__builtin_popcount(i) >= k) ans = (ans + dp[1][i]) % MOD;
	cout << ans;
	return 0;
}


