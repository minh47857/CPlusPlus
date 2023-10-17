#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1e5 + 5 , MOD = 1e9 +7;
ll n , m , t , trace[N] , res = 0 , x , y , z , sum[N] , d[N] , num[N];
vector <pi> adj[N];
vector <ll> new_adj[N];
void file()
{
	freopen("shortcut.inp" , "r" , stdin);
	freopen("shortcut.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
void dijkstra(int s)
{
	priority_queue < pi , vector <pi> , greater<pi> > heap;
	for (int i = 2 ; i <= n ; i++) d[i] = LLONG_MAX;
	d[s] = 0;
	heap.push({0 , s});
	while (heap.size() != 0)
	{
		ll t = (heap.top()).fi;
		ll u = (heap.top()).se;
		heap.pop();
		if ( t != d[u] ) continue ;
		for (auto x : adj[u])
		{
			ll v = x.fi;
			ll w = x.se;
			if (d[v] == t + w && u < trace[v]) trace[v] = u;
			if (d[v] > t + w) 
			{
				d[v] = t + w;
				heap.push({d[v] , v});
				trace[v] = u;
			}
		}
	}
}
void Dfs(int u)
{
	sum[u] += num[u];
	for (auto x : new_adj[u])
	{
		Dfs(x);
		sum[u] += sum[x];
	}
	res = max (res , (d[u] - t) * sum[u]);
}

int main()
{
	file();
   cin >> n >> m >> t ;
   for (int i = 1; i <= n ; i++)  cin >> num[i];
   for (int i = 1 ; i <= m ; i++)
   {
   	cin >> x >> y >> z;
   	adj[x].pb({y , z});
   	adj[y].pb({x , z});
   }
   dijkstra(1);
   for (int i = 1 ; i <= n ; i++) new_adj[trace[i]].pb(i);
   Dfs(1);
   cout << res;
   return 0 ;
}

