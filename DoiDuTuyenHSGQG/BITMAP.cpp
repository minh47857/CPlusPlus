#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1001 , MOD = 1e9 +7 , inf = 1e15;
ll t , n , m , ans = 1;
pi par[N][N] ;
void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
pi root (ll x , ll y)
{
	if (par[x][y].fi < 0) return {x , y};
	par[x][y] = root(par[x][y].fi , par[x][y].se);
	return par[x][y];
}
void merge(int x , int y , int u , int v)
{
	if (u < 1 || v < 1 || u > m || v > n || par[u][v].fi == inf) return;
	pi q = root(x , y);
	pi p = root(u , v);
	if (q.fi == p.fi && q.se == p.se) return;
	if (par[p.fi][p.se].fi < par[q.fi][q.se].fi) swap(q , p);
	par[q.fi][q.se].fi += par[p.fi][p.se].fi;
	ans = max(ans , -par[q.fi][q.se].fi);
	par[p.fi][p.se] = {q.fi , q.se};
}
int main()
{
	file();
  cin >> m >> n ;
  for (int i = 1 ; i <= m ; i++)
  for (int j = 1 ; j <= n ; j++)
  {
  	char s ;
    cin >> s ;
    par[i][j]= {inf , 0};
    if(s - '0' == 0) continue;
   	par[i][j].fi = -1;
   merge(i , j , i - 1 , j);
   merge(i , j , i , j - 1);
  }
  cin >> t;
  while(t--)
  {
  	int i , j;
   cin >> i >> j;
   if (par[i][j].fi != inf)
   {
   	cout << ans << '\n';
   	continue;
   }
   par[i][j].fi = -1;
   merge(i , j , i - 1 , j);
   merge(i , j , i + 1 , j);
   merge(i , j , i , j + 1);
   merge(i , j , i , j - 1);
   cout << ans << '\n';
  }
  return 0;
}

