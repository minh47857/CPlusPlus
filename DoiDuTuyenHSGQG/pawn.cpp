#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
#define pii pair < string , ll >
const ll N = 101 , MOD = 1e9 +7;

struct node 
{
	ll r , c , m;
};

ll ans = -1 , n , m , k, dp[N][N][12] , a[N][N];
vector <node> trace[N][N][12];
pii dist[N][N][12] , res;
char ss[N][N];
void file()
{
	freopen("pawn.inp","r",stdin);
	freopen("pawn.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
pii combine_Min (pii x , pii y)
{
	if (x.se < y.se) return x;
	if (x.se == y.se) 
	{
		if (x.fi < y.fi) return x;
		return y;
	}
	return y;
}
void Dfs(int x , int y , int z)
{
	dist[x][y][z].se = INT_MAX;
  for (auto  v : trace[x][y][z])
      {
  	      if (dist[v.r][v.c][v.m].se == 0 ) Dfs(v.r , v.c , v.m);
  	      string s;
  	      if (y == v.c + 1) s = "R"  ; else s = "L";
  	    string  str = dist[v.r][v.c][v.m].fi + s  ;
  	    ll  col =  dist[v.r][v.c][v.m].se;
  	     dist[x][y][z] = combine_Min(dist[x][y][z] , {str , col} );
	  }	
}
void solve(int u , int v , int x, int y)
{
	if(v < 1 || v > m) return ;
	for (int i = 0 ; i < k ; i++)
	{
		if (dp[u][v][i] == -1) continue;
		ll t = (i + a[x][y]) % k;
		if (dp[u][v][i] + a[x][y] > dp[x][y][t]) 
		{
			dp[x][y][t] = dp[u][v][i] + a[x][y] , trace[x][y][t].clear();
		//	cout << u << ' ' << v << ' ' << i << ' ' << x << ' ' << y << ' ' << t << ' ' << dp[u][v][i] << ' ' << dp[x][y][t] <<endl;
		}
		if (dp[u][v][i] + a[x][y] == dp[x][y][t]) trace[x][y][t].pb({u , v , i});
	}
}

int main()
{
	file();
   cin >> n >> m >> k; 
   k = k + 1;
   for (int i = 1; i <= n ; i++)
   for (int j = 1; j <= m ; j++)
   cin >> ss[i][j] , a[i][j] = ss[i][j] - '0';
   
   for (int i = 1; i <= n ; i++)
   for (int j = 1; j <= m ; j++)
   for (int l = 0; l < k ; l++)  dp[i][j][l] = -1;
   
   for (int i = 1; i <= m ; i++) 
   {
   	dp[n][i][a[n][i] % k] = a[n][i];
   	dist[n][i][a[n][i] % k] = {"" , i};
   }
  
   
   for (int i = n - 1; i >= 1 ; i--)
     for (int j = 1; j <= m ; j++)
     {
     	solve(i + 1 , j - 1 , i , j);
     	solve(i + 1 , j + 1 , i , j);
	 }
   for (int i = 1; i <= m ; i++)  ans = max (ans , dp[1][i][0]);
   cout << ans << '\n' ;
  if (ans == -1) return 0;
  
  res.se = INT_MAX; 
 for (int i = 1; i <= m ; i++) 
  {
  	if (dp[1][i][0] == ans) 
     {
     	Dfs( 1 , i , 0);
  	    res = combine_Min(dist[1][i][0] , res);
     }
  }
  
  cout << res.se << '\n';
  cout <<res.fi;
  return 0;
}

