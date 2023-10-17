#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<ll , ll>
#define fi first
#define se second
#define pb push_back

const ll N = 1505 , MOD = 1e9 + 7 , M = 5005;

void file() {
    freopen("path.inp" , "r" , stdin);
	freopen("path.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

struct edge {
	int v , w , id;
};

ll n , m , g[N] , f[N] , ans[M] , d[N] , check[N];
vector<edge> adj[N];

void Dijkstra(int x) {
	priority_queue< pi , vector<pi> , greater<pi> > heap;
	memset(d , 0x3f , sizeof(d));
	memset(f , 0 , sizeof(f));
	memset(g , 0 , sizeof(g));
	memset(check , 0 , sizeof(check));
	vector<pi> S;
	d[x] = 0 , heap.push({0 , x});
	f[x] = 1;
	while(heap.size()) {
		int u = heap.top().se , du = heap.top().fi;
		if(!check[u]) check[u] = 1 , S.pb({0 , u}); 
		heap.pop();
		if(d[u] != du) continue;
		for(auto x : adj[u]) {
			ll v = x.v , w = x.w;
			if(d[v] > d[u] + w) d[v] = d[u] + w , heap.push({d[v] , v}) , f[v] = f[u];
			else if(d[v] == d[u] + w) f[v] = (f[v] + f[u]) % MOD;
		}
	}
	
	for(int i = 0 ; i < S.size() ; i++) S[i].fi = d[S[i].se];
	sort(S.begin() , S.end() , greater<pi>());
	for(auto x : S) {
		int u = x.se;
		for(auto p : adj[u]) {
			ll v = p.v , w = p.w;
			if(d[u] + w == d[v]) g[u] = (g[u] + g[v]) % MOD;
		}
		g[u] = (g[u] + 1) % MOD;
	}
	
	for(auto x : S) {
		int u = x.se;
		for(auto p : adj[u]) {
			ll v = p.v , w = p.w ;
			if(d[u] + w == d[v])ans[p.id] = (ans[p.id] + f[u] * g[v]) % MOD;
		}
	}
//	for(int i = 1 ; i <= n ; i++) cout << x << ' ' << i << ' ' << d[i] << ' ' << f[i] << ' ' << g[i] << '\n';	
}

int main() {
	file();
	cin >> n >> m;
	for(int i = 1 ; i <= m ; i++) {
		int u , v , w;
		cin >> u >> v >> w;
		adj[u].pb({v , w , i});
	}
	for(int i = 1 ; i <= n ; i++) Dijkstra(i);
	for(int i = 1 ; i <= m ; i++) cout << ans[i] << '\n';
	return 0;	
}


