#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int , ll>
#define fi first
#define se second
#define pb push_back

const ll N = 1e3 + 5 , MOD = 1e9 + 7 , inf = 1e15;

void file() {
    freopen("TOUR.inp" , "r" , stdin);
	freopen("TOUR.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
int n , m ,  p , s , t;
ll d[N] , dist[3][N] , ans = inf;
vector<pi> adj[N];

void Dijkstra(int a , int x) {
	priority_queue< pi , vector<pi> , greater<pi> > heap;
	for(int i = 1 ; i <= n ; i++) dist[x][i] = inf;
	dist[x][a] = 0;
	heap.push({0 , a});
	while(heap.size()) {
		ll u = heap.top().se , du = heap.top().fi;
		heap.pop();
		if(du != dist[x][u]) continue;
		for(auto f : adj[u]) {
			ll v = f.fi , w = f.se;
			if(dist[x][v] > du + w) 
			      dist[x][v] = du + w , 
				  heap.push({dist[x][v] , v});
		}
	}
}

int main() {
	file();
	cin >> n >> m >> p >> s >> t;
	for(int i = 1 ; i <= m ; i++) {
		ll u , v , w;
		cin >> u >> v >> w;
		adj[u].pb({v , w});
		adj[v].pb({u , w});
	}
	for(int i = 1 ; i <= p ; i++) cin >> d[i];
	Dijkstra(s , 0);
	Dijkstra(t , 1);
	for(int i = 1 ; i <= p ; i++) 	
	  ans = min(ans , dist[0][d[i]] + dist[1][d[i]]);
	cout << ans;
	return 0;
}


