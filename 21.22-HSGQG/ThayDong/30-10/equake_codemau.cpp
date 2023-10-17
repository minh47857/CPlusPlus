#include<bits/stdc++.h>
#define int long long
#define x first
#define y second
#define bug(x) cerr<<#x<<" = "<<x<<'\n'

using namespace std;
using ll = long long;

typedef pair<int, int> ii;

const int maxn = 100005;
const ll INF = 1e15;

int N, S;
int P[maxn], C[maxn], W[maxn];
int par[maxn][20], H[maxn];
ll dist[maxn];
vector<ii> G[maxn];

void dfs(int u, int p = 0) {
  par[u][0] = p;
  for (int i = 1; i < 20; ++i)
    par[u][i] = par[par[u][i - 1]][i - 1];
  for (ii e : G[u]) if (e.x != p) {
    dist[e.x] = dist[u] + e.y;
    H[e.x] = H[u] + 1;
    dfs(e.x, u);
  }
}

int jump(int u, int h) {
  for (int i = 0; i < 20; ++i) if (h >> i & 1)
    u = par[u][i];
  return u;
}

int lca(int u, int v) {
  if (H[u] < H[v]) swap(u, v);
  u = jump(u, H[u] - H[v]);
  if (u == v) return u;
  for (int i = 19; i >= 0; --i)
    if (par[u][i] != par[v][i])
      u = par[u][i], v = par[v][i];
  return par[u][0];
}

ll d(int u, int v) {
  return dist[u] + dist[v] - 2 * dist[lca(u, v)];
}

ll need[(1 << 15)], F[(1 << 15)];
ll Dist[maxn][16];

bool ok(ll val) {
  memset(F, 0, sizeof F);
  
  for (int i = 1; i <= N; ++i) {
    int msk = 0;
    for (int j = 0; j < S; ++j)
      if (Dist[i][j] <= val)
        msk += (1 << j);
    F[msk] += P[i];
  }
  
  for (int i = 0; i < S; ++i)
    for (int msk = (1 << S) - 1; msk > 0; --msk)
      if (msk >> i & 1)
        F[msk ^ (1 << i)] += F[msk];
        
  for (int msk = 0; msk < (1 << S); ++msk)
    if (!(__builtin_popcount(msk) & 1))
      F[msk] = -F[msk];
      
  for (int i = 0; i < S; ++i)
    for (int msk = 1; msk < (1 << S); ++msk)
      if (!(msk >> i & 1))
        F[msk ^ (1 << i)] += F[msk];
        
  for (int msk = 1; msk < (1 << S); ++msk)
    if (F[msk] < need[msk])
      return false;
      
  return true;
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
//  freopen("equake.inp", "r", stdin);
//  freopen("equake.out", "w", stdout);
  cin >> N >> S;
  for (int i = 1; i <= N; ++i) cin >> P[i];
  for (int i = 1; i <= S; ++i) cin >> C[i];
  for (int i = 1; i <= S; ++i) cin >> W[i];
  for (int u, v, w, i = 1; i < N; ++i) {
    cin >> u >> v >> w;
    G[u].push_back({v, w});
    G[v].push_back({u, w});
  }
  dfs(1);
  for (int i = 1; i <= N; ++i)
    for (int j = 0; j < S; ++j)
      Dist[i][j] = d(i, C[j + 1]);
  for (int msk = 0; msk < (1 << S); ++msk)
    for (int i = 0; i < S; ++i) if (msk >> i & 1)
      need[msk] += W[i + 1];
  ll lo = 0, hi = INF, ans = INF;
  while (lo <= hi) {
    ll mi = (lo + hi) >> 1;
    if (ok(mi)) {
      ans = mi;
      hi = mi - 1;
    } else
      lo = mi + 1;
  }
  cout << ans << '\n';
}
