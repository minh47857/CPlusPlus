#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 255 , MOD = 1e9 +7 , inf = 1e15 , 
      row[4] = {0 , 1 , -1 , 0} ,
      col[4] = {1 , 0 , 0 , -1} ;
void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
 
 ll n , a[N][N] , ans = 0 , res = 0;
 pi par[N][N];
 
pi root (ll x , ll y)
{
	if (par[x][y].fi < 0) return {x , y};
	par[x][y] = root(par[x][y].fi , par[x][y].se);
	return par[x][y];
}

void merge(int x , int y , int u , int v)
{
//	if (u < 1 || v < 1 || u > m || v > n || par[u][v].fi == inf) return;
	pi q = root(x , y);
	pi p = root(u , v);
	if (q.fi == p.fi && q.se == p.se) return;
	if (par[p.fi][p.se].fi < par[q.fi][q.se].fi) swap(q , p);
	par[q.fi][q.se].fi += par[p.fi][p.se].fi;
	ans = max(ans , -par[q.fi][q.se].fi);
	par[p.fi][p.se] = {q.fi , q.se};
}

void solve(int x , int y , int u , int v)
{
	pi q = root(x , y);
	pi p = root(u , v);
	cout << 
	res = max(res , -(par[q.fi][q.se].fi + par[p.fi][p.se].fi) );
}

int main()
{
 cin >> n ;
 for (int i = 1 ; i <= n ; i++)
 for (int j = 1 ; j <= n ; j++)
 cin >> a[i][j];
 memset(par , - 1 , sizeof(par));
 for (int i = 1 ; i <= n ; i++)
 for (int j = 1 ; j <= n ; j++)
 {
 	for(int k = 0 ; k < 4 ; k++)
 	{
 		int u = i + row[k] , v = j + col[k];
 		if(u < 1|| u > n || v < 1 || v > n || a[i][j] != a[u][v]) continue;
 		merge(i , j , u , v);
	}
 }
 cout << ans << '\n';
 
 for (int i = 1 ; i <= n ; i++)
 for (int j = 1 ; j <= n ; j++)
 {
 	for(int k = 0 ; k < 4 ; k++)
 	{
 		int u = i + row[k] , v = j + col[k];
 		if(u < 1|| u > n || v < 1 || v > n || a[i][j] == a[u][v]) continue;
 		solve(i , j , u , v);
	}
 }
 cout << res << '\n';
 return 0;
}

