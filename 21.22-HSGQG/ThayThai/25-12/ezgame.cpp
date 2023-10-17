#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 5005 , MOD = 1e9 + 7 , inf = 1e9 + 7;

int n , m , w , b , t[N][N] , f[N][N];
vector<int> G[N] , H[N];

void Go(int u , int v) {
	if(t[u][v] != -1) return;
	t[u][v] = 0;
	for(int x : G[u]) Go(x , v) , t[u][v] |= (1 - t[x][v]);
	for(int x : H[v]) Go(u , x) , t[u][v] |= (1 - t[u][x]);
}

int calc(int u , int v) {
	if(f[u][v] != -1) return f[u][v];
	f[u][v] = ((t[u][v]) ? inf : 0);
	for(auto x : G[u]) {
		if(t[u][v] && !t[x][v]) f[u][v] = min(calc(x , v) + 1 , f[u][v]);
		if(!t[u][v] && t[x][v]) f[u][v] = max(calc(x , v) + 1 , f[u][v]);
	}
	for(auto x : H[v]) {
		if(t[u][v] && !t[u][x]) f[u][v] = min(calc(u , x) + 1 , f[u][v]);
		if(!t[u][v] && t[u][x]) f[u][v] = max(calc(u , x) + 1 , f[u][v]);
	}
	return f[u][v];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
	cin >> n >> m >> w >> b;
	for(int i = 1 ; i <= m ; i++) {
		int u , v ; cin >> u >> v;
		H[v].pb(u);
		G[u].pb(v);
	}
	memset(t , -1 , sizeof(t));
	memset(f , -1 , sizeof(f));
	for(int i = 1 ; i <= n ; i++)
	  for(int j = 1 ; j <= n ; j++)
	  	Go(i , j);
	cout << calc(w , b);
	return 0;
}

