#include <bits/stdc++.h>
using namespace std;

#define print(_v) for (auto &_ : _v) {cerr << _ << ' ';} cerr << '\n';
using ll = long long;
using ld = long double;
random_device dev;
mt19937_64 rng(chrono::steady_clock().now().time_since_epoch().count());
#define NguyenLuong ""
const int N = 2e5 + 5;
int n, a[N], q;

int phi(int n) {
	int ans = n;
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			ans /= i;
			while (n % i == 0) n /= i;
			ans *= (i - 1);
		}
	}
	if (n != 1) ans /= n, ans *= (n);
	return ans;
}

namespace sub1 {
	void sol() {
		while (q--) {
			int t; cin >> t;
			if (t == 1) {
				int l, r; cin >> l >> r;
				for (int i = l; i <= r; ++i)
					a[i] = phi(a[i]);
			} else if (t == 2) {
				int l, r; cin >> l >> r;
				ll sum = 0;
				for (int i = l; i <= r; ++i) sum += a[i];
				cout << sum << '\n';
			} else {
				int pos, val; cin >> pos >> val;
				a[pos] = val;
			}
		}
	}
}

namespace sub2 {
	ll st[4 * N];

	void build(int id, int l, int r) {
		if (l == r) {
			st[id] = a[l];
			return;
		}
		int mid = (l + r) / 2;
		build(id * 2, l, mid);
		build(id * 2 + 1, mid + 1, r);
		st[id] = st[id * 2] + st[id * 2 + 1];
	}
	
	void upd(int id, int l, int r, int pos, int val) {
		if (l == r) {
			st[id] = val;
			return;
		}
		int mid = (l + r) / 2;
		if (pos <= mid)
			upd(id * 2, l, mid, pos, val);
		else
			upd(id * 2 + 1, mid + 1, r, pos, val);
		st[id] = st[id * 2] + st[id * 2 + 1];
	}
	
	ll get(int id, int l, int r, int u, int v) {
		if (r < u || v < l) return 0;
		if (u <= l && r <= v) return st[id];
		int mid = (l + r) / 2;
		return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
	}
	
	void sol() {
		build(1, 1, n);
		
		while (q--) {
			int t; cin >> t;
			if (t == 2) {
				int l, r; cin >> l >> r;
				cout << get(1, 1, n, l, r) << '\n';
			} else {
				int pos, val; cin >> pos >> val;
				upd(1, 1, n, pos, val);
			}
		}
	}
}

bool checka() {
	for (int i = 1; i <= n; ++i)
		if (a[i] > 1e3) return false;
	return true;
}

void solve() {
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	
	if (n <= 1e3 && q <= 1e3)
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
