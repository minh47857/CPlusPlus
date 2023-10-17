#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 10001, inf = LLONG_MAX;

struct data
{
    ll fi, se ,rd;
} ;
bool operator > (const data& A, const data& B) {
  return A.fi > B.fi;
}

ll n, r, k, x, y, l, t, dist[101][N], ans, test; 
vector<data> adj[N];

void dijkstra(ll s)
{

    priority_queue < data, vector <data>, greater <data> > heap;
    heap.push({0 , s, 0});
    dist[s][0] = 0;
    while( heap.size()!= 0 )
    {
        ll t = heap.top().fi;
        ll u = heap.top().se;
        ll w =  heap.top().rd;
        heap.pop();
        if( t != dist[u][w]) continue ;
       for (auto x : adj[u] )
       {
    ll	v = x.fi ;
    ll	len = x.se;
    ll  count = x.rd ;
        if ( count + w > k) continue;
    	if( dist[v][count + w] > t + len )  dist[v][count + w] = t + len, heap.push({t + len, v, count + w});
	   }             
    }
    for (int i = 0; i <= k; i++ )  ans = min (dist[n][i] , ans) ;
	if( ans == inf) cout << -1 << '\n';
	else cout << ans << '\n';
    
}
void solve()
{
	cin >> k >> n >> r;
	for (int i = 1; i <= n; i++)
     {
     	adj[i].clear();
     	for( int j = 0; j <= k ; j++) dist[i][j] = inf ;
	 }
	 ans = inf;
	for (int i = 1; i <= r ; i++)
	{
		cin >> x >> y >> l >> t;
		adj[x].pb({ y, l, t});
		
	}
     
   dijkstra(1);
}
int main()
{
	cin >> test ;
	while( test --)	solve();
   return 0;
}

