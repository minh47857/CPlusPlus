#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>

const int N = 1e3 + 5;

void file() {
	freopen("CERAMIC.inp" , "r" , stdin);
	freopen("CERAMIC.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , m , s , Deg[N] , vis[N] ;
vector<int> adj[N];

void Dfs(int u) {
	for(auto v : adj[u]) if(!vis[v]) vis[v] = 1 , Dfs(v);
}

bool IsConnected() {
	memset(vis , 0 , sizeof(vis));
	vis[s] = 1;
	Dfs(s);
	for(int i = 1 ; i <= n ; i++) if(adj[i].size() != 0 && !vis[i]) return false;
	return true;
}

bool IsEuler() {
	vector<int> Odd;
	for(int i = 1 ; i <= n ; i++) if(Deg[i] % 2 == 1) return false;
	return true;
}

void solve() {
	memset(Deg , 0 , sizeof(Deg));
	for(int i = 1 ; i <= n ; i++) adj[i].clear();
	for(int i = 1 , u , v ; i <= m ; i++) {
		cin >> u >> v;
		Deg[u]++;
		Deg[v]++;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	if(!IsConnected() || !IsEuler()) 	cout << "NO" << '\n';
	else cout << "YES" << '\n';
}

int main() {
	file();
   while(cin >> n >> m >> s) {
   	if(n == 0 && m == 0 && s == 0) return 0;
   	else solve();
   }
}

