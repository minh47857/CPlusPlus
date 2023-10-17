#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 100005 , MOD = 1e9 +7 , inf = 1e15;

void file()
{
	freopen("NOBITA.inp" , "r" , stdin);
	freopen("NOBITA.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

struct node
{
	ll  u , v , c;
};


 ll n , m , k , a[N] , gate[N];
 vector<pi> adj[N];
 vector<node> ve;
 
namespace sub1
{
	ll par[N] , ans = 0;
int root(int v)
{
    return par[v] < 0
            ? v
            : (par[v] = root(par[v]));
}

bool merge(int x, int y) 
{
    if ((x = root(x)) == (y = root(y)) )   return false ;
    if (par[y] < par[x])  swap(x, y);
    par[x] += par[y];
    par[y] = x;
    return true;
}
	void solve()
	{
		memset(par , -1 , sizeof(par));
		for (auto x : ve)	if (merge(x.u , x.v)) ans += x.c;
		cout << ans;
	}
}

namespace sub2
{
	ll dist[N];
	void dijkstra(int s)
 {
    priority_queue< pi , vector< pi >, greater< pi > > heap;
    for(int i = 0 ; i <= n ; i++) dist[i] = inf;
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
 }
 void solve()
 {
 	dijkstra(1);
 	cout << dist[a[1]];
 }
}

namespace sub3
{
	ll dist[N][20] , ans = inf;
	
	struct v
     {
     	ll fi , se , rd;
	 };
	 
	 bool operator > (const v&a , const v&b)
	 {
	 	return a.fi  > b.fi;
	 }
	 
	 int Bit (int x , int k)
	 {
	 	return (x >> k) & 1;
	 }
	void dijkstra(int s)
 {
    priority_queue< v , vector< v >, greater< v > > heap;
    
    for(int i = 0 ; i <= n ; i++) 
	for (int j = 0 ; j < (1 << k) ; j++)	dist[i][j] = inf;
	
	if (gate[s] != 0) dist[s][1 << (gate[s] - 1)] = 0 , heap.push({0 , s , 1 << (gate[s] - 1)});
	else dist[s][0] = 0 , heap.push({0 , s , 0});
   
    while(!heap.empty())
    {
        ll u = heap.top().se;
        ll du = heap.top().fi;
        ll t = heap.top().rd;
        heap.pop();
        
        if(du != dist[u][t]) continue;
        
        for(auto x : adj[u])
        {
        	ll v , w , tt = t;
        	 v = x.fi;
           if (gate[v] != 0 && !Bit(t , gate[v] - 1)) tt += (1 << (gate[v] - 1)) ;
           if (gate[v] && Bit(t , gate[v] - 1)) w = 0;
           else w = x.se;
           if( dist[v][tt] > du + w) dist[v][tt] = du + w , heap.push( {dist[v][tt] , v , tt} );
        }
        
        
        for (int i = 0 ; i < k ; i++)
        {
        	if (!Bit(t , i)) continue;
        	if (dist[a[i + 1]][t] > du) dist[a[i + 1]][t] = du , heap.push({du , a[i + 1] , t});
		}
    }
 }
 void solve()
 {
 	dijkstra(1);
 	for (int i = 1 ; i <= n ; i++) ans = min(ans , dist[i][(1 << k) - 1]);
 	cout << ans;
 }
}

int main()
{
	file();
  cin >> n >> m;
  for (int i = 1 ; i <= m ;  i++) 
  {
  	ll u , v , w;
  	cin >> u >> v >> w;
  	adj[u].pb({v , w});
  	adj[v].pb({u , w});
  	ve.pb({u , v , w});
  }
  sort(ve.begin() , ve.end());
  cin >> k;
  memset(gate , 0 , sizeof(gate));
  for (int i = 1 ; i <= k ; i++) cin >> a[i] , gate[a[i]] = i;
  if (k == n) 
  {
  	sub1::solve();
  	return 0;
  }
  if (k == 1) 
  {
  	sub2::solve();
  	return 0;
  }
  if (k <= 4 && k > 1) 
  {
  	sub3::solve();
  	return 0;
  }
}

