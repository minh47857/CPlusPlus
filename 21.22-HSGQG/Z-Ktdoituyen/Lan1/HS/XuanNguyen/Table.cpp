#include <bits/stdc++.h>
using namespace std;

#define ll = long long;
#define  ld = long double;
#define NguyenLuong "Table"
//random_device dev;
mt19937_64 rng(chrono::steady_clock().now().time_since_epoch().count());
int n;
string s;
ll ans = 1e16;

ll cut(int i) {
	ll ans = 1e16;
	for (int len = min(i + 1, n - i - 1); len <= 15; ++len) {
		string a = string(len - (i + 1), '*'), b;
		for (int j = 0; j <= i; ++j) a += s[j];
		for (int j = i + 1; j < n; ++j) b += s[j];
		while (b.size() < len) b += '*';
		
		bool ok = true;
		for (int j = 0; j < len; ++j) {
			if (a[j] == b[j] && a[j] == '*') {
				ok = false;
				break;
			}
		}
		if (!ok) break;
		
		
	}
}

namespace sub1 {
	string k;
	const ll mod = 1e9 + 7;
	const int base = 271;
	ll Hash[(int)5e6 + 20], Pow[(int)5e6 + 20], Hash_s;
	int get(int l, int r) {
		return (Hash[r] - Hash[l - 1] * Pow[r - l + 1] + mod * mod) % mod;
	}
	void sol() {
		int val = 0;
		while (k.size() <= 1e6) {
			++val;
			k += to_string(val);
		}
		cout << k << '\n';
		int m = k.size();
		k = ' ' + k;
		Pow[0] = 1;
		for (int i = 1; i <= m; ++i) {
			Pow[i] = Pow[i - 1] * base % mod;
			Hash[i] = (Hash[i - 1] * base + k[i]) % mod;
		}
		for (char c : s) {
			Hash_s = (Hash_s * base + c) % mod;
		}
		for (int i = 1; i <= m - n + 1; ++i) {
			if (get(i, i + n - 1) == Hash_s) {
				cout << i + n - 1;
				return;
			}
		}
	}
}

void solve() {
	cin >> n >> s;
	
	if (n <= 6) {
		sub1::sol();
		return;
	}
	
	// )(
	for (int i = 0; i < n - 1; ++i) {
		// Cut at i: i] [i + 1
		ans = min(ans, cut(i));
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
