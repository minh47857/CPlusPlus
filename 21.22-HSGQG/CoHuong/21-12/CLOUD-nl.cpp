#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 2e3 + 5;
int n, m;

struct T {
    int c;
    ll f, v;
    int dat;
} a[2 * N];

ll dp[2][50 * N];

bool cmp (const T &a, const T &b) {
	if (a.f == b.f) return !a.dat;
    return a.f > b.f;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) 
        cin >> a[i].c >> a[i].f >> a[i].v, a[i].dat = 0;
    cin >> m;
    for (int i = n + 1; i <= n + m; ++i)
        cin >> a[i].c >> a[i].f >> a[i].v, a[i].dat = 1;
    
    n += m;
    sort(a + 1, a + n + 1, cmp);

    int s = 0;
    for (int i = 1; i <= n; ++i)
        s += (1 - a[i].dat) * a[i].c;

    memset(dp, -0x3f, sizeof dp);
    dp[0][0] = 0;
    // for (int i = 0; i <= n; ++i)
    //     dp[i][0] = 0;
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= s; ++j) {
            if (!a[i].dat) {
                dp[i % 2][j] = max(dp[i % 2][j], dp[(i - 1) % 2][j]);
                if (j - a[i].c >= 0)
                    dp[i % 2][j] = max(dp[i % 2][j], dp[(i - 1) % 2][j - a[i].c] - a[i].v);
            } else {
                dp[i % 2][j] = max(dp[i % 2][j], dp[(i - 1) % 2][j]);
                if (j + a[i].c <= s)
                    dp[i % 2][j] = max(dp[i % 2][j], dp[(i - 1) % 2][j + a[i].c] + a[i].v);
            }
//            cout << i << ' ' << j << ' ' << dp[i][j] << '\n';
        }
    }
    for (int i = 0; i <= s; ++i) ans = max(ans, dp[n % 2][i]);
    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);
    if (fopen("CLOUD.inp", "r")) {
        freopen("CLOUD.inp", "r", stdin);
        freopen("CLOUD.out", "w", stdout);
    }
    solve();
    return 0;
}
