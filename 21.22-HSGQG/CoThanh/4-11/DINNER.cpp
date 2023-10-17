#include <bits/stdc++.h>
using namespace std;

#define print(_v) for (auto &_ : _v) {cerr << _ << ' ';} cerr << '\n';
using ll = long long;
random_device dev;
mt19937 rng((unsigned int) chrono::steady_clock().now().time_since_epoch().count());
#define NguyenLuong "DINNER"
const int N = 1e6 + 5;
const int mod = 1e9 + 7;
int n;
ll dp[N];

void init() {
    dp[1] = 1;
    for (int i = 2; i <= 1e6; ++i) {
        dp[i] = (dp[i - 1] + (i - 2) * dp[i - 2]) % mod;
    }
}

void solve() {
    int n; cin >> n;
    cout << dp[n] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);
    if (fopen(NguyenLuong".inp", "r")) {
        freopen(NguyenLuong".inp", "r", stdin);
        freopen(NguyenLuong".out", "w", stdout);
    }
    init();
    int t; cin >> t; while (t--)
    solve();
    return 0;
}