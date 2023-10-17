#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>

const int N = 1e5 + 5;

void file() {
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , m , d[N] , K;
vector<int> adj[N] , G[N];
ll ans = 0;

int main() {
	file();
  cin >> n >> m;
  for(int i = 1 , u , v ; i <= m ; i++) cin >> u >> v , adj[u].pb(v);
  K = sqrt(m);
  for(int i = 1 ; i <= n ; i++) if(!adj[i].empty()) {
  	 if(adj[i].size() >= K) {
  	 	for(auto x : adj[i]) d[x] = 1;
  	 	for(int j = 1 ; j <= n ; j++) {
  	 		if(i == j || (j > i && adj[j].size() >= K)) continue;
  	 		ll s = 0;
  	 		for(auto x : adj[j]) s += d[x];
  	 		ans += (s * (s - 1) / 2);
		   }
		for(auto x : adj[i]) d[x] = 0;
	   }
	else {
		sort(adj[i].begin() , adj[i].end());
		for(int x = 0 ; x < adj[i].size() ; x++)
		 for(int y = x + 1 ; y < adj[i].size() ; y++)
		   G[adj[i][x]].pb(adj[i][y]);
	}
  }
  for(int i = 1 ; i <= n ; i++) {
  	for(auto x : G[i]) ans += d[x] , d[x]++;
  	for(auto x : G[i]) d[x] = 0;
  }
  cout << ans;
}
