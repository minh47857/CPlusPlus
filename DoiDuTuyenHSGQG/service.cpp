#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 501 , MOD = 1e9 +7 , inf = 1e15;
ll n , m , q , x , y , z , res , c[N][N] , l[N];
vector<ll> adj[N];
void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
void solve()
{
	 res = 0;
	cin >> x >> y >> z;
	for (int i = 1 ; i <= n ; i++) l[i] = min({c[i][x] , c[i][y] , c[i][z]}) ;// cout << l[i] << endl;
	for (int i = 1 ; i <= n ; i++)
	{
		ll best = inf ;
		for (auto j : adj[i])	if (c[j][i] + l[j] == l[i]) best = min(best , c[j][i]);
	//	cout << best <<' ';
	if (best != inf)	res += best;
	}
	cout << res * 100 << '\n';
}
int main()
{
    cin >> n >> m >> q ;
  for (int i = 1 ; i <= n ; i++)
  for (int j = 1 ; j <= n ; j++)
  if (i != j) c[i][j] = inf;
    for(int i = 1 ; i <= m ; i++) 
    {
    	ll u , v , w;
    	cin >> u >> v >> w;
    	adj[u].pb(v);
    	adj[v].pb(u);
    	c[u][v] = min(c[u][v] , w);
    	c[v][u] = min(c[v][u] , w);
	}
	
	for (int k = 1 ; k <= n ; k++)
	for (int i = 1 ; i <= n ; i++)
	for (int j = 1 ; j <= n ; j++) 
	c[i][j] = min(c[i][j] , c[i][k] + c[k][j]);
	while (q--) solve();
}

