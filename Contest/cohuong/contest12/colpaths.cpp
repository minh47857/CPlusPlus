#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>

const ll N = 3000005 , MOD = 1e9 + 7 , inf = 1e15;

void file() {
	freopen("colpaths.in" , "r" , stdin);
	freopen("colpaths.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , m , k , c[N];
ll ans = 0 ;
vector<int> adj[N];

int Bit(int x , int k) {
	return (x >> k) & 1;
}

int main() {
	file();
  cin >> n >> m >> k;
  ll f[n + 5][1 << k];
  memset(f , 0 , sizeof(f));
  for(int i = 1 ; i <= n ; i++) cin >> c[i] , f[i][1 << (c[i] - 1)] = 1;
  
  for(int i = 1 ; i <= m ; i++) {
  	int u , v;
  	cin >> u >> v;
  	adj[u].pb(v);
  	adj[v].pb(u);
  }
  
  for(int mask = 1 ; mask < (1 << k) ; mask++) 
  	for(int i = 1 ; i <= n ; i++) {
  		if(__builtin_popcount(mask) != 1) ans += f[i][mask];
  		if(f[i][mask] == 0) continue;
  	    	for(auto v : adj[i]) 
  		    if(!Bit(mask , c[v] - 1)){
  		     	int new_mask = mask | (1 << (c[v] - 1));
  			    f[v][new_mask] += f[i][mask];
  		  }  
	  }
  cout << ans;
  return 0;
}

