#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1e5 + 5 , MOD = 1e9 +7 , inf = 1e15 , M = 3e5 + 5;
void file()
{
	freopen("AvoidCol.inp" , "r" , stdin);
	freopen("AvoidCol.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
struct node
{
	ll u , v , c;
} edge[M];

ll n , m , way[3][N] , d[3][N] , ans = 0 , Mindist;
vector<pi> adj[N];

void dijkstra(ll s , ll p)
{
    priority_queue< pi , vector <pi> , greater <pi> > heap;
    d[p][s] = 0 , way[p][s] = 1;
    heap.push({0 , s});
    while (heap.size())
    {
        ll u = heap.top().se;
        ll t = heap.top().fi;
        heap.pop();
        if (t != d[p][u]) continue;
        for (auto x : adj[u])
        {
          ll  v = x.fi;
          ll  w = x.se; 
            if (t + w < d[p][v]) 
            {
                d[p][v] = t + w ;
                way[p][v] = way[p][u];
                heap.push({d[p][v] , v});
            }
            else if(t + w == d[p][v]) way[p][v] = (way[p][v] + way[p][u]) % MOD; 
        }
    }
}

ll sqr(ll x)
{
	return (x * x) % MOD;
}

int main()
{
	file();
  cin >> n >> m;
  for(int i = 1 ; i <= m ; i++)
  {
  	ll x , y , c;
  	cin >> x >> y >> c;
  	adj[x].pb({y , c});
  	adj[y].pb({x , c});
  	edge[i] = {x , y , c};
  }
  
   for (int i = 1 ; i <= 2 ; i ++)
      for (int j = 1 ; j <= n ; j ++) d[i][j] = inf;
    dijkstra(1 , 1) , dijkstra(n , 2);
    Mindist = d[1][n];
 //   cout << Mindist << '\n';
 //   for(int i = 1 ; i <= n ; i++) cout << i << ' ' << d[1][i] << ' ' << way[1][i] << "||" << d[2][i] << ' ' << way[2][i] << '\n';
    for(int i = 1 ; i <= n ; i++)	
	if(d[1][i] == d[2][i] && d[1][i] + d[2][i] == Mindist) 
     {
    // 	cout << i << ' ';
    	ll tmp = sqr((way[1][i] * way[2][i]) % MOD);
    	ans = (ans + tmp) % MOD;
	 }
//	cout << ans << ' ' << '\n';
	for(int i = 1 ; i <= m ; i++)
	{
		ll u = edge[i].u , v = edge[i].v , w = edge[i].c;
		if(abs(d[1][u] - d[2][v]) < w && d[1][u] + w + d[2][v] == Mindist) ans = (ans + sqr((way[1][u] * way[2][v]) % MOD))% MOD;
		swap(u , v);
		if(abs(d[1][u] - d[2][v]) < w&& d[1][u] + w + d[2][v] == Mindist) ans = (ans + sqr((way[1][u] * way[2][v]) % MOD))% MOD;
	}
	
	 ans =  ((way[1][n] * way[2][1] ) % MOD - ans + MOD ) % MOD;
	 cout << ans;
	 return 0;
}

