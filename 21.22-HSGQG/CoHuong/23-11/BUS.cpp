#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 5e3 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , m , c[N] , d[N] , f[N][N];
vector<int> G[N];

int Dfs(int u , int x) {
	cout << u << ' ' << x << '\n';
	if(u == n) return 0;
	if(f[u][x] != -1) return f[u][x];
	f[u][x] = inf;
	int res = inf;
	if(f[u][d[u]] != inf) res = min(res , Dfs(u , d[u]) + c[u]);
	if(x) for(auto v : G[u]) if(f[v][x - 1] != inf) res = min(res , Dfs(v , x - 1));
	f[u][x] = res;
	cout << u << ' ' << x << ' ' << res << "|| ";
	cout << u << ' ' << d[u] << "| ";
	if(x) for(auto v : G[u]) cout << v << ' ' << x - 1 <<"| ";
	cout << '\n';
	return res;
}

int main() {
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++) cin >> c[i] >> d[i];
	for(int i = 1 ; i <= m ; i++) {
		int u , v ;
		cin >> u >> v;
		G[u].pb(v);
		G[v].pb(u);
	}
	memset(f , -1 , sizeof(f));
	cout << Dfs(1 , 0);
}

