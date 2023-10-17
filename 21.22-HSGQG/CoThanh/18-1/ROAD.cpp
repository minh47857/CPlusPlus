#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define eps 1e-6
#define pi pair<int , int>

const int N = 1e3 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

using namespace std;

void file() {
	freopen("ROAD.inp" , "r" , stdin);
	freopen("ROAD.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int n , m , num[N] , low[N] , deg[N] , cnt , cmp , bridge[N] , Time , root[N];
vector<pi> g[N] , edge;
vector<int> adj[N];

void Dfs1(int u , int pa) {
	num[u] = low[u] = ++Time;
	for(auto x : g[u]) {
		int v = x.fi , id = x.se;
		if(v == pa) continue;
		if(num[v]) low[u] = min(low[u] , num[v]);
		else {
			Dfs1(v , u);
			low[u] = min(low[u] , low[v]);
			if(low[v] == num[v])  bridge[id] = true;
		}
	}
}

void Dfs2(int u) {
	root[u] = cmp;
	for(auto v : adj[u]) 
		if(!root[v]) Dfs2(v);
}

int main() {
	file();
	cin >> n >> m;
	for(int i = 1 ; i <= m ; i++) {
		int u , v;
		cin >> u >> v;
		g[u].pb({v , i - 1}) , g[v].pb({u , i - 1});
		edge.pb({u , v});
	}
	Dfs1(1 , 0);
	for(int i = 0 ; i < edge.size() ; i++) 
		if(!bridge[i]) {
			adj[edge[i].fi].pb(edge[i].se);
			adj[edge[i].se].pb(edge[i].fi);
		}
	for(int i = 1 ; i <= n ; i++) 
		if(!root[i]) {
			cmp++;
			Dfs2(i);
		}
	for(int i = 0 ; i < edge.size() ; i++) 
		if(bridge[i]) {
			int u = edge[i].fi , v = edge[i].se;
			deg[root[u]]++;
			deg[root[v]]++;
		}
	for(int i = 1 ; i <= cmp ; i++) cnt += (deg[i] == 1);
	cout << (cnt + 1) / 2;
	return 0;
}


