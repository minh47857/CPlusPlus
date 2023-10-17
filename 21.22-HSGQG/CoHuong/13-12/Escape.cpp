#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define ld long double
#define eps 1e-9
#define pi pair<ld , ld>

const int N = 105 , MOD = 1e9 + 7 , inf = 1e6;
 
using namespace std;

void file() {
	freopen("Escape.inp" , "r" , stdin);
	freopen("Escape.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int  n , m , e , q[N] , X , Y , vis[N];
ld ans = -1 , c[N][N] , lo = 1 , hi = inf , g , d[N];
vector<pi> G[N];

bool check(ld V) {
	priority_queue< pi , vector<pi> , greater<pi> > Q;
	for(int i = 1 ; i <= n ; i++)
		d[i] = inf;
	d[X] = 0;
	Q.push({0 , X});
	while(Q.size()) {
		int u = Q.top().se;
		ld du = Q.top().fi;
		Q.pop();
		if(du != d[u]) continue;
		for(auto x : G[u]) {
			int v = x.fi;
			ld w = x.se;
			if(du + w < d[v] && c[Y][v] * V >= (du + w) * 160)
				d[v] = du + w , Q.push({d[v] , v});
		}
	}
	for(int i = 1 ; i <= e ; i++)
		if(d[q[i]] != inf) return true;
	return false;
}

int main() {
	file();
	cin >> n >> m >> e;
	for(int i = 1 ; i <= n ; i++)
		for(int j = 1 ; j <= n ; j++)
			c[i][j] = ((i == j) ? 0 : inf);
    for(int i = 1 ; i <= m ; i++) {
    	int u , v;
    	ld w;
    	cin >> u >> v >> w;
    	c[u][v] = c[v][u] = w;
    	G[u].pb({v , w});
    	G[v].pb({u , w});
	}
	for(int k = 1 ; k <= n ; k++)
    	for(int i = 1 ; i <= n ; i++)
    		for(int j = 1 ; j <= n ; j++)
    			c[i][j] = min(c[i][j] , c[i][k] + c[k][j]);
	for(int i = 1 ; i <= e ; i++)
		cin >> q[i];
	cin >> X >> Y;
	for(int i = 1 ; i <= 100 ; i++) {
		g = (lo + hi) / 2;
		if(check(g)) ans = g , hi = g;
		else lo = g;
	}
	if(ans == -1) 
		cout << "IMPOSSIBLE";	
	else cout << fixed << setprecision(6) << ans;
	return 0;
}


