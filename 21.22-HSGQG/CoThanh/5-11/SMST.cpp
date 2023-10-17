#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back

const ll N = 205 , inf = 1e15;

void file() {
    freopen("SMST.inp" , "r" , stdin);
	freopen("SMST.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

struct node {
	ll u , v , w;
};

int n , m , vis[N];
ll sum;
node d[N];
vector<pi> G[N];
vector<node> Edge;

void DfsCalc(int u) {
	for(auto x : G[u]) if(!vis[x.fi]) {
		vis[x.fi] = 1;
		DfsCalc(x.fi);
	    sum += x.se; 
	}
}

ll Get() {
	for(int i = 1 ; i <= n ; i++) vis[i] = 0;
	vis[1] = 1; 
	sum = 0;
	DfsCalc(1);
	for(int i = 1 ; i <= n ; i++) if(!vis[i]) return 123456789;
	return sum;
}

void Dfs(int u , int p) {
	for(auto x : G[u]) if(x.fi != p) {
		ll v = x.fi , w = x.se;
		d[v] = d[u];
		if(w > d[v].w) 	d[v] = {u , v , w};
		Dfs(v , u);
	}
}

int main() {
	file();
	cin >> n >> m;
	for(int i = 1 ; i <= m ; i++) {
		ll u , v , w;
		cin >> u >> v >> w;
		Edge.pb({u , v , w});
	}
	for(auto x : Edge) {
		for(int i = 1 ; i <= n ; i++) d[i] = {0 , 0 , -inf};
		if(x.u == x.v) {
			cout << Get() << '\n';
			continue;
		}
		Dfs(x.u , x.u);
	    if(d[x.v].w == -inf || d[x.v].w > x.w) {
	      int	p = d[x.v].u , q = d[x.v].v;
	      for(int i = 0 ; i < G[p].size() ; i++) if(G[p][i].fi == q) {
	      	G[p].erase(G[p].begin() + i);
	      	break;
	      }
	      for(int i = 0 ; i < G[q].size() ; i++) if(G[q][i].fi == p) {
	      	G[q].erase(G[q].begin() + i);
	      	break;
	      }
	        G[x.u].pb({x.v , x.w});
	        G[x.v].pb({x.u , x.w});
		}
		cout << Get() << '\n';
	}
	return 0;
}


