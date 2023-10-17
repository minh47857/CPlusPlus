#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back

const ll N = 1e5 + 5 , MOD = 1e9 + 7 , inf = 1e15;

void file() {
    freopen("EDGES.inp" , "r" , stdin);
	freopen("EDGES.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , m1 , m2 , Time = 0 , S , T , scc = 0 , low[N] , num[N] , par[N] , dlt[N] , deg[N];
ll d[N] , ans = 0;
vector<pi> Edge , A[N]; 
vector<int> adj[N];
stack<int> st;

void Tarjan(int u) {
	st.push(u);
	low[u] = num[u] = ++Time;
	for(auto v : adj[u]) if(!dlt[v]) {
		if(num[v]) low[u] = min(low[u] , num[v]);
		else {
			Tarjan(v);
			low[u] = min(low[u] , low[v]);
		}
	}
	if(low[u] == num[u]) {
		scc++;
		int v;
		do {
			v = st.top();
			st.pop();
			dlt[v] = 1;
			par[v] = scc;
		} while(v != u);
	}
}

void Dijkstra(int u) {
	priority_queue< pi , vector<pi> , greater<pi> > heap;
	for(int i = 1 ; i <= scc ; i++)
		d[i] = inf;
	d[u] = 0 , heap.push({d[u] , u});
	while(heap.size()) {
		ll u = heap.top().se , du = heap.top().fi;
		heap.pop();
		if(du != d[u]) continue;
		for(auto x : A[u]) {
			ll v = x.fi , w = x.se;
			if(d[v] > d[u] + w) 
				d[v] = d[u] + w , heap.push({d[v] , v});
		}
	}
	if(d[S] == inf) 	cout << "NO";
	else cout << "YES\n" << ans + d[S];
}

int main() {
	file();
	cin >> n >> m1;
	for(int i = 1 ; i <= m1 ; i++) {
		int u , v;
		cin >> u >> v;
		adj[u].pb(v);
		Edge.pb({u , v});
	}
	for(int i = 1 ; i <= n ; i++) 
		if(!num[i]) Tarjan(i);
	for(int i = 0 ; i < Edge.size() ; i++) 
		Edge[i] = {par[Edge[i].fi] , par[Edge[i].se]};
	for(auto x : Edge) 	
		if(x.fi != x.se) A[x.fi].pb({x.se , 0}) , deg[x.se]++;
	for(int i = 1 ; i <= scc ; i++) {
		if(!deg[i] && A[i].size()) S = i;
		if(!A[i].size() && deg[i]) T = i;
	}
	cin >> m2;
	for(int i = 1 , u , v , w ; i <= m2 ; i++) {
		cin >> u >> v >> w;
		if(w < 0) {
			ans += w;
			w = 0;
		}
		A[par[u]].pb({par[v] , w});
	}
	Dijkstra(T);
	return 0;
}
