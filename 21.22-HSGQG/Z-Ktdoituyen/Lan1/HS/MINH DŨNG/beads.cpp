#include<bits/stdc++.h>
#define x first
#define y second
#define bug(x) cout<<__LINE__<<": "<<#x<<" = "<<x<<'\n'

using namespace std;
using ll = long long;

const int maxn = 200100;
const ll INF = 1e18;

typedef pair<ll, ll> ii;

void maxx(ll &a, ll b) {
  if (a < b) a = b;
}

int N;
ll dp[maxn][2], ans = -INF;
vector<ii> G[maxn];

ii F[maxn][2];

void dfs(int u, int p = -1) {
  dp[u][0] = 0;
  dp[u][1] = -INF;
  ii a0 = {-INF, -1};
  ii a1 = {-INF, -1};
  for (ii e : G[u]) if (e.x != p) {
    int v = e.x;
    ll w = e.y;
    dfs(v, u);
    ll dp0, dp1;
    dp0 = dp[u][0] + max(w + dp[v][1], dp[v][0]);
    dp1 = max(dp[u][1] + max(w + dp[v][1], dp[v][0]),
              dp[u][0] + w + dp[v][0]);
    dp[u][0] = dp0;
    dp[u][1] = dp1;

    ll val = w + dp[v][0] - max(w + dp[v][1], dp[v][0]);

    if (val > a0.x) {
      a1 = a0;
      a0.x = val;
      a0.y = v;
    } else if (val > a1.x) {
      a1.x = val;
      a1.y = v;
    }
  }
  F[u][0] = a0;
  F[u][1] = a1;
}

void go(int u, int p, int w) {
  ll old_dp0 = dp[u][0], old_dp1 = dp[u][1];
  ii old_F0 = F[u][0], old_F1 = F[u][1];
  ll dp_p0, dp_p1;
  if (u != 1) {
    ll cost = max(w + dp[u][1], dp[u][0]);
    dp_p0 = dp[p][0] - cost;
    if (u != F[p][0].y) {
      dp_p1 = dp[p][1] - cost;
    } else {
      dp_p1 = dp_p0 + F[p][1].x;
    }
    {
      dp[u][1] = max(dp[u][1] + max(w + dp_p1, dp_p0),
                     dp[u][0] + w + dp_p0);
      dp[u][0] += max(w + dp_p1, dp_p0);
      ll val = w + dp_p0 - max(w + dp_p1, dp_p0);
      if (val > F[u][0].x) {
        F[u][1] = F[u][0];
        F[u][0].x = val;
        F[u][0].y = p;
      } else if (val > F[u][1].x) {
        F[u][1].x = val;
        F[u][1].y = p;
      }
    }
  }
//  cerr<<u<<'\n';
//  cerr<<dp[u][0]<<'\n';
//  cerr<<dp[u][1]<<'\n';
  ans = max(ans, dp[u][0]);
  for (ii e : G[u]) if (e.x != p)
    go(e.x, u, e.y);
  if (u != 1) {
    dp[u][0] = old_dp0;
    dp[u][1] = old_dp1;
    F[u][0] = old_F0;
    F[u][1] = old_F1;
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  freopen("beads.inp", "r", stdin);
  freopen("beads.out", "w", stdout);
  cin >> N;
  for (int u, v, w, i = 1; i < N; ++i) {
    cin >> u >> v >> w;
    G[u].push_back({v, w});
    G[v].push_back({u, w});
  }
//  for (int i = 1; i <= N; ++i) {
//    dfs(i);
////    bug(i);
////    bug(dp[i][0]);
////    bug(dp[i][1]);
//    //ans = max(ans, dp[i][0]);
//  }
  dfs(1);
  go(1, -1, -1);
  cout << ans << '\n';
  return 0;
}
