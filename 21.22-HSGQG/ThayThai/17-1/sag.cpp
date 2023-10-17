#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define eps 1e-6
#define pi pair<int , int>

const int N = 1e5 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

using namespace std;

void file() {
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int n , k , m , nn , root[N] , vis[N] , f[N] , g[N];
vector<pi> edge;
vector<int> adj[N] , G[N] , nadj[N];

void find(int u) {
	root[u] = nn;
	for(auto v : G[u]) 
		if(!root[v]) find(v);
}

void dag(int u) {
	vis[u] = 1;
	for(auto v : adj[u]) {
		if(!vis[v]) dag(v);
		f[u] = max(f[u] , f[v] + 1);
		
	}
}

void ndag(int u) {
	vis[u] = 1;
	for(auto v : nadj[u]) {
		if(!vis[v]) ndag(v);
		g[u] = max(g[u] , g[v] + 1);
	}
}

int main() {
	file();
	cin >> n >> k >> m;
	for(int i = 1 ; i <= m ; i++) {
		int x , y;
		char c;
		cin >> x >> c >> y;
		if(c == '=') G[x].pb(y) , G[y].pb(x);
		if(c == '<') edge.pb({x , y});
		if(c == '>') edge.pb({y , x});
	}
	for(int i = 1 ; i <= n ; i++) 
		if(!root[i]) nn++ , find(i);
	for(auto x : edge) 
		if(root[x.fi] != root[x.se]) 
			adj[root[x.fi]].pb(root[x.se]),
			nadj[root[x.se]].pb(root[x.fi]);
	for(int i = 1 ; i <= nn ; i++) if(!vis[i]) dag(i);
    for(int i = 1 ; i <= nn ; i++) vis[i] = 0;
	for(int i = 1 ; i <= nn ; i++) if(!vis[i]) ndag(i);
	for(int i = 1 ; i <= n ; i++) {
		int par = root[i];
		if(g[par] + f[par] == k - 1) cout << char('a' + g[par]);
		else cout << "?";
	}
	return 0;
}


