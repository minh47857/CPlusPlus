#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 100001 , MOD = 1e9 +7 , inf = 1e15;
void file()
{
	freopen("OLYMPIC.inp" , "r" , stdin);
	freopen("OLYMPIC.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

 ll n , m , k , c , d[N];
 pi a[N];
 vector<pi> adj[N];

 void Dijkstra(int s)
 {
 	priority_queue< pi , vector<pi> , greater<pi> > heap;
 	for (int i = 1 ; i <= n ; i++) d[i] = inf;
 	d[s] = 0 , heap.push({0 , s});
 	while(!heap.empty())
 	{
 		int u = heap.top().se;
 		int du = heap.top().fi;
 		heap.pop();
 		if (du != d[u]) continue;
 		
 		for (auto x : adj[u])
 		{
 			int v = x.fi;
 			int w = x.se;
 			if (d[v] > du + w) d[v] = du + w , heap.push({d[v] , v});
		}
	}
 }

int main()
{
	file();
  cin >> n >> m >> k >> c;
  for (int i = 1 ; i <= k ; i++) cin >> a[i].se;
  for (int i = 1 ; i <= m ; i++)
  {
  	ll u , v , w;
  	cin >> u >> v >> w;
  	adj[u].pb({v , w});
  	adj[v].pb({u , w});
  }
  Dijkstra(c);
  for (int i = 1 ; i <= k ; i++) a[i].fi = d[a[i].se];
  
  sort(a + 1 , a + k + 1);
 for (int i = 1 ; i <= k ; i++) cout << a[i].se << ' ' << a[i].fi << '\n';
  return 0;
}

