#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define eps 1e-6
#define pi pair<int , int>

const int N = 1e5 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

using namespace std;

void file() {
	freopen("fpath.inp" , "r" , stdin);
	freopen("fpath.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int n , m , s , l , k , res[N] , ans , d[N];
vector<int> g[N];

int main() {
//	file();
	cin >> n >> m >> s >> l >> k;
	for(int i = 1 ; i <= m ; i++) {
		int u , v , w;
		cin >> u >> v >> w;
		res[u] = max(res[u] , w);
		res[v] = max(res[v] , w);
		g[u].pb(v) ; g[v].pb(u);
	}
	queue<int> q;
	d[s] = 1;
	q.push(s);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(auto v : g[u]) 
			if(!d[v]) d[v] = d[u] + 1 , q.push(v);
	}
	for(int i = 1 ; i <= n ; i++)
		if(d[i] <= k) ans = max(ans , res[i]);
	cout << ans;
	return 0;
}


