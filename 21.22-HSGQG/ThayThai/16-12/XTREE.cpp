#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define eps 1e-6
#define pi pair<int , ll>
#define Bit(x , k) ((x >> k) & 1)

const int N = 1e5 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

using namespace std;


ll n , bit[35][5] , f[N] , ans = 0;
vector<pi> G[N];

void file() {
	freopen("XTREE.inp" , "r" , stdin);
	freopen("XTREE.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

void Dfs(int u , int pa) {
	for(auto x : G[u]) if(x.fi != pa) {
		f[x.fi] = f[u] ^ x.se;
		Dfs(x.fi , u);
	}
}

int main() {
	//file();
	cin >> n;
	for(int i = 1 ; i < n ; i++) {
		ll u , v , w;
		cin >> u >> v >> w;
		G[u].pb({v , w});
		G[v].pb({u , w});
	}
	Dfs(1 , 0);
	for(int i = 1 ; i <= n ; i++) {
		for(int j = 32 ; j >= 0 ; j--) 
			ans += (bit[j][1 - Bit(f[i] , j)] * (1LL << j));
		for(int j = 32 ; j >= 0 ; j--)
			bit[j][Bit(f[i] , j)]++;
	}
	cout << ans;
	return 0;	
}

