#include <bits/stdc++.h>
using namespace std;

#define print(_v) for (auto &_ : _v) {cerr << _ << ' ';} cerr << '\n';
using ll = long long;
using ld = long double;
random_device dev;
mt19937_64 rng(chrono::steady_clock().now().time_since_epoch().count());
#define NguyenLuong "test"
const int N = 1e5 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("truck.inp" , "r" , stdin);
	freopen("truck.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int  n , m , d , c = 1e9 , g , res , a[N];

bool check(int x) {
	int s = 0 , p = 1;
	for(int i = 1 ; i <= n ; i++) {
		if(a[i] + s <= x) s += a[i];
		else s = a[i] , p++;
	}
	return (p <= m);
}

void solve() {
    int t = 10;
    string add = (t <= 9 ? "0" : "");
    string testin = "Test" + add + to_string(t) + "/Truck.inp"; // filename
    string testout = "Test" + add + to_string(t) + "/Truck.out"; // filename
    freopen(testin.c_str(), "r", stdin);
    freopen(testout.c_str(), "w", stdout);

    cin >> n >> m;
	for(int i = 1 ; i <= n ; i++) cin >> a[i] , d = max(a[i] , d);
	while(d <= c) {
		g = (d + c) / 2;
		if(check(g)) res = g , c = g - 1;
		else d = g + 1;
	}
	cout << res;
}

int main() {
    // ios::sync_with_stdio(0);
    // cout.tie(0); cin.tie(0);
    solve();
    return 0;
}
