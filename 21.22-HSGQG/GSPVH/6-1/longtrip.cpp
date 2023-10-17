#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 55 , M = 2e4 + 5 , inf = 1e9 + 7;

void file() {
	freopen("longtrip.inp" , "r" , stdin);
	freopen("longtrip.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

struct trip {
	ll dist , u , s;
	bool operator > (const trip&other) const {
		return dist > other.dist;
	}
};

int n , m , c;
ll t , d[N][M];
vector<pi> G[N];

void Dijkstra() {
	priority_queue< trip , vector<trip> , greater<trip> > Q;
	memset(d , 0x3f , sizeof(d));
	d[1][0] = 0;
	Q.push({0 , 1 , 0});
	while(Q.size()) {
		int u = Q.top().u , du = Q.top().dist , s = Q.top().s;
		Q.pop();
		if(d[u][s] != du) continue;
		for(auto x : G[u]) {
			int v = x.fi , w = x.se;
			if(d[v][(s + w) % c] > d[u][s] + w) 
				d[v][(s + w) % c] = d[u][s] + w,
				Q.push({d[u][s] + w , v , (s + w) % c});
		}
	}
}

int main() {
	file();
	cin >> n >> m >> t;
	for(int i = 1 ; i <= m ; i++) {
		int u , v , w;
		cin >> u >> v >> w;
		if(u == 1 || v == 1) c = 2 * w;
		G[u].pb({v , w});
		G[v].pb({u , w});
	}
	if(c == 0) {
		cout << "Impossible";
		return 0;
	}
	Dijkstra();
	cout << ((d[n][t % c] <= t) ? "Possible" : "Impossible");
	return 0;
}

