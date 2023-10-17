#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll , ll>
const ll N = 100005 , MOD = 1e9 +7 , inf = 1e15;

void file()
{
    //freopen(".inp" , "r" , stdin);
    //freopen(".out" , "w" , stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll n , m , q ,  h[N] , dist[45][N] , dtree[N] , d[N] , p[N][30] , par[N];
vector<pi> adj[N] , nadj[N];
vector<int> vertex;

int parent(int u)
{
    if(par[u] < 0) return u;
    par[u] = parent(par[u]);
    return par[u];
}

bool merge(int u , int v )
{
    if( (u = parent(u)) == (v = parent(v)) ) return false;
    if(par[u] > par[v]) swap(u , v);
    par[u] += par[v];
    par[v] = u;
    return true;
}

void Dfs(int u , int pa)
{
    for(int i = 1 ; i <= log2(n) ; i++) p[u][i] = p[p[u][i - 1]][i - 1];
    
    for(auto x : nadj[u])
    {
        int v = x.fi , w = x.se; 
        if(v == pa) continue;
        p[v][0] = u;
        h[v] = h[u] + 1;
        dtree[v] = dtree[u] + w;
        Dfs(v , u);
    }
}

int lca(int u , int v)
{
    if(u == 1 || v == 1) return 1;
    if(h[u] < h[v]) swap(u , v);
    for(int i = log2(h[u]) ; i >= 0 ; i--) if(h[p[u][i]] >= h[v]) u = p[u][i];
    if(u == v) return u;
    for(int i = log2(h[u]) ; i >= 0 ; i--) if(p[u][i] != p[v][i]) u = p[u][i] , v = p[v][i];
    return p[u][0];
}

void dijkstra(int s , int id)
{
    priority_queue< pi , vector< pi >, greater< pi > > heap;
    for(int i = 0; i <= n; ++i) dist[id][i] = inf;
    dist[id][s] = 0; heap.push({0, s});
    while(!heap.empty())
    {
        ll u = heap.top().se;
        ll du = heap.top().fi;
        heap.pop();
        if(du != dist[id][u]) continue;
        for(auto x : adj[u])
        {
            ll v = x.fi;
            ll w = x.se;
           if( dist[id][v] > du + w) dist[id][v] = du + w , heap.push( {dist[id][v] , v});
        }
    }
 //  for (int i = 1; i <= n ; i++) cout << dist[i] << " ";   
}
int main()
{
    file();
  cin >> n >> m;
  memset(par , -1 , sizeof(par));
  
  for (int i = 1 ; i <= m ; i++)
  {
      int u , v , w;
      cin >> u >> v >> w;
      adj[u].pb({v , w});
      adj[v].pb({u , w});
      if(merge(u , v)) nadj[u].pb({v , w}) , nadj[v].pb({u , w});
      else
      {
        if(!d[u]) vertex.pb(u) , d[u] = 1;
      if(!d[v]) vertex.pb(v) , d[v] = 1;    
    }
  }
  
  h[1] = 0 , dtree[1] = 0;
  Dfs(1 , 0);
  for(int i = 0 ; i < vertex.size() ; i++) dijkstra(vertex[i] , i);
  
  cin >> q;
  for (int i = 1 ; i <= q ; i++)
  {
      int u , v;
      cin >> u >> v;
      ll ans = dtree[u] + dtree[v] - 2 * dtree[lca(u , v)];
      for(int i = 0 ; i <  vertex.size() ; i++) ans = min(ans , dist[i][u] + dist[i][v])    ;
    cout << ans << '\n';
  }
 return 0;
}

