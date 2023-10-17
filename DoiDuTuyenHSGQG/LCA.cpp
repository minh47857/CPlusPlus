// cach 1
void dfs(ll u , ll preu)
{
    for (auto v : adj[u])
	{
        if (v == preu) continue;
        trace[v] = trace[u] + 1;
        Spar[v][0] = u;
        dfs(v , u);
    }
}
void build()
{
	for (ll j = 1 ; (1 << j) < n ; ++j)
	for (ll i = 1 ; i <= n ; ++i) 
		Spar[i][j] = Spar[Spar[i][j - 1]][j - 1];
}
int Lca(int x , int y)
{
    if(trace[x] >= trace[y]) swap(x , y);
    int k = (int)log2(trace[y]);
  //  cout<<x<<' '<<y<<' ';
    for(int i = k ; i >= 0 ; i--)
    {
        if(trace[y] -  (1 << i) >= trace[x])
            y = Spar[y][i];
    }
    if(y == x) return x;
    k = (int) log2(trace[y]);
    for(int i = k ; i >= 0 ; i--)
    {
        if(Spar[x][i] != Spar[y][i])
        {
            x = Spar[x][i];
            y = Spar[y][i];
        }
    }
    return Spar[x][0];
}







 // cach 2
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ms(d, i) memset(d, i, sizeof d)
#define pb push_back
//////////////piM//////////////////

const int N = 1e5 + 5;

int n, m, u, v, x, y;
vector<int> a[N];
int trace[N], p[N][25];

void in()
{
    cin >> n >> m;
    for(int i = 1; i <= n - 1; ++i) cin >> u >> v, a[u].pb(v), a[v].pb(u);
}
void DFS(int u)
{
    for(int i = 0; i < a[u].size(); ++i)
    {
        int v = a[u][i];
        if(trace[v] == -1)
        {
            trace[v] = trace[u] + 1;
            p[v][0] = u;
            for(int t = 1; t <= 19; ++t)
            {
                if((1 << t) > trace[v]) break;
                int e = p[v][t - 1];
                p[v][t] = p[e][t - 1];
            }
            DFS(v);
        }
    }
}
int lca(int x, int y)
{
    for(int i = 19; i >= 0; --i)
    {
        if(trace[p[x][i]] >= trace[y])
            x = p[x][i];
    }
    for(int i = 19; i >= 0; --i)
    {
        if(trace[p[y][i]] >= trace[x])
            y = p[y][i];
    }
    for(int i = 19; i >= 0; --i)
    {
        if(p[x][i] != p[y][i])
        {
            x = p[x][i];
            y = p[y][i];
        }
    }
    while(x != y) x = p[x][0], y = p[y][0];
    return x;
}
void solve()
{
    memset(trace, -1, sizeof trace); trace[1] = 0;
    DFS(1);
    for(int i = 1; i <= m; ++i)
    {
        cin >> x >> y;
        cout << lca(x, y) << '\n';
    }
    return;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    if(fopen(".inp", "r"))
    {
        freopen(".inp", "r", stdin);
        freopen(".out", "w", stdout);
    }
	in();
	solve();
	return 0;
}
