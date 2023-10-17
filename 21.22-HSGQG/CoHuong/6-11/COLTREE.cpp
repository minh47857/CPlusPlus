#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back

const int N = 1e5 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
    freopen("COLTREE.inp" , "r" , stdin);
	freopen("COLTREE.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , m , r , id[N] , c[N] , f[N];
set<int> s[N];
vector<int> G[N];

void Dfs(int u , int p) {
	int t = id[u];
	for(auto v : G[u]) if(v != p) {
		Dfs(v , u);
		if(s[id[v]].size() > s[t].size()) t = id[v];
	}
	id[u] = t;
	for(auto v : G[u]) if(v != p && id[u] != id[v]) {
		for(auto x : s[id[v]]) s[id[u]].insert(x);
	}
	s[id[u]].insert(c[u]);
	f[u] = s[id[u]].size();
}

int main() {
	file();
	cin >> n >> m >> r;
	for(int i = 1 ; i <= n ; i++) id[i] = i;
	for(int i = 1 ; i < n  ; i++) {
		int u , v;
		cin >> u >> v;
		G[u].pb(v);
		G[v].pb(u);
	}
	for(int i = 1 ; i <= n ; i++) cin >> c[i];
	Dfs(r , 0);
	for(int i = 1 , x; i <= m ; i++) 
	   cin >> x , cout << f[x] << '\n';
	   return 0;
}


