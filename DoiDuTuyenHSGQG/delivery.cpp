#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>

const ll N = 105 , M = 5e3 + 5 , inf = 1e15;

void file() {
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

struct shipper {
	ll dis ;
	int  cur , com , fi , se;
	
	bool operator > (const shipper &a) const {
		return dis < a.dis;
	}
	
};

int t , n , m , k , s[M] , d[M];
ll f[N][M][3][3];
vector<pi> adj[N];

void Dijkstra(int start) {
	priority_queue< shipper , vector<shipper> , greater<shipper> > Q;
	for(int i = 1 ; i <= n ; i++)
	  for(int j = 0 ; j <= k ; j++)
	     f[i][j][0][0] = f[i][j][0][1] = f[i][j][1][0] = f[i][j][1][1] = inf;
	f[start][0][0][0] = 0;
	
	Q.push({0 , start , 0 , 0 , 0});
	while(Q.size()) {
	  int 	u = Q.top().cur , p1 = Q.top().fi , p2 = Q.top().se , c = Q.top().com;
	  ll  du = Q.top().dis;
	  Q.pop();
	  if(du != f[u][c][p1][p2]) continue;
	  
	  for(auto x : adj[u]) {
	  	ll w = x.se ;
		int  v = x.fi , nx2 = p2 , nx1 = p1 , nxc = c;
	  	
	  	if(p1 == 0) if(v == s[c + 1]) nx1 = 1 ;
		  
		if(p1 == 1) {
			if(p2 == 0) {
				if(v == d[c + 1]) nx1 = nx2 , nxc = c + 1 , nx2 = 0;
				else if(v == s[c + 2]) nx2 = 1 ;
			}
			
			else 	if(v == d[c + 1]) nx1 = nx2 , nxc = c + 1 , nx2 = 0;	
			
		}
		
	    if(f[v][nxc][nx1][nx2] > du + w) f[v][nxc][nx1][nx2] = du + w , Q.push({du + w , v , nxc , nx1 , nx2});
	  }
	  
	}
	
	if(f[d[k]][k][0][0] != inf) cout << f[d[k]][k][0][0] << '\n';
	else cout << -1 << '\n';
}

void solve() {
	cin >> n >> m >> k;
	for(int i = 1 ; i <= n ; i++) {
	//	adj[i].clear();
	//	adj[i].pb({i , 0});
	}
	
	for(int i = 1 ; i <= m ; i++) {
		int u , v , c;
		cin >> u >> v >> c;
		adj[u].pb({v , c});
		adj[v].pb({u , c});
	}
	
	for(int i = 1 ; i <= k ; i++)	cin >> s[i] >> d[i];
	s[k + 1] = d[k + 1] = s[k + 2] = d[k + 2] = 0;
	Dijkstra(1);
}

int main() {
	file();
  cin >> t;
  while(t--) solve();
  return 0;
}

