#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 33 , MOD = 1e9 +7 , inf = 1e15;
ll n , m , k , d[N*N] , match[N*N] , res = 0 , dd , c , dp[N][N] , g;
char s[N][N];
vector <ll> adj[N*N];
void file()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
ll findd(int u , int v , int l)
{
	return dp[u][v] - dp[u][v - l] - dp[u - l][v] + dp[u - l][v - l];
} 
bool ghep(int u)
{
	if (d[u] != 1) d[u] = 1;
	else return false;
	for (auto x : adj[u])
	{
		if (match[x] == 0 || ghep(match[x])) 
		{
			match[x] = u;
			return true;
		}
	}
	return false;
}
bool solve(int u , int v , int len )
{
	vector<pi> l , r;
	l.pb({0 , 0}) , r.pb({0 , 0});
	ll ans = 0;
	memset(match , 0 , sizeof(match));
	for (int i = 1 ; i <= m ; i++)
	for (int j = 1 ; j <= n ; j++)
	{
		if (s[i][j] == '#' || (i > u - len && i <= u && j > v - len && j <= v) ) continue;
		if( (i + j) % 2 == 0) r.pb({i , j});
		else l.pb({i , j});
	}
	for (int i = 1 ; i < r.size() ; i++)
	{
		adj[i].clear();
			for (int j = 1 ; j < l.size() ; j++)
	        if ( (r[i].fi == l[j].fi && abs(r[i].se - l[j].se) == 1) || (r[i].se == l[j].se && abs(r[i].fi - l[j].fi) == 1) ) adj[i].pb(j);
	}
	for (int i = 1 ; i < r.size() ; i++)
	{
		memset(d , 0 , sizeof(d));
		if (ghep(i)) ans++;
	}
	if (ans >= k) return true;
	return false;
}
bool check_square(ll x)
{
	for (int i = x ; i <= m ; i++)
	for (int j = x ; j <= n ; j++)
	{
		if (findd(i , j , x) != 0) continue;
		if(solve(i , j , x)) return true;
	}
	return false;
}
int main()
{
	file();
  cin >> m >> n >> k;
  for (int i = 1 ; i <= m ; i++)
  for (int j = 1 ; j <= n ; j++)
  {
   cin >> s[i][j];
   dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] ;
   if (s[i][j] == '#') dp[i][j]++;
  }
  dd = 1 , c = min(m , n);
  while (dd <= c)
  {
  	g = (dd + c) / 2;
  	if (check_square(g)) res = g , dd = g + 1;
  	else c = g - 1;
  }
  cout << res;
  return 0;
}

