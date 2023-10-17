#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define eps 1e-6
#define pi pair<int , int>

const int N = 15e4 , MOD = 1e9 + 7 , inf = 1e9 + 7;

using namespace std;

void file() {
	freopen("drumuri.inp" , "r" , stdin);
	freopen("drumuri.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int n , m , num[N] , low[N] , Time = 0 , ans[2][N] , vis[N] , deg[N] , dlt[N] , root[N] , scc;
vector<int> res , topo , adj[N] , g[2][N];
vector<pi> edge;
stack<int> st;

void Dfs(int u) {
	num[u] = low[u] = ++Time;
	st.push(u);
	for(int v : adj[u]) {
		if(dlt[v]) continue;
		if(!num[v]) {
			Dfs(v);
			low[u] = min(low[u] , low[v]);
		}
		else low[u] = min(low[u] , num[v]);
	}
	if(low[u] == num[u]) {
		scc++;
		int v;
		do {
			v = st.top();
			dlt[v] = 1;
			root[v] = scc;
			st.pop();
		} while(u != v);
	}
}

void go(int u , int id) {
	vis[u] = 1;
	for(int v : g[id][u]) {
		if(!vis[v])
			go(v , id);
	}
	topo.pb(u);
}

void solve(int id) {
	memset(deg , 0 , sizeof(deg));
	int cnt = 0;
	reverse(topo.begin() , topo.end());
	for(int i = 1 ; i <= topo.size() ; i++) {
		int u = topo[i - 1];
		for(auto v : g[1 - id][u]) {
			if(!deg[v]) deg[v]++ , cnt++;
		}
		if(cnt == i - 1) ans[id][u] = 1;
	}
}

int main() {
	file();
	cin >> n >> m;
	for(int i = 1 ; i <= m ; i++) {
		int u , v ; cin >> u >> v;
		adj[u].pb(v);
		edge.pb({u , v});
	}
	for(int i = 1 ; i <= n ; i++)
		if(!num[i]) Dfs(i);
	for(auto x : edge) {
		if(root[x.fi] == root[x.se]) continue;
		g[0][root[x.fi]].pb(root[x.se]);
		g[1][root[x.se]].pb(root[x.fi]);
	}
	memset(vis , 0 , sizeof(vis));
	for(int i = 1 ; i <= scc ; i++)
		if(!vis[i]) go(i , 0);
	solve(0);
	solve(1);
	for(int i = 1 ; i <= n ; i++) 
		if(ans[0][root[i]] && ans[1][root[i]]) res.pb(i);
	cout << res.size() << '\n';
	for(auto x : res) cout << x << ' ';
	return 0;
}


