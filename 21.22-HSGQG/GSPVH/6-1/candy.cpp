#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define eps 1e-6
#define pi pair<int , int>

const int N = 5e2 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7 , M = 1e4 + 5;

using namespace std;

void file() {
	freopen("candy.inp" , "r" , stdin);
	freopen("candy.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

struct edge {
	int u , v , w;
};

int n , m , ans[M] , cnt[N];
ll f[N][N] , d[N][N];
vector<pi> G[N];
vector<edge> Edges;

void Dijkstra(int s) {
	priority_queue< pi , vector<pi> , greater<pi> > Q;
	for(int i = 1 ; i <= n ; i++)
		d[s][i] = inf , f[s][i] = 0;
	d[s][s] = 0 , f[s][s] = 1;
	Q.push({0 , s});
	while(Q.size()) {
		int u = Q.top().se , du = Q.top().fi;
		Q.pop();
		if(du != d[s][u]) continue;
		for(auto x : G[u]) {
			int v = x.fi , w = x.se;
			if(d[s][v] == d[s][u] + w) f[s][v] = (f[s][v] + f[s][u]) % MOD;
			else if(d[s][v] > d[s][u] + w) {
				d[s][v] = d[s][u] + w;
				f[s][v] = f[s][u];
				Q.push({d[s][v] , v});
			} 
		}
	}
}

int main() {
	file();
	cin >> n >> m;
	for(int i = 1 ; i <= m ; i++) {
		int u , v , w;
		cin >> u >> v >> w;
		Edges.pb({u , v , w});
		G[u].pb({v , w});
		G[v].pb({u , w});
	}
	for(int i = 1 ; i <= n ; i++) Dijkstra(i);
	for(int s = 1 ; s <= n ; s++) {
	//	cout << "S : " << s << '\n';
		for(int i = 1 ; i <= n ; i++) cnt[i] = 0;
		for(int v = 1 ; v <= n ; v++)
		  for(int t = s ; t <= n ; t++) 
		  	if(d[s][v] + d[v][t] == d[s][t] && f[s][v] * f[v][t] % MOD == f[s][t]) cnt[v]++;
		for(int i = 0 ; i < m ; i++) {
			int u = Edges[i].u , v = Edges[i].v , w = Edges[i].w;
			if(d[s][u] + w == d[s][v] && f[s][u] == f[s][v]) ans[i] += cnt[v];
			if(d[s][v] + w == d[s][u] && f[s][u] == f[s][v]) ans[i] += cnt[u];
		}
	//	cout << endl;
	}
	for(int i = 0 ; i < m ; i++) 
		cout << ans[i] << '\n';
	return 0;
}


