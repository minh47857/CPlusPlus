#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 1e5 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

ll f[N] , n , ans = 0;
vector<pi> G[N];

void file() {
	freopen("nttree.inp" , "r" , stdin);
	freopen("nttree.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

void Dfs(int u , int par) {
	f[u] = 1;
	for(auto x : G[u]) {
		if(x.fi == par) continue;
		Dfs(x.fi , u);
		ans += f[x.fi] * (n - f[x.fi]) * x.se;
		f[u] += f[x.fi];	
	}
}

int main() {
	file();
	cin >> n;
	for(int i = 1 ; i < n ; i++) {
		int u , v , w;
		cin >> u >> v >> w;
		u++ , v++;
		G[u].pb({v , w});
		G[v].pb({u , w});
	}
	Dfs(1 , 0);
	cout << ans;
	return 0;
}

