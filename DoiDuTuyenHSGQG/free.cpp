#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1000001 , MOD = 1e9 +7;
ll m , n , st , fn  , d[N][5] , Min[N][5] , vis[N] , ans , x , y , l ;
vector <ll> trace[N];
vector <pi> adj[N];
void file()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
void solve(int s, int po)
{
	priority_queue< pi , vector<pi> , greater<pi> > heap;
	d[s][po] = 0;
	heap.push({0,s});
	while (heap.size() != 0)
	{
		ll t = heap.top().fi;
		ll u = heap.top().se;
		heap.pop();
		if (t != d[u][po]) continue;
		for (auto x : adj[u])
		{
		ll	v = x.fi;
		ll	w = x.se;
           if (d[v][po] == t + w) trace[v].pb(u);
           else if(d[v][po] > t + w) 
			{
		   	  trace[v].clear();
		   	  trace[v].pb(u);
		   	  d[v][po] = t + w, heap.push({t + w , v});
		   }
		}
	}
//	for (int i = 1 ; i <= n ; i ++) cout << d[i][po] << " ";
//	cout << endl;
}
void dijkstra(int s , int po)
{
	 priority_queue< pi , vector< pi >, greater< pi > > heap;
    d[s][po] = 0;
	heap.push({0,s});
    while(!heap.empty())
    {
        ll u = heap.top().se;
        ll du = heap.top().fi;
        heap.pop();
        if(du != d[u][po]) continue;
        for(auto x : adj[u])
        {
        	ll v = x.fi;
        	ll w = x.se;
           if( d[v][po] > du + w) d[v][po] = du + w , heap.push( {d[v][po] , v});
        }
    }
}
void Dfs(int u)
{
	vis[u] = 1;
	Min[u][2] = d[u][2];
	Min[u][1] = d[u][1];
	cout << u <<endl;
	for (auto x : trace[u])
	{
		if (vis[x] == 0) Dfs(x) ;
		Min[u][2] = min(Min[u][2] , Min[x][2]);
		Min[u][1] = min(Min[u][1] , Min[x][1]);
	}
	ans = min({d[u][1] + Min[u][2] , ans , d[u][2] + Min[u][1]});
}
int main()
{
   cin >> n >> m >> st >> fn;
    for(int i = 1; i <= m; ++i)
    {
       cin >> x >> y >> l;
       adj[x].pb( {y, l});
       adj[y].pb( {x, l});
    }
    for (int i = 1; i <= n ; i++)	d[i][0] = d[i][1] = d[i][2] = 1e15 ;
    memset(vis , 0 , sizeof (vis));
    solve(1 , 0);
    dijkstra(st , 1);
    dijkstra(fn , 2);
    ans = d[st][2];
    Dfs(n);
    cout << ans ;
	return 0;
}

