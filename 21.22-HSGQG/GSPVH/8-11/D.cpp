#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back

const int N = 5e5 + 5;

void file() {
    freopen("mst.inp" , "r" , stdin);
	freopen("mst.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

struct mst {
	int x , y , w , id;
	bool operator < (const mst&s) const {return w < s.w;}
} E[N];

int n , m , t , par[N] , h[N] , g[N][20] , f[N][20] , ans[N] , s[N] , Mst[N];
vector<mst> G[N];

int parent(int u) {
	if(par[u] < 0) return u;
	par[u] = parent(par[u]);
	return par[u];
}

int par2(int u) {
	if(par[u] != u) par[u] = par2(par[u]);
	return par[u];
}

bool merge(int x , int y) {
	if((x = parent(x)) == (y = parent(y))) return false;
	if(par[x] > par[y]) swap(x , y);
	par[x] += par[y];
	par[y] = x;
	return true;
}

void Dfs(int u , int p) {
	for(int i = 1 ; i <= 19 ; i++) 
	    f[u][i] = f[f[u][i - 1]][i - 1],
	    g[u][i] = max(g[u][i - 1] , g[f[u][i - 1]][i - 1]);
	for(auto x : G[u]) if(x.x != p) {
		f[x.x][0] = u;
		g[x.x][0] = x.w;
		s[x.x] = x.id;
		h[x.x] = h[u] + 1;
		Dfs(x.x , u);
	}
}

pi Get(int x , int y) {
	int res = 0;
	if(h[x] < h[y]) swap(x , y);
	for(int i = 19 ; i >= 0 ; i--) 
		if(h[f[x][i]] >= h[y]) 
		    res = max(res , g[x][i]), 
			x = f[x][i];
	if(x == y) return {x , res};
	for(int i = 19 ; i >= 0 ; i--) 
		if(f[x][i] != f[y][i]) {
			res = max({res , g[x][i] , g[y][i]});
			x = f[x][i] , y = f[y][i];
	}	   
	res = max({res , g[x][0] , g[y][0]});
	return {f[x][0] , res};
}

int main() {
	file();
	cin >> t >> n >> m;
	memset(par , -1 , sizeof(par));
	for(int i = 1 ; i <= m ; i++) {
		cin >> E[i].x >> E[i].y >> E[i].w;
		E[i].id = i;
	}
	sort(E + 1 , E + m + 1);
	for(int i = 1 ; i <= m ; i++) 
		if(merge(E[i].x , E[i].y)) {
			G[E[i].x].pb({E[i].y , 0 , E[i].w , E[i].id});
			G[E[i].y].pb({E[i].x , 0 , E[i].w , E[i].id});
			Mst[i] = 1;
		}
	h[1] = 1;
	Dfs(1 , 0);
	for(int i = 1 ; i <= n ; i++) par[i] = i;
	for(int i = 1 ; i <= m ; i++) 	if(!Mst[i]) {
	pi	t = Get(E[i].x , E[i].y);
	int u = par2(E[i].x) , v = par2(E[i].y);
		ans[E[i].id] = t.se;
		while(h[u] > h[t.fi]) {
		   par[u] = f[u][0];
		   ans[s[u]] = E[i].w;
		   u = par2(u);
		}
		while(h[v] > h[t.fi]) {
		   par[v] = f[v][0];
		   ans[s[v]] = E[i].w;
		   v = par2(v);
		}
	}
	
	for(int i = 1 ; i <= m ; i++) cout << ans[i] - 1 << ' ';
	return 0;
}


