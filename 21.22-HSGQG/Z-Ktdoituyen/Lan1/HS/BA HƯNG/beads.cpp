#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 3;
int n;
int dp[N][2][2];
typedef pair < int, int > ii;
vector < ii > adj[N];

void dfs(int i, int j)
{
    dp[i][0][0] = 0;
    if (adj[i].size() > 1) dp[i][0][1] = 0;

    for (ii cur : adj[i])
    {
        int u = cur.first;
        int w = cur.second;
        if (u == j) continue;
        dfs(u, i);

        dp[i][0][0] += max({dp[u][0][0], dp[u][1][1], dp[u][0][1]});
        dp[i][0][1] += max({dp[u][1][1], dp[u][0][0], dp[u][1][0] + w});

        //if (i == 1) cout << dp[i][1][1] + max({dp[u][0][0] + dp[u][1][1] + dp[u][1][0] + w}) << '\n';

        dp[i][1][1] = max(dp[i][1][1] + max({dp[u][0][0], dp[u][1][1], dp[u][1][0] + w}),
                          dp[i][1][0] + max({dp[u][1][1], dp[u][0][0], dp[u][0][1]}) + w);

        dp[i][1][0] = max(dp[i][1][0], dp[i][0][0] - max({dp[u][0][0], dp[u][1][1], dp[u][0][1]})
                                                   + max({dp[u][1][1], dp[u][0][0], dp[u][0][1]}) + w);

        dp[i][1][0] = max(dp[i][1][0], dp[i][0][1] - max({dp[u][1][1], dp[u][0][0], dp[u][1][0] + w})
                                                   + max({dp[u][1][1], dp[u][0][0], dp[u][0][1]}) + w);

        //if (i == 1) cout << i << " " << dp[i][1][0] << " " << dp[i][1][1] << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("beads.inp","r",stdin); freopen("beads.out","w",stdout);

    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    for (int i = 1; i <= n; i++)
        dp[i][1][1] = dp[i][1][0] = -1e6,
        dp[i][0][1] = dp[i][0][0] = -1e6;

    dfs(1, 0);

//    for (int i = 1; i <= n; i++)
//        cout << i << " " << dp[i][0][0] << " "
//             << dp[i][0][1] << " " << dp[i][1][0] << " " << dp[i][1][1] << '\n';

    cout << max({dp[1][0][0], dp[1][0][1], dp[1][1][1]});
}
