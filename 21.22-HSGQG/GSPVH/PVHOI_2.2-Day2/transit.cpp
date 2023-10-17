#include<bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 1505 , Maxlen = 1500000 , M = (1 << 17) + 5;
const int inf = 1e8;

using namespace std;

int n , m , q , d[20][N] , g[20][20][M] , c[N][N] , f[20] , d2[20][N];
vector<int> Q[Maxlen];
vector<pi> S[Maxlen];

int Bit(int x , int k) {
	return (x >> k) & 1;
}

namespace sub1 {
	void solve() {
		while(q--) {
			int l , r , res = m + 1;
			cin >> l >> r;
			if(m == 1 && l == r && r == f[1]) cout << 0 << ' ';
			else {
				for(int i = 1 ; i <= m ; i++) 
					if(f[i] == l || f[i] == r) res --;
				cout << res << ' ';
			}
		}
	}
}

void Dijkstra1(int s , int id) {
	for(int i = 1 ; i <= n ; i++) d[id][i] = inf;
	Q[0].pb(s);
	d[id][s] = 0;
	for(int len = 0 ; len < Maxlen ; len++) {
		while(Q[len].size()) {
			int u = Q[len].back();
			Q[len].pop_back();
			if(d[id][u] != len) continue;
			for(int v = 1 ; v <= n ; v++) {
				if(d[id][v] > len + c[u][v]) 
					d[id][v] = len + c[u][v] , Q[d[id][v]].pb(v);
			}
		}
	}
	
	for(int i = 1 ; i <= n ; i++) d2[id][i] = inf;
	Q[0].pb(s);
	d2[id][s] = 0;
	for(int len = 0 ; len < Maxlen ; len++) {
		while(Q[len].size()) {
			int u = Q[len].back();
			Q[len].pop_back();
			if(d2[id][u] != len) continue;
			for(int v = 1 ; v <= n ; v++) {
				if(d2[id][v] > len + c[v][u]) {
					d2[id][v] = len + c[v][u] , Q[d2[id][v]].pb(v);
				}
			}
		}
	}
	
}

void Dijkstra2(int id , int p[20][140000]) { 
	for(int i = 1 ; i <= m ; i++) 
		for(int mask = 0 ; mask < (1 << m) ; mask++) 
			p[i][mask] = inf;
	p[f[i]][(1 << (id - 1))] = 0;
	for(int maks = 1 ; mask <)
	for(int v = 1 ; v <= m ; v++) if(!Bit(mask , v - 1)) {
		int nmask = mask | (1 << (v - 1));
		if(p[v][nmask] > p[u][mask] + d[u][f[v]]) {
			p[v][nmask] = p[u][mask] + d[u][f[v]];
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
	cin >> n >> m >> q;
	bool cksub1 = true;
	for(int i = 1 ; i <= m ; i++) cin >> f[i];
	for(int i = 1 ; i <= n ; i++)
		for(int j = 1 ; j <= n ; j++)
			cin >> c[i][j] , cksub1 &= (i == j || c[i][j] == 1);
	if(cksub1) {
		sub1::solve();
		return 0;
	}
	for(int i = 1 ; i <= m ; i++) 
		Dijkstra1(f[i] , i);
	for(int i = 1 ; i <= m ; i++)
		Dijkstra2(i , g[i]);
	while(q--) {
		int u , v , ans = inf;
		cin >> u >> v;
		for(int i = 1 ; i <= m ; i++)
		for(int j = 1 ; j <= m ; j++)
			ans = min(ans , d2[i][u] + g[i][j][(1 << m) - 1] + d[j][v]);
		cout << ans << ' ';
	}
	return 0;
}

