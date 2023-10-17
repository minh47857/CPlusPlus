#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back

const int N = 2e5 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
    freopen("COLORTREE.inp" , "r" , stdin);
	freopen("COLORTREE.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , c[N] , id[N] , t = 1 , f[N][2] , ans = 0;
vector<int> G[N] , adj[N];

void DfsCompress(int u , int pa) {
	for(auto v : adj[u]) {
		if(v == pa) continue;
		if(c[u] == c[v]) id[v] = id[u];
		else {
			id[v] = ++t;
	     	G[id[u]].pb(id[v]);
		    G[id[v]].pb(id[u]);
		}
		DfsCompress(v , u);
	}
}

void Diameter(int u , int pa) {
	vector<int> Dis;
	for(auto v : G[u]) {
		if(v == pa) continue;
		Diameter(v , u);
		Dis.pb(f[v][0] + 1);
	}
	if(Dis.empty()) {
		f[u][0] = 1;
		return;
	}
	sort(Dis.begin() , Dis.end() , greater<int>());
	f[u][0] = Dis[0];
	if(Dis.size() > 1) f[u][1] = Dis[1];
	else f[u][1] = 0;
	ans = max({ans , f[u][0] / 2 , f[u][1] / 2 , (f[u][0] + f[u][1] - 1) / 2});
}

int main() {
	file();
  cin >> n;
  for(int i = 1 ; i <= n ; i++) cin >> c[i];
  for(int i = 1 , u , v ; i < n ; i++) {
  	cin >> u >> v;
  	adj[u].pb(v);
  	adj[v].pb(u);
  }
  id[1] = 1;
  DfsCompress(1 , 0);
  Diameter(1 , 0);
  cout << ans;
  return 0;
}


