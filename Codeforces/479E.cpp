#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 5e3 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

int n , k , a , b , dp[N][N] , ans = 0;

int main() {
	cin >> n >> a >> b >> k;
	if(a < b) {
		dp[a][0] = 1;
		dp[a + 1][0] = -1;
		for(int len = 0 ; len <= k ; len++)
			for(int i = 1 ; i < b ; i++) {
				dp[i][len] = (dp[i][len] + dp[i - 1][len]) % MOD;
			  	int nxl = max(0 , i - (b - i - 1));
			  	dp[nxl][len + 1] = (dp[nxl][len + 1] + dp[i][len]) % MOD;
			  	dp[i + 1][len + 1] = (dp[i + 1][len + 1] + dp[i][len]) % MOD;
			  	dp[i][len + 1] = (dp[i][len + 1] - dp[i][len] + MOD) % MOD;
			  }
		for(int i = 1 ; i < b ; i++) {
			ans = (ans + dp[i][k]) % MOD;
		}
		cout << ans;
	}
	else {
		dp[a][0] = 1;
		dp[a - 1][0] = -1;
		for(int len = 0 ; len <= k ; len++)
			for(int i = n ; i > b ; i--) {
				dp[i][len] = (dp[i][len] + dp[i + 1][len]) % MOD;
				int nxr = min(n + 1 , i + (i - b - 1));
				dp[nxr][len + 1] = (dp[nxr][len + 1] + dp[i][len]) % MOD;
				dp[i - 1][len + 1] = (dp[i - 1][len + 1] + dp[i][len]) % MOD;
				dp[i][len + 1] = (dp[i][len + 1] - dp[i][len] + MOD) % MOD;
			}
		for(int i = n ; i > b ; i--) {
			ans = (ans + dp[i][k]) % MOD;
		}
		cout << ans;
	}
	return 0;
}

