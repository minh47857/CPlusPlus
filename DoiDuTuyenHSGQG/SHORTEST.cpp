#include<bits/stdc++.h>
using namespace std;
typedef pair<long long ,long long > pi;
#define fi first
#define se second
#define ll long long
#define pb push_back

const long long N=3005, MOD=1e9 +7;
ll n, m, dist[N][N], num[N][N];
vector <pi> adj[N];
struct graph
{
	ll c1, c2, c3;
} ad[10005];
void file()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
void dijkstra(int s)
{
	priority_queue<pi, vector <pi> , greater<pi>> heap;
	heap.push({0 , s});
	while( heap.size( )!= 0 )
	{
		ll t = heap.top().fi;
		ll v = heap.top().se;
		heap.pop();
		if( t != dist[s][v]) continue ;
		for(auto x : adj[v] )
		{
			ll u = x.fi;
			ll w = x.se;
			if( dist[s][u] == t +w ) num[s][u] += num[s][v];
			if (dist[s][u] > t + w) 
			{
				dist[s][u] = t + w; 
				heap.push({dist[s][u], u});
				num[s][u] = num[s][v]; 
			}
			
		}
	}
}
void solve()
{
	for(int ve = 1; ve <= m; ve++)
	{
		ll res = 0;
		for(int i = 1; i <= n; i++)
	      for(int j = 1; j <= n; j++)
	        {
		        if(i == j) continue;
		        int u = ad[ve].c1;
		        int v = ad[ve].c2;
		        int w = ad[ve].c3;
		        if(dist[i][u] + w + dist[v][j] == dist[i][j]) res = (res+ num[i][u] * num[v][j])%MOD ;
	         }
	    cout<< res<< '\n';
	}
	
}
int main()
{
	cin>> n>> m;
	for(int i = 1; i <= m ; i++)
	{
		cin>> ad[i].c1>> ad[i].c2>> ad[i].c3;
		adj[ad[i].c1].pb({ad[i].c2, ad[i].c3});
	}
	for(int i = 1; i <= n ;i++)
	for(int j = 1; j <= n ;j++) 
	{
		if(i == j) dist[i][j] = 0, num[i][j] = 1;
		else dist[i][j] = 1e15;
	}
	for(int i = 1; i <= n; i++)  dijkstra(i);
	solve();
	return 0;
}

