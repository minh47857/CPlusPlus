#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define pi pair <ll , ll>
#define fi first
#define se second
using namespace std;

const ll N = 1e5 , MOD = 1e9 + 7 , inf = 1e15;

void file() {
	freopen("gps.in" , "r" , stdin);
	freopen("gps.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) , cout.tie(0);
}

ll m , n , a[N] , b[N] , p[N] , q[N] , d[5][N] ;
vector<pi> adj[5][N];

void Dijkstra(int s , int t) {
	priority_queue< pi , vector<pi>  , greater<pi> > Q;
	for(int i = 1 ; i <= n ; i++) d[t][i] = inf;
	d[t][s] = 0 , Q.push({0 , s});
	while(Q.size()) {
		ll u = Q.top().se , du =  Q.top().fi;
		Q.pop();
		if(d[t][u] != du) continue;
		for(auto x : adj[t][u]) {
			ll v = x.fi , w = x.se;
			if(d[t][v] > du + w) d[t][v] = du + w , Q.push({d[t][v] , v});
		}
	}
}

int main() {
	file();
  cin >> n >> m;
  for(int i = 1 ; i <= m ; i++) {
  	cin >> a[i] >> b[i] >> p[i] >> q[i];
  	adj[1][b[i]].pb({a[i] , p[i]});
  	adj[2][b[i]].pb({a[i] , q[i]});
  }
  Dijkstra(n , 1);
  Dijkstra(n , 2);
  for(int i = 1 ; i <= m ; i++) {
  	int w = 0;
  	if(d[1][a[i]] != d[1][b[i]] + p[i]) w++;
  	if(d[2][a[i]] != d[2][b[i]] + q[i]) w++;
  	adj[3][a[i]].pb({b[i] , w});
  }
  Dijkstra(1 , 3);
  cout << d[3][n];
  return 0;
}

