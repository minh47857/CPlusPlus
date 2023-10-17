#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<long long, long long>
#define fi first
#define se second
#define pb push_back

const ll N = 2e5 + 5 , inf = 1e18 ;

ll n, m, x, y, l, dist[N];
vector<pi> adj[N];

void solve(int s)
{
    priority_queue< pi , vector< pi >, greater< pi > > heap;
    for(int i = 0; i <= n; ++i) dist[i] = inf;
    dist[s] = 0; heap.push({0, s});
    while(!heap.empty())
    {
        ll u = heap.top().se;
        ll du = heap.top().fi;
        heap.pop();
        if(du != dist[u]) continue;
        for(auto x : adj[u])
        {
        	ll v = x.fi;
        	ll w = x.se;
           if( dist[v] > du + w) dist[v] = du + w , heap.push( {dist[v] , v});
        }
    }
   for (int i = 1; i <= n ; i++) cout << dist[i] << " ";   
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
       cin >> n >> m;
    for(int i = 1; i <= m; ++i)
    {
       cin >> x >> y >> l;
       adj[x].pb( {y, l * 2});
       adj[y].pb( {x, l * 2 });
    }
    for(int i = 1; i <= n; i++) cin >> x, adj[0].pb({ i , x} ) ;
	solve(0);
	return 0;
}
