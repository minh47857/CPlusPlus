#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<ll , ll>
#define fi first
#define se second
#define pb push_back

const ll N = 1100 , inf = 1e18 ;

void file()
{
	freopen("BUS.inp" , "r" , stdin);
	freopen("BUS.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll n, m , dist[N][N] , q;
vector<pi> adj[N];

void solve(int s)
{
    priority_queue< pi , vector< pi >, greater< pi > > heap;
    for(int i = 0; i <= n; ++i) dist[s][i] = inf;
    dist[s][s] = 0; heap.push({0, s});
    while(!heap.empty())
    {
        ll u = heap.top().se;
        ll du = heap.top().fi;
        heap.pop();
        if(du != dist[s][u]) continue;
        for(auto x : adj[u])
        {
        	ll v = x.fi;
        	ll w = x.se;
           if( dist[s][v] > du + w) dist[s][v] = du + w , heap.push( {dist[s][v] , v});
        }
    }
 //  for (int i = 1; i <= n ; i++) cout << dist[i] << " ";   
}
int main()
{
	file();
       cin >> n >> m;
    for(int i = 1; i <= m; ++i)
    {
    	ll x , y , l;
       cin >> x >> y >> l;
       adj[x].pb( {y, l });
       adj[y].pb( {x, l });
    }
    for (int i = 1 ; i <= n ; i++)	solve(i);
    cin >> q;
    while(q--) 
	{
		int l , r;
		cin >> l >> r ;
	    cout << dist[l][r] << '\n';
	}
	return 0;
}
