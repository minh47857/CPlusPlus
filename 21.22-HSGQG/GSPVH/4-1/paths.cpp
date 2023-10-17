#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define eps 1e-6
#define pi pair<int , int>

const int N = 505 , inf = 1e9;

using namespace std;

void file() {
	freopen("paths.inp" , "r" , stdin);
	freopen("paths.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int n , m , f[N] , c[N][N];
vector<pi> adj[N];

void solve(int s) {
	for(int i = 1 ; i <= n ; i++) {
		f[i] = 0;
		for(pi x : adj[i]) 
			if(c[s][x.fi] + x.se == c[s][i]) f[i]++;
	}
	for(int i = s + 1 ; i <= n ; i++) {
		int res = 0;
		for(int j = 1 ; j <= n ; j++)
			if(c[s][i] == c[s][j] + c[j][i]) res += f[j];
		cout << res << ' ';
	}
	cout << '\n';
}

int main() {
	file();
	cin >> n >> n >> m;
	for(int i = 1 ; i <= n ; i++)
	  for(int j = i + 1 ; j <= n ; j++)
	  	c[i][j] = c[j][i] = inf;
	for(int i = 1 ; i <= m ; i++) {
		int u , v , l;
		cin >> u >> v >> l;
		adj[u].pb({v , l});
		adj[v].pb({u , l});
		c[u][v] = min(c[u][v] , l);
		c[v][u] = min(c[v][u] , l);
	}
	for(int k = 1 ; k <= n ; k++)
	  for(int i = 1 ; i <= n ; i++)
	    for(int j = 1 ; j <= n ; j++) 
	    	c[i][j] = min(c[i][j] , c[i][k] + c[k][j]);
	for(int i = 1 ; i <= n ; i++) solve(i);
	return 0;
}


