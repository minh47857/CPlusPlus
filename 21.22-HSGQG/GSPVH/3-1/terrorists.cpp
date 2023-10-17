#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>
#define pil pair<ll , int> 

const int N = 1e5 + 5 , inf = 2e9;

void file() {
    freopen("terrorists.inp" , "r" , stdin);
    freopen("terrorists.out" , "w" , stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int t , n , m , q ,  h[N] , dtree[N] , d[N] , p[N][25] , par[N];
int dist[105][N];
vector<pi> adj[N] , nadj[N];
vector<int> vertex;

int parent(int u) {
    if(par[u] < 0) return u;
    par[u] = parent(par[u]);
    return par[u];
}

bool merge(int u , int v ) {
    if( (u = parent(u)) == (v = parent(v)) ) return false;
    if(par[u] > par[v]) swap(u , v);
    par[u] += par[v];
    par[v] = u;
    return true;
}

void Dfs(int u , int pa) {
    for(int i = 1 ; i <= 20 ; i++) 
		p[u][i] = p[p[u][i - 1]][i - 1];
    for(auto x : nadj[u]) {
        int v = x.fi , w = x.se; 
        if(v == pa) continue;
        p[v][0] = u;
        h[v] = h[u] + 1;
        dtree[v] = dtree[u] + w;
        Dfs(v , u);
    }
}

int lca(int u , int v) {
    if(u == 1 || v == 1) return 1;
    if(h[u] < h[v]) swap(u , v);
    for(int i = 20 ; i >= 0 ; i--) 
		if(h[p[u][i]] >= h[v]) u = p[u][i];
    if(u == v) return u;
    for(int i = 20 ; i >= 0 ; i--) 
		if(p[u][i] != p[v][i]) u = p[u][i] , v = p[v][i];
    return p[u][0];
}

void dijkstra(int s , int id) {
    priority_queue<pil , vector< pil >, greater< pil >> heap;
    for(int i = 0; i <= n; ++i) dist[id][i] = inf;
    dist[id][s] = 0; heap.push({0, s});
    while(!heap.empty()) {
        int u = heap.top().se;
        int du = heap.top().fi;
        heap.pop();
        if(du != dist[id][u]) continue;
        for(auto x : adj[u]) {
            int v = x.fi , w = x.se;
           if( dist[id][v] > du + w) 
		   dist[id][v] = du + w , heap.push( {dist[id][v] , v});
        }
    }  
}

void solve() {
	cin >> n >> m >> q;
  memset(par , -1 , sizeof(par));
  memset(d , 0 , sizeof(d));
  for(int i = 1 ; i <= n ; i++)  adj[i].clear() , nadj[i].clear();
  vertex.clear();
  
  for (int i = 1 ; i <= m ; i++) {
      int u , v , w;
      cin >> u >> v >> w;
      adj[u].pb({v , w});
      adj[v].pb({u , w});
      if(merge(u , v)) nadj[u].pb({v , w}) , nadj[v].pb({u , w});
      else {
        if(!d[u]) vertex.pb(u) , d[u] = 1;
      if(!d[v])  vertex.pb(v) , d[v] = 1;   
    }
  }
  h[1] = 0 , dtree[1] = 0;
  Dfs(1 , 0);
  for(int i = 0 ; i < vertex.size() ; i++) dijkstra(vertex[i] , i);
  for (int i = 1 ; i <= q ; i++) {
      int u , v;
      cin >> u >> v;
      int ans = dtree[u] + dtree[v] - 2 * dtree[lca(u , v)];
      for(int i = 0 ; i <  vertex.size() ; i++) 
	  	ans = min(ans , dist[i][u] + dist[i][v]);
      cout << ans << '\n';
  }
}

int main() {
    file();
    cin >> t;
    while(t--) 
    	solve();
    return 0;
}

