#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("cachly.inp" , "r" , stdin);
	freopen("cachly.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , m , Time , num[N] , low[N] , res[N];
vector<int> adj[N];

void dfs(int u , int pa) {
	num[u] = low[u] = ++Time;
	res[u] = (pa != 0);
	for(auto v : adj[u]) if(v != pa) {
		if(num[v]) low[u] = min(low[u] , num[v]);
		else {
			dfs(v , u);
			low[u] = min(low[u] , low[v]);
			if(low[v] >= num[u]) res[u]++;
		}
	}
}

int main() {
	file();
	cin >> n >> m;
	for(int i = 1 ; i <= m ; i++) {
		int u , v ; cin >> u >> v;
		adj[u].pb(v) ; adj[v].pb(u);
	}
	dfs(1 , 0);
	for(int i = 1 ; i <= n ; i++) cout << res[i] << '\n';
	return 0;
}

