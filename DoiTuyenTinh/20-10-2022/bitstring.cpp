#include<bits/stdc++.h>
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define Bit(x , k) ((x >> k) & 1)

using namespace std;
const int N = 1e5 + 5 , MOD = 1e6 + 7 , K = 105;

void file() {
	freopen(".inp" , "r" , stdin);
	freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie() ; cout.tie(0);
}

int n , k , dp[N][K];

int main() {
	cin >> n >> k;
	dp[0][0] = 1;
	for(int i = 0 ; i < n ; i++) {
		for(int j = 0 ; j <= min(k , i) ; j++) {
			if(j == k) 
				dp[i + 1][j] = (dp[i + 1][j] + 2 * dp[i][j]) % MOD;
			else {
				dp[i + 1][0] = (dp[i + 1][0] + dp[i][j]) % MOD;
				dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j]) % MOD;
			}
		}
	}
	cout << dp[n][k];
	return 0;
}

