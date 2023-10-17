#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<ll,ll>
#define fi first
#define se second
#define pb push_back
const ll N = 1000005 , MOD = 1e9 + 7 , inf = 1e18;
struct node
{
    ll fi , se , rd;
} edge[N];
ll n , m , hc , sc , sj , hj , d[4][N] , ans ;
vector <pi> adj[N];
void file()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
void dijkstra(ll s , ll p)
{
    priority_queue< pi , vector <pi> , greater <pi> > heap;
    d[p][s] = 0;
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
                heap.push({d[p][v] , v});
            }
        }
    }
}

void solve()
{
    ans = 0;
    cin >> hc >> sc >> hj >> sj;
    for (int i = 1; i <= n; i ++) adj[i].clear();
     for (int i = 0 ; i <= 3 ; i ++)
      for (int j = 1 ; j <= n ; j ++) d[i][j] = inf;
        for (int i = 1 ; i <= m ; i++)
		{
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].pb({v , w});
            adj[v].pb({u , w});
            edge[i] = {u, v, w};
        }
      dijkstra(hc , 0) , dijkstra(sc , 1) , dijkstra(hj , 2) , dijkstra(sj , 3);
   
        for (int i = 1; i <= n; i ++) if ( d[0][i] == d[2][i] && d[0][i] + d[1][i] == d[0][sc] && d[2][i] + d[3][i] == d[2][sj] ) ans ++;

        bool check = false;
        for (int i = 1; i <= m; i ++)
		{
            int u = edge[i].fi, v = edge[i].se;
            ll w = edge[i].rd;
            if ( d[0][u] + w + d[1][v] == d[0][sc] && d[2][u] + w + d[3][v] == d[2][sj] && d[0][u] == d[2][u] ) {check = true ; break;}
            if ( d[0][v] + w + d[1][u] == d[0][sc] && d[2][v] + w + d[3][u] == d[2][sj] && d[0][v] == d[2][v] ) {check = true ; break;}
        }

        if (check)
		  {
		  	cout << -1 << '\n';
		  	return;
		  }

        for (int i = 1; i <= m; i ++){
            int u = edge[i].fi, v = edge[i].se;
            ll w = edge[i].rd;
            if ( d[0][u] + w + d[1][v] == d[0][sc] && d[2][v] + w + d[3][u] == d[2][sj] && abs(d[0][u]-d[2][v]) < w ) ans ++;
            if ( d[0][v] + w + d[1][u] == d[0][sc] && d[2][u] + w + d[3][v] == d[2][sj] && abs(d[0][v]-d[2][u]) < w ) ans ++;
        }

        if ( d[0][sc] < d[2][sc] && d[2][sc] + d[3][sc] == d[2][sj] ) ans ++;
        if ( d[0][sj] > d[2][sj] && d[0][sj] + d[1][sj] == d[0][sc] ) ans ++;

        cout << ans << '\n';
}


int main()
{
    file();
    while (cin >> n >> m)
    {
        if (n == m && n == 0) return 0;
        else solve();
    }
}
