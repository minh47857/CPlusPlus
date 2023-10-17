#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define eps 1e-6
#define pi pair<int , int>

const int N = 2e6 + 5;

using namespace std;

void file() {
	freopen("colorful.inp" , "r" , stdin);
	freopen("colorful.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int n , par[N] , f[N] , c[N] , cnt = 0 , T = 0;
vector<int> adj[N] , ans;
vector<pi> Edges;

int parent(int u) {
	return ((par[u] < 0) ? u : (par[u] = parent(par[u])));
}

void merge(int x , int y) {
	if((x = parent(x)) == (y = parent(y))) return;
	if(par[x] > par[y]) swap(x , y);
	par[x] += par[y];
	par[y] = x;
}

int main() {
	file();
	cin >> n >> n;
	for(int i = 1 ; i < n ; i++) {
		int u , v ; cin >> u >> v;
		adj[u].pb(v) ; adj[v].pb(u);
		Edges.pb({u , v});
	}
	for(int i = 1 ; i <= n ; i++) cin >> c[i];
	memset(par , -1 , sizeof(par));
	for(auto x : Edges) 
		if(c[x.fi] == c[x.se]) merge(x.fi , x.se);
	for(int i = 1 ; i <= n ; i++) 
		if(par[i] < 0) cnt++;
	for(int u = 1 , tmp ; u <= n ; u++) 
		if(adj[u].size() >= cnt - 1) {
		T++;
		f[parent(u)] = T;
		tmp = 1;
		for(auto v : adj[u]) {
			int pa = parent(v);
			if(f[pa] != T) f[pa] = T , tmp++;
		}
		if(tmp == cnt) ans.pb(u);
	}
	if(ans.empty()) {
		cout << "NO";
		return 0;
	}
	cout << "YES\n";
	sort(ans.begin() , ans.end());
	for(auto x : ans) cout << x << ' ';
	return 0;
}


