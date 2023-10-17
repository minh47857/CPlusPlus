#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl '\n'
#define bit(s, i) (s & (1<<i)

using namespace std;

const int inf = 2e9;
const int mod = 1e9 + 7;

typedef pair < int, int > ii;

int n, dp[200005][3];
vector < ii > adj[200005];

void dfs(int u, int p) {
    dp[u][0] = 0;
    for(auto x : adj[u]) {
        int v = x.fi, w = x.se;
        if(v == p) continue;
        dfs(v, u);
        int p = max({dp[v][2], dp[v][0], dp[v][1] + w});
        dp[u][2] = max(dp[u][2] + p, dp[u][1] + max(dp[v][0], dp[v][2]) + w);
        dp[u][1] = max(dp[u][1], dp[u][0] + max(dp[v][0], dp[v][2]) + w);
        dp[u][0] += p;
    }
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("Beads.inp", "r", stdin);
    freopen("Beads.out", "w", stdout);

    cin >> n;
    for(int i=1;i<n;++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
    memset(dp, -0x3f, sizeof dp);
    dfs(1, 0);
    cout << max(dp[1][0], dp[1][2]);
}

