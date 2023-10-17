#include <bits/stdc++.h>
using namespace std;

#define print(_v) for (auto &_ : _v) {cerr << _ << ' ';} cerr << '\n';
using ll = long long;
using ld = long double;
random_device dev;
mt19937_64 rng(chrono::steady_clock().now().time_since_epoch().count());
#define NguyenLuong ""

ll range(ll l, ll r) {
	return l + rng() % (r - l + 1);
}

void solve() {
	int n, m;
	n = range(1e4, 1e5), m = range(1e4, 1e5);
	cout << n << ' ' << m << '\n';
	for (int i = 1; i <= n; ++i) cout << range(1, 1e6) << ' ';
	cout << '\n';
	for (int i = 1; i <= m; ++i) {
		int t = range(1, 3);
		cout << t << ' ';
		if (t <= 2) {
			int l = range(1, n), r = range(l, n);
			cout << l << ' ' << r << '\n';
		} else {
			int k = range(1, n), x = range(1, 1e6);
			cout << k << ' ' << x << '\n';
		}
	}
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

