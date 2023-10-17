#include<bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 3e5 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

using namespace std;

vector<int> adj[N];
int subtask , n;

void Dfs(int u , int pa) {
	for(int i = 1 ; i <= 20 ; i++) 
		p[u][i] = p[p[u][i - 1]][i - 1];
	for(auto v : adj[u]) {
		if(v == pa) continue;
		h[v] = h[u] + 1;
		p[v][0] = u;
		Dfs(v , u);
	}
}

int lca(int x , int y) {
	if(x == 1 || y == 1) return 1;
	if(h[x] < h[y]) swap(x , y);
	for(int i = 20 ; i >= 0 ; i--) 
		if(h[x] - (1 << i) >= h[y]) x = p[x][i];
	if(x == y) return x;
	for(int i = 20 ; i >= 0 ; i--)
		if(p[x][i] != p[y][i])
			x = p[x][i] , y = p[y][i];
	return p[x][0];
}


namespace sub4 {
	vector<int> V;
	pi a[N];
	int t , q , root , pos[N];
	
	void Go(int u , int pa) {
		V.pb(u);
		for(auto v : adj[u]) 
			if(v != pa) Go(v , u);
	}
	
	bool cmp(pi x , pi y) {
		if(x.fi == y.fi) return x.se > y.se;
		if(x.fi < y.fi) return true;
	}
	
	void solve() {
		for(int i = 1 ; i <= n ; i++) 
			if(adj[i].size() == 1) root = i;
		Go(root , 0);
		for(int i = 0 ; i < n ; i++) pos[V[i]] = i;
		cin >> t;
		while(t--) {
			bool ok = true;
			set<int> s;
			cin >> q;
			for(int i = 1 ; i <= q ; i++) {
				int u , v;
				cin >> u >> v;
				if(pos[u] > pos[v]) swap(u , v);
				a[i] = {pos[u] , pos[v]};
			}
			sort(a + 1 , a + q + 1);
			for(int i = 1 ; i <= q ; i++) {
				if(s.empty() || *s.rbegin() < a[i].fi) {
					s.insert(a[i].se);
					continue;
				}
				auto it = s.lower_bound(a[i].fi);
				if(*it >= a[i].fi && *it <= a[i].se) ok = false;
				s.insert(a[i].se);
			}
			cout << ((ok) ? "RO RANG\n" : "MAP MO\n");
		}
	}
}

int main() {
	cin >> subtask >> n;
	for(int i = 1 ; i < n ; i++) {
		int u , v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
//	Dfs(1 , 0);
	//if(subtask <= 3) sub3::solve();
	if(subtask == 4) sub4::solve();
}

