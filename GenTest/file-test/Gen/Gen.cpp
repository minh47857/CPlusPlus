#include <bits/stdc++.h>
using namespace std;

#define print(_v) for (auto &_ : _v) {cerr << _ << ' ';} cerr << '\n';
using ll = long long;
using ld = long double;
random_device dev;
mt19937_64 rng(chrono::steady_clock().now().time_since_epoch().count());
#define NguyenLuong "test"

ll range(ll l, ll r) {
    return l + rng() % (r - l + 1);
}

void solve() {
    for (int t = 1; t <= 10; ++t) {
        string add = (t <= 9 ? "0" : "");
        string test = "Test" + add + to_string(t) + "/Truck.inp"; // filename
        freopen(test.c_str(), "w", stdout);

        int n, m;
        if (t <= 6) n = range(5e2, 1e3);
        else n = range(1e4, 15e3);
        m = range(1, 15000);
        cout << n << ' ' << m << '\n';
        for (int i = 1; i <= n; ++i) {
            cout << range(1, 3e4) << ' ';
        }
    }
}

int main() {
    // ios::sync_with_stdio(0);
    // cout.tie(0); cin.tie(0);
    solve();
    return 0;
}
