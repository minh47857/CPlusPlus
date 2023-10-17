#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 2e5 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

int n , m , q , f[N] , d[N] , res[N] , c[N];
vector<pi> adj[N];

void Dijkstra() {
	queue<int> Q;
	for(int i = 1 ; i <= n ; i++)
		d[i] = inf , f[i] = 0;
	d[1] = 0 , f[1] = inf;
	Q.push(1);
	while(Q.size()) {
		int u = Q.front();
		Q.pop();
		for(auto x : adj[u]) {
			int v = x.fi , id = x.se;
			if(d[v] != inf) {
				if(d[u] + 1 == d[v]) 
					f[v] = max(min(f[u] , c[id]) , f[v]);
			}
			else 
				d[v] = d[u] + 1,
				f[v] = min(f[u] , c[id]),
				Q.push(v);
		}
	}
//	for(int i = 1 ; i <= n ; i++)
//		cout << i << ' ' << d[i] << ' ' << f[i] << '\n';
}

int main() {
	freopen("train.in" , "r" , stdin);
	freopen("train.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
	cin >> n >> m >> q;
	for(int i = 1 , u , v ; i <= m ; i++) {
		cin >> u >> v;
		adj[u].pb({v , i});
		adj[v].pb({u , i});
		c[i] = inf;
	}
	for(int i = 1 , x ; i <= q ; i++)
		cin >> x , c[x] = i;
	Dijkstra();
	for(int i = 2 ; i <= n ; i++)
		if(f[i] != inf) res[f[i]]++;
	for(int i = 1 ; i <= q ; i++)  {
		res[i] += res[i - 1],
		cout << res[i] << '\n';
	}	
	return 0;
	
}

