#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll , ll>

const ll N = 1e5 + 5 , inf = 1e15;

void file() {
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll n , s , par[N][25] , D[N] , h[N] , c[N] , w[N] , p[N] , need[N] , f[N] , d[N][17];
vector<pi> adj[N];

int Bit(int x , int k) {
	return (x >> k) & 1;
}

void Dfs(int u , int pa) {
	par[u][0] = pa;
	for(int i = 1 ; i < 20 ; i++) par[u][i] = par[par[u][i - 1]][i - 1];
	for(auto x : adj[u]) {
		ll v = x.fi , dist = x.se;
		if(v == pa) continue;
		D[v] = D[u] + dist;
		h[v] = h[u] + 1;
		Dfs(v , u);
	}
}

int lca(int u , int v) {
	if(h[u] < h[v]) swap(u , v);
	if(v == 1) return 1;
	for(int i = 19 ; i >= 0 ; i--) if((h[u] - (1 << i)) >= h[v]) u = par[u][i];
	if(u == v) return u;
	for(int i = 19 ; i >= 0 ; i--) 
		if(par[u][i] != par[v][i]) u = par[u][i] , v = par[v][i];
	return par[u][0];
}

ll Dist(int u , int v) {
	return D[u] + D[v] - 2 * D[lca(u , v)];
}

bool check(ll val) {
	memset(f , 0 , sizeof(f));
	for(int i = 1 ; i <= n ; i++) {
		int mask = 0;
		for(int j = 0 ; j < s ; j++) {
			if(d[i][j] <= val) mask += (1 << j);
		}
		f[mask] += p[i];
	}
	for(int i = 0 ; i < s ; i++)
	 for(int mask = (1 << s) - 1 ; mask >= 1 ; mask--)
	  if(Bit(mask , i)) f[mask ^ (1 << i)] += f[mask];
	  
	for(int i = 1 ; i < (1 << s) ; i++) if(!(__builtin_popcount(i) & 1)) f[i] = -f[i];
	
	for(int i = 0 ; i < s ; i++)
	 for(int mask = 1 ; mask < (1 << s) ; mask++)
	  if(!Bit(mask , i)) f[mask ^ (1 << i)] += f[mask];
	for(int i = 1 ; i < (1 << s) ; i++) if(f[i] < need[i]) return false;
	return true;
}

void Binary() {
	ll l = 0 , r = inf , g , ans;
	while(l <= r) {
		g = (l + r) / 2;
		if(check(g)) ans = g , r = g - 1;
		else l = g + 1;
	}
	cout << ans;
}

int main() {
	file();
 	cin >> n >> s;
 	for(int i = 1 ; i <= n ; i++) cin >> p[i];
 	for(int i = 0 ; i < s ; i++) cin >> c[i];
 	for(int i = 0 ; i < s ; i++) cin >> w[i];
 	for(int i = 1 ; i < n ; i++) {
 		ll u , v , duv;
 		cin >> u >> v >> duv;
 		adj[u].pb({v , duv});
 		adj[v].pb({u , duv});
	}
	Dfs(1 , 0);
	for(int i = 1 ; i <= n ; i++)
	 for(int j = 0 ; j < s ; j++)
	   d[i][j] = Dist(i , c[j]);
	 
	for(int i = 1 ; i < (1 << s) ; i++) 
		for(int j = 0 ; j < s ; j++) if(Bit(i , j)) need[i] += w[j];
	Binary();
	return 0;
}
