#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 2e5 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll n , c[N] , d[N] , ans = 0 , dp[N] , par[N][25] , cnt[N] , h[N];
vector<pi> G[N];

void Dfs(int u , int pa) {
	for(int i = 1 ; i <= 20 ; i++) par[u][i] = par[par[u][i - 1]][i - 1];
	for(auto x : G[u]) if(x.fi != pa) {
		par[x.fi][0] = u;
		h[x.fi] = h[u] + 1;
		Dfs(x.fi , u);
	}
}

int lca(int x , int y) {
	if(h[x] < h[y]) swap(x , y);
	for(int i = 20 ; i >= 0 ; i--) if(h[par[x][i]] >= h[y]) x = par[x][i];
	if(x == y) return x;
	for(int i = 20 ; i >= 0 ; i--) 
		if(par[x][i] != par[y][i]) x = par[x][i] , y = par[y][i];
	return par[x][0];
}

void Get(int u , int pa , int id) {
	for(auto x : G[u]) if(x.fi != pa) {
		Get(x.fi , u , x.se);
		dp[u] += dp[x.fi];
	}
	if(id != -1) cnt[id] = dp[u];
}

int main() {
	file();
	cin >> n;
	for(int i = 1 ; i < n ; i++) {
		int u , v;
		cin >> u >> v >> c[i] >> d[i];
		G[u].pb({v , i});
		G[v].pb({u , i});
	}
	h[1] = 1;
	Dfs(1 , 0);
	for(int i = 1 ; i < n ; i++) 
	   dp[i]++ , dp[i + 1]++ , dp[lca(i , i  + 1)] -= 2;
	Get(1 , 0 , -1);
	for(int i = 1 ; i < n ; i++) ans = ans + min(cnt[i] * c[i] , d[i]);
	cout << ans;
	return 0;
}

