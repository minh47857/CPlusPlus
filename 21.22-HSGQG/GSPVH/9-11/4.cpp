#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const ll N = 3e5 + 5 , MOD = 998244353;

void file() {
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll n , m , C[N] , par[N] , vis[N] , low[N] , num[N] , sz[N] , bridge[N] , joint[N] , used[N] , base = 0 , root , Time = 0;
vector<pi> G[N];

void Find(int u) {
	for(auto x : G[u]) if(!vis[x.fi]) {
		vis[x.fi] = 1;
		par[x.fi] = root;
		C[root]++;
		Find(x.fi);
	}
}

void Dfs(int u , int p) {
	vector<int> E;
	int child = 0 , ok = 0;
	ll sum = 0;
	num[u] = low[u] = ++Time;
	sz[u] = 1;
	for(auto x : G[u]) if(!used[x.se]) {
		int v = x.fi , id = x.se;
		used[x.se] = 1;
		if(num[v]) low[u] = min(num[v] , low[u]);
		else {
		    child++;
			Dfs(v , p);
			sz[u] += sz[v];
			low[u] = min(low[u] , low[v]);
			if(low[v] == num[v]) bridge[id] = sz[v] * (C[p] - sz[v]) ;
			if(u == p) {
				if(child > 1) ok = 1;
				E.pb(sz[v]);
			}
			else if(low[v] >= num[u]) ok = 1 , E.pb(sz[v]);
		} 
	}
	if(ok) {
		for(auto v : E) sum += v;
		E.pb(C[p] - sum - 1);
		sum = 0;
		for(auto v : E) {
			joint[u] = joint[u] + sum * v;
			sum += v;
		}
	}
}

int main() {
	file();
	cin >> n >> n >> m;
	for(int i = 1 , u , v ; i <= m ; i++) {
		cin >> u >> v;
		G[u].pb({v , i});
		G[v].pb({u , i});
	}
	ll sum = 0;
	vector<int> E;
	for(int i = 1 ; i <= n ; i++) {
		if(vis[i]) continue;
		par[i] = i;
		E.pb(i);
		root = i;
		C[i] = 1;
		vis[i] = 1;
		Find(i);
	}
	for(auto v : E) {
		base = base + sum * C[v];
		sum += C[v];
	}
	for(int i = 1 ; i <= n ; i++) if(!num[i]) Dfs(i , i);
	for(int i = 1 ; i <= n ; i++) cout << (joint[i] + base - n + C[par[i]]) % MOD << ' ';
	cout << '\n';
	for(int i = 1 ; i <= m ; i++) cout << (bridge[i] + base) % MOD << ' ';
	return 0;
}

