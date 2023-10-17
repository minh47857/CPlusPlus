#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
#define NguyenLuong "Block"
random_device dev;
mt19937_64 rng(chrono::steady_clock().now().time_since_epoch().count());
const int N = 1e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
int n, k, a[N];

namespace sub1 {
	const int Ns = 100 + 5;
	ll dp[Ns][Ns];
	int p[Ns][Ns];
	int rmq[Ns][10];
	int Log2(int x) {return 31 - __builtin_clz(x);}
	int get(int l, int r) {
		int w = Log2(r - l + 1);
		return max(rmq[l][w], rmq[r - (1 << w) + 1][w]);
	}
	void sol() {
		for (int i = 1; i <= n; ++i) rmq[i][0] = a[i];
		for (int j = 1; (1 << j) <= n; ++j) {
			for (int i = 1; i + (1 << j) - 1 <= n; ++i)
				rmq[i][j] = max(rmq[i][j - 1], rmq[i + (1 << (j - 1))][j - 1]);
		}
		
		memset(dp, 0x3f, sizeof dp);
		dp[0][0] = 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= min(i, k); ++j) {
				for (int t = 0; t < i; ++t) {
					if (dp[t][j - 1] + get(t + 1, i) < dp[i][j]) {
						dp[i][j] = dp[t][j - 1] + get(t + 1, i);
					}
//					dp[i][j] = min(dp[i][j], dp[t][j - 1] + get(t + 1, i));
				}
//				cout << i << ' ' << j << ' ' << dp[i][j] << '\n';
			}
		}
		cout << dp[n][k];
	}
}

namespace sub2 {
	const int K = 100 + 5;
	pair<ll, int> dp[N][K][2];
	void sol() {
		for (int i = 0; i <= n; ++i)
			for (int j = 0; j <= k; ++j) dp[i][j][0] = dp[i][j][1] = {inf, 0};
		dp[0][0][0] = {0, 0};
		for (int j = 1; j <= k; ++j) {
			for (int i = j; i <= n; ++i) {
				dp[i][j][0] = {min(dp[i - 1][j - 1][0].first, dp[i - 1][j - 1][1].first) + a[i], a[i]};
				if (dp[i - 1][j][0].first + max(0, a[i] - dp[i - 1][j][0].second) > dp[i - 1][j][1].first + max(0, a[i] - dp[i - 1][j][1].second))
					dp[i][j][1] = {dp[i - 1][j][1].first + max(0, a[i] - dp[i - 1][j][1].second), max(a[i], dp[i - 1][j][1].second)};
				else if (dp[i - 1][j][0].first + max(0, a[i] - dp[i - 1][j][0].second) < dp[i - 1][j][1].first + max(0, a[i] - dp[i - 1][j][1].second))
					dp[i][j][1] = {dp[i - 1][j][0].first + max(0, a[i] - dp[i - 1][j][0].second), max(a[i], dp[i - 1][j][0].second)};
				else {
					if (max(a[i], dp[i - 1][j][1].second) > max(a[i], dp[i - 1][j][0].second))
						dp[i][j][1] = {dp[i - 1][j][1].first + max(0, a[i] - dp[i - 1][j][1].second), max(a[i], dp[i - 1][j][1].second)};
					else
						dp[i][j][1] = {dp[i - 1][j][0].first + max(0, a[i] - dp[i - 1][j][0].second), max(a[i], dp[i - 1][j][0].second)};
				}
			}
		}
		cout << min(dp[n][k][0].first, dp[n][k][1].first);
	}
}

void solve() {
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	
	if (n <= 100)
		sub1::sol();
	else
		sub2::sol();
}

int main() {
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	if (fopen(NguyenLuong".inp", "r")) {
		freopen(NguyenLuong".inp", "r", stdin);
		freopen(NguyenLuong".out", "w", stdout);
	}
	solve();
	return 0;
}
