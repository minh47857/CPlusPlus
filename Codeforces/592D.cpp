#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 123460;

int n , m , c[N] , ans;
vector<int> G[N];
pi ver;

bool Dfs(int u , int pa , int h) {
	if(c[u]) 
		ver = max(make_pair(h , -u) , ver);
	bool ok = c[u];
	for(auto v : G[u]) {
		if(v == pa) continue;
		bool tmp = Dfs(v , u , h + 1);
		ans += tmp;
		ok |= tmp;
	}
	return ok;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
	cin >> n >> m;
	for(int i = 1 ; i < n ; i++) {
		int u , v ;	cin >> u >> v;
		G[u].pb(v);
		G[v].pb(u);
	}
	int u;
	for(int i = 1 ; i <= m ; i++) {
		cin >> u;
		c[u] = 1;
	}
	if(m == 1) {
		cout << u << '\n' << 0;
		return 0;
	}
	Dfs(u , 0 , 0);
	u = -ver.se;
	ver = {0 , 0};
	Dfs(u , 0 , 0);
	cout << min(u , -ver.se) << '\n' << ans - ver.fi;
	return 0;
}

