#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 3005 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , m , d[N][N] , s1 , s2 , t1 , t2 , l1 , l2 , ans;
vector<int> adj[N];

void Bfs(int u) {
	queue<int> Q;
	for(int i = 1 ; i <= n ; i++) d[u][i] = inf;
	d[u][u] = 0 , Q.push(u);
	while(Q.size()) {
		int v = Q.front();
		Q.pop();
		for(auto x : adj[v]) 
			if(d[u][x] == inf) d[u][x] = d[u][v] + 1,
			Q.push(x);
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
	cin >> s1 >> t1 >> l1 >> s2 >> t2 >> l2;
	for(int i = 1 ; i <= n ; i++) 
		Bfs(i);
	if(d[s1][t1] <= l1 && d[s2][t2] <= l2) 
		ans = m - d[s1][t1] - d[s2][t2];
	else {
		cout << -1;
		return 0;
	}
	for(int u = 1 ; u <= n ; u++)
		for(int v = u ; v <= n ; v++) {
			int d1 = min(d[u][s1] + d[v][t1] , d[u][t1] + d[v][s1]) + d[u][v];
			int d2 = min(d[u][s2] + d[v][t2] , d[u][t2] + d[v][s2]) + d[u][v];
			if(d1 <= l1 && d2 <= l2) 
				ans = max(ans , m - d1 - d2 + d[u][v]);
		}
	cout << ans;
	return 0;
}

