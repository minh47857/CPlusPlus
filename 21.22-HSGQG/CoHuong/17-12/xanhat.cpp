#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 1e5 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

int n , g[N];
pi f[N][5];
vector<int> G[N];

void file() {
	freopen("xanhat.inp" , "r" , stdin);
	freopen("xanhat.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

void Dfs1(int u , int par) {
	for(auto v : G[u]) {
		if(v == par) continue;
		Dfs1(v , u);
		if(f[v][0].fi + 1 >= f[u][0].fi) {
			f[u][1] = f[u][0];
			f[u][0] = {f[v][0].fi + 1 , v};
		}
		else if(f[v][0].fi + 1 >= f[u][1].fi) f[u][1] = {f[v][0].fi + 1 , v};
	}
}

void Dfs2(int u , int par) {
	if(u != 1) {
		int tmp = 0;
		if(f[par][0].se != u) tmp = f[par][0].fi;
		else tmp = f[par][1].fi;
		g[u] = max(g[par] , tmp) + 1;
	}
	for(auto v : G[u]) 
		if(v != par) Dfs2(v , u);
}

int main() {
	file();
	cin >> n;
	for(int i = 1 , u , v ; i < n ; i++) {
		cin >> u >> v;
		G[u].pb(v);
		G[v].pb(u);
	}
	Dfs1(1 , 0);
	Dfs2(1 , 0);
	for(int i = 1 ; i <= n ; i++)
		cout << max(g[i] , f[i][0].fi) << '\n';
	return 0;
}

