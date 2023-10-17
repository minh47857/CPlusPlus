#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define eps 1e-6
#define pi pair<int , int>

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

using namespace std;

void file() {
	freopen("dag.inp" , "r" , stdin);
	freopen("dag.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int n , m , c[N] , vis[N];
vector<pi> G[N];
bool check = false;

void Dfs(int u) {
	vis[u] = 1;
	for(auto x : G[u]) {
		int v = x.fi , id = x.se;
		if(vis[v] == 1) {
			check = true;
			continue;
		}
		else {
			c[id] = 1;
			if(!vis[v]) Dfs(v);
		}
	}
	vis[u] = 2;
}

int main() {
	file();
	cin >> n >> m;
	for(int i = 1 ; i <= m ; i++) {
		int u , v ; cin >> u >> v;
		if(u == v) {
			cout << -1;
			return 0;
		}
		G[u].pb({v , i});
		//G[v].pb({u , i});
	}
	for(int i = 1 ; i <= n ; i++)
		if(!vis[i]) Dfs(i);
	if(check) cout << 2 << '\n';
	else cout << 1 << '\n';
	for(int i = 1 ; i <= m ; i++) 
		cout << 2 - c[i] << ' ';
	return 0;
}


