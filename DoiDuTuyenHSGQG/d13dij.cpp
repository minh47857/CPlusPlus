#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 410 , MOD = 1e9 +7 , inf = 1e15;
ll n , m , c[N][N] , w[N][N] , q;
void file()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
ll get()
{
	ll ans = 0;
	for (int i = 1 ; i <= n + 3 ; i++)
	for (int j = 1 ; j <= n + 3 ; j++)
	if (i != j && w[i][j] != inf) ans = ans + w[i][j];
	return ans;
}
void update(ll x)
{
	
	for (int i = 1 ; i < x ; i++)
	for (int j = 1 ; j < x ; j++)
	w[i][x] = min(w[i][j] + w[j][x] , w[i][x]) ;
	
	for (int i = 1 ; i < x ; i++)
	for (int j = 1 ; j < x ; j++)
	w[x][i] = min(w[x][j] + w[j][i] , w[x][i]) ;
	
	for (int i = 1 ; i < x ; i++)
	for (int j = 1 ; j < x ; j++)
	w[i][j] = min(w[i][j] , w[i][x] + w[x][j]);

}
void solve()
{
	for (int i = 1 ; i <= n + 3 ; i++)
	for (int j = 1 ; j <= n + 3 ; j++)
	w[i][j] = c[i][j];
	ll s;
	cin >> s;
	for (int i = 1 ; i <= s ; i++)
	{
		ll u , v , cp;
		cin >> u >> v >> cp;
		w[u][v] = min(w[u][v] , cp);
	}
	update(n + 1);
	update(n + 2);
	update(n + 3);
	cout << get() << '\n';
}
int main()
{
	file();
  cin >> n >> m >> q ;
  for (int i = 1 ; i <= n + 3 ; i++)
  for (int j = 1 ; j <= n + 3 ; j++)
  if (i != j) c[i][j] = inf;
  else c[i][j] = 0;
  for (int i = 1 ; i <= m ; i++) 
  {
  	ll x , y , w;
  	cin >> x >> y >> w;
  	c[x][y] = min(c[x][y] , w);
  }
  for (int k = 1 ; k <= n ; k++)
  for (int i = 1 ; i <= n ; i++)
  for (int j = 1 ; j <= n ; j++)
  c[i][j] = min(c[i][j] , c[i][k] + c[k][j]);
  while(q--) solve();
  return 0;
}

