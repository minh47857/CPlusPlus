#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 82 , MOD = 1e9 + 7 , inf = 1e9 + 7;

int t , Pow[N] , cnt[10] , c[N][N] , dp[10][N][N];

int mul(int a , int b) {
	return 1LL * a * b % MOD;
}

int add(int a , int b) {
	a += b;
	if(a >= MOD) a -= MOD;
	if(a < 0) a += MOD;
	return a;
}

void solve() {
	memset(dp , 0 , sizeof(dp));
	int ans = 0;
	for(int i = 1 ; i <= 9 ; i++) 
		cin >> cnt[i];
	for(int x = 1 ; x <= 9 ; x++) {
		if(!cnt[x]) continue;
		dp[x][0][0] = 1;
		for(int i = 0 ; i < 9 ; i++) {
			for(int len = 0 ; len < N ; len++) {
				for(int k = 0 ; k <= cnt[i + 1] - (i + 1 == x) ; k++) 
					if(len + k < N) dp[x][i + 1][len + k] = add(dp[x][i + 1][len + k] , mul(dp[x][i][len] , c[len + k][len]));	
			}
		}
	}
	for(int i = 1 ; i <= 9 ; i++) {
		for(int pos = 1 ; pos < N ; pos++) {
			int res = 0;
			for(int len = pos - 1 ; len < N ; len++)
				res = add(res , dp[i][9][len]);
			ans = add(ans , mul(res , mul(i , Pow[pos - 1])));
 		}
	}
	cout << ans << '\n';
}

int main() {
	c[0][0] = 1;
	for(int i = 1 ; i < N ; i++) {
		c[i][0] = c[i][i] = 1;
		for(int j = 1 ; j <= i / 2 ; j++)
			c[i][j] = c[i][i - j] = add(c[i - 1][j] , c[i - 1][j - 1]);
	}
	Pow[0] = 1;
	for(int i = 1 ; i < N ; i++)
		Pow[i] = mul(Pow[i - 1] , 10);
	cin >> t;
	while(t--) solve();
	return 0;
}

