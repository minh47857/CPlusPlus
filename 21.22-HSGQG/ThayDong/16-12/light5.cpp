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
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int n , m , q , deg[N] , h[N] , f[N] , ans = 0 , K;
vector<pi> G[N];

bool cmp(pi a , pi b) {
	return deg[a.fi] > deg[b.fi];
}

int main() {
    file();
	cin >> n >> m >> q;
	K = sqrt(m);
	for(int i = 1 ; i <= m ; i++) {
		int u , v , c;
		cin >> u >> v >> c;
		G[u].pb({v , c}) , G[v].pb({u , c});
		deg[u]++ , deg[v]++;
		h[v] += c , h[u] += c;
	    ans += c;
	}
	for(int i = 1 ; i <= n ; i++) 
		sort(G[i].begin() , G[i].end() , cmp);
	while(q--) {
		int u ; cin >> u;
		f[u]++;
		if(deg[u] <= K) {
			for(auto x : G[u]) {
				int tmp = (f[u] + f[x.fi] + x.se) % 2;
				if(tmp == 0) tmp = -1;
				ans += tmp;
				if(deg[x.fi] > K) h[x.fi] += tmp;
			}
		}
		else {
			ans = ans - h[u] + deg[u] - h[u];
			h[u] = deg[u] - h[u];
			for(auto x : G[u]) {
				if(deg[x.fi] < K) break;
				int tmp = (f[u] + f[x.fi] + x.se) % 2;
				if(tmp == 0) tmp = -1;
				h[x.fi] += tmp;
			}
		}
		cout << ans << ' ';
	}
	return 0;
}

