#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int dp[N][5], tmp[5];
vector<pair<int, int>> adj[N];

/// 0 : chua lay canh ghep o u, 0
/// 1 : chua lay canh ghep o u, 1
/// 2 : co mot canh tu u chua ghep, 0
/// 3 : co mot canh tu u chua ghep, 1
/// 4 : co mot cap canh o u da ghep, 1

void dfs(int u, int p) {
    dp[u][0] = 0;
    for (auto e : adj[u]) {
        int v, w; tie(v, w) = e;
        if (v == p) continue; dfs(v, u);
        for (int j = 0; j < 5; j++)
            tmp[j] = dp[u][j];
        dp[u][0] = max(tmp[0] + dp[v][0], tmp[0] + dp[v][2] + w);
        dp[u][1] = max({tmp[0] + dp[v][1], tmp[0] + dp[v][3] + w,
        tmp[1] + dp[v][0], tmp[1] + dp[v][2] + w});
        dp[u][2] = max(tmp[0] + dp[v][0] + w, tmp[2] + dp[v][0]);
        dp[u][3] = max({tmp[0] + dp[v][1] + w,
        tmp[1] + dp[v][0] + w, tmp[3] + dp[v][0]});
        dp[u][4] = max({tmp[4] + dp[v][0], tmp[2] + dp[v][0] + w,
        tmp[2] + dp[v][1] + w, tmp[3] + dp[v][0] + w});
    }
    dp[u][1] = max(dp[u][1], dp[u][4]);
}

int main() {
    freopen("beads.inp", "r", stdin);
    freopen("beads.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    dfs(1, 0); cout << max(dp[1][0], dp[1][1]);
}
