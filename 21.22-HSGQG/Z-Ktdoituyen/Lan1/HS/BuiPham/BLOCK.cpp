#include <bits/stdc++.h>

using namespace std;

const int inf = 0x3f3f3f3f;

int n , k , a[100010] , f[2][100010] , mi[100010] , cost[100010] , dp[110][110];

void solve1() {
    memset(dp,inf,sizeof(dp));
    dp[0][0] = 0;
    for (int j = 1 ; j <= k ; ++j) {
        for (int i = 1 ; i <= n ; ++i) {
            int ma = 0;
            for (int pos = i ; pos > 0 ; --pos) {
                ma = max(ma , a[pos]);
                dp[i][j] = min(dp[i][j] , dp[pos - 1][j - 1] + ma);
            }
        }
    }
    cout << dp[n][k] << '\n';
}

void solve2() {
    int cur = 0;
    memset(f,inf,sizeof(f));
    f[0][0] = 0;
    for (int j = 1 ; j <= k ; ++j) {
        cur ^= 1;
        deque < int > dq;
        dq.push_back(0);
        mi[0] = inf;
        f[cur][0] = inf;
        for (int i = 1 ; i <= n ; ++i) {
            int val = a[i] + f[cur ^ 1][i - 1];
            while (dq.back() != 0 && a[dq.back()] <= a[i]) {
                val = min(val , cost[dq.size() - 1] - a[dq.back()] + a[i]);
                dq.pop_back();
            }
            dq.push_back(i);
            cost[dq.size() - 1] = val;
            mi[dq.size() - 1] = min(mi[dq.size() - 2] , val);
            f[cur][i] = mi[dq.size() - 1];
        }
    }
    cout << f[cur][n];
}

int main() {
    freopen("BLOCK.inp","r",stdin);
    freopen("BLOCK.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> k;
    for (int i = 1 ; i <= n ; ++i) cin >> a[i];
    if (n <= 100) solve1();
    else solve2();
}
