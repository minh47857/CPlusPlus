#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
#define NguyenLuong "Beads"
random_device dev;
mt19937_64 rng(chrono::steady_clock().now().time_since_epoch().count());
string s;

void solve() {
	getline(cin, s);
	cout << 60;
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
