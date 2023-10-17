#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back

const int N = 1e4 + 5 , M = 205 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
    freopen("escape.in" , "r" , stdin);
	freopen("escape.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

struct room {
	int dist , u , h , t;
	bool operator > (const room&s) const {return dist > s.dist;}
} ;

int ans = inf , n , m , X , a[N] , d[N][M][3];
vector<pi> adj[N];

void Dijkstra() {
	priority_queue< room , vector<room> , greater<room> > Q;
	for(int i = 1 ; i <= n ; i++)
		for(int j = 0 ; j <= X ; j++)
			d[i][j][0] = d[i][j][1] = d[i][j][2] = inf;
	d[1][X][0] = 0;
	Q.push({0 , 1 , X , 0});
	while(Q.size()) {
		int u = Q.top().u , du = Q.top().dist , h = Q.top().h , t = Q.top().t;
	//	cout << u << ' ' << du << ' ' << h << ' ' << t << '\n';
		Q.pop();
		if(du != d[u][h][t]) continue;
		for(auto x : adj[u]) {
			int v = x.fi , w = x.se;
		    int nxh = max(h - w , 0);
			int nxt = (nxh == 0) ? 1 : t;
			if(abs(nxt - a[v]) == 2) continue;
			if(a[v] == 1) {
				if(d[v][nxh][nxt] > du + w)
					d[v][nxh][nxt] = du + w ,
					Q.push({d[v][nxh][nxt] , v , nxh , nxt});
			}
			else  
				if(d[v][X][a[v]] > du + w)
					d[v][X][a[v]] = du + w ,
					Q.push({d[v][X][a[v]] , v , X , a[v]});
		}
	}
	for(int i = 0 ; i <= X ; i++)
		ans = min({ans , d[n][i][0] , d[n][i][1] , d[n][i][2]});
	cout << ans;
}

int main() {
	file();
	cin >> n >> m >> X;
	for(int i = 1 ; i <= n ; i++)
		cin >> a[i];
	for(int i = 1 ; i <= m ; i++) {
		int u , v , w;
		cin >> u >> v >> w;
		adj[u].pb({v , w});
		adj[v].pb({u , w});
	}
	Dijkstra();
	return 0;
}


