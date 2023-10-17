#include<bits/stdc++.h>
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define Bit(x , k) ((x >> k) & 1)

using namespace std;
const int N = 1e3 + 5 , MOD = 1e9 + 7 , inf = 1e9;
int n, a[N];
ll dp[N][N];

void file() {
	freopen("Game.inp" , "r" , stdin);
	freopen("Game.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie() ; cout.tie(0);
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	
	// odd -> 1, even -> 2
	for (int i = 1; i <= n; ++i) dp[i][i] = ((n - 1) % 2 ? -a[i] : a[i]);
	for (int i = n; i >= 1; --i) {
		for (int j = i + 1; j <= n; ++j) {
			int d = (n - (j - i + 1)) % 2;
			if (d % 2 == 0) dp[i][j] = max(dp[i + 1][j] + a[i], dp[i][j - 1] + a[j]);
			else dp[i][j] = min(dp[i + 1][j] - a[i], dp[i][j - 1] - a[j]);
//			cout << i << ' ' << j << ' ' << dp[i][j] << '\n';
		}
	}
	cout << (dp[1][n] > 0 ? "YES" : "NO") << '\n';
}

int main() {
	file();
	int t; cin >> t; while (t--)
		solve();
	return 0;
}

