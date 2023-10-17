#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>

const ll N = 1e4 + 5 , MOD = 1e9 + 7 , inf = 1e15;

void file() {
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int num[N] , low[N] , n , m , numjoint = 0 , joint[N] , Time = 0 , bridge = 0 , child;
vector<int> adj[N];

void Dfs(int u , int par) {
	int child = 0;
	num[u] = low[u] = ++Time;
	for(auto v : adj[u]) {
		if(v == par) continue;
		if(!num[v]) {
			Dfs(v , u);
			low[u] = min(low[u] , low[v]);
			if(num[v] == low[v]) bridge++;
			child++;
			if(u == par) {
				if(child > 1) joint[u] = 1;
			}
			else if(low[v] >= num[u]) joint[u] = 1;
		}
		else low[u] = min(low[u] , num[v]);
	}
}

int main() {
  cin >> n >> m;
  for(int i = 1 ; i <= m ; i++) {
  	int u , v;
  	cin >> u >> v;
  	adj[u].pb(v);
  	adj[v].pb(u);
  }
  for(int i = 1 ; i <= n ; i++) if(!num[i]) Dfs(i , i);
  for(int i = 1 ; i <= n ; i++) numjoint += joint[i] ;// cout << i << ' ' << joint[i] << endl;
  cout << numjoint << ' ' << bridge ;
  return 0;
}
