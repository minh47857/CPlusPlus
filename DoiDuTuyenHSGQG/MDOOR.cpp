#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1001 , MOD = 1e9 +7 , inf = 1e15;
ll n , m , c , a[N][N] , w[N][N];
void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
namespace sub2
{
	ll ans = -inf , dp[N][N];
	void solve()
	{
		for (int i = 1 ; i <= n ; i++) dp[i][0] = dp[i][m + 1] = -inf;
		for (int i = 1 ; i <= n ; i++)
		 for (int j = 1 ; j <= m ; j++)
				dp[i][j] = max({dp[i - 1][j] , dp[i - 1][j + 1] , dp[i - 1][j - 1]}) + w[i][j];
	   for (int i = 1 ; i <= m ; i++) ans = max(ans , dp[n][i]);
	   cout << ans;		
	}
}
namespace sub1
{
	ll res = -inf , f[35][35][35];
	vector <pi> edge;
	ll Dfs(int u , int v , int val)
	{
		//cout << u << ' ' << v << ' ' << val << endl;
		if (v == 0 || v == m + 1) return -inf;
		if(u == n && (val == c || a[u][v] == 0)) return 0;
		if(f[u][v][val] != -1) return f[u][v][val];
		ll ans = -inf;
		if (u == n) ans = 0;
		if (u != n) ans = max({Dfs(u + 1 , v , val) + w[u + 1][v] , Dfs(u + 1 , v + 1 , val) + w[u + 1][v + 1], Dfs(u + 1 , v - 1 , val) + w[u + 1][v - 1] , ans});
		if (val < c && a[u][v] == 1)
		{
			for (auto x : edge)
			{
			 	ans  = max(ans , Dfs(x.fi , x.se , val + 1) + w[x.fi][x.se]);
			}
		}
	//	cout << ans << endl;
		f[u][v][val] = ans;
		return ans;
	}
	void solve()
	{
		memset(f , - 1 , sizeof(f));
		for (int i = 1; i <= n ; i++)
		for (int j = 1 ; j <= m ; j++)
		if (a[i][j] == 1) edge.pb({i , j});
	    for (int i = 1 ; i <= m ; i++) res = max(Dfs(1 , i , 0) + w[1][i] , res);
	  //  for (int i = 1 ; i <= m ; i++) cout << Dfs(1 , i , 0) + w[1][i] << endl;
		cout << res ;
	}
}
namespace sub3
{
	ll f[35][1005][1005] , g[35] , res = -inf;
	void solve()
	{
		for (int i = 1 ; i <= n ; i++) 
		for (int j = 0 ; j <= c ; j++)
		f[j][i][0] = f[j][i][m + 1] = -inf;
		for (int t = 0 ; t <= c ; t++)
		{
			for (int i = 1 ; i <= n ; i++)
			{
				for (int j = 1 ; j <= m ; j++)
				{
					f[t][i][j] = max({f[t][i - 1][j - 1] , f[t][i - 1][j + 1] , f[t][i - 1][j]}) + w[i][j];
				if (a[i][j] == 1 && t > 0)	f[t][i][j] = max(g[t - 1] + w[i][j] , f[t][i][j]);
				if (a[i][j] == 1) g[t] = max(g[t] , f[t][i][j]);
			//	  cout << i << ' ' << j << ' ' << t <<' ' << f[t][i][j] << ' ' <<g[t] << endl;
				}
			}
		}
		for (int i = 1 ; i <= m ; i++)
		for (int j = 0 ; j <= c ; j++)
		res = max(res , f[j][n][i]);
		cout << res;
	}
}
namespace sub4
{
    ll dp[N][N], x, y, z = -inf;
   ll get()
   {
   	ll ans = -inf;
   	 for (int i = 1 ; i <= n ; i++)
   	 for (int j = 1 ; j <= m ; j++)
   	 if (a[i][j] == 1) ans = max(ans , dp[i][j]);
   	 return ans;
   }
    void solve()
    {
        memset(dp, -0x3f, sizeof(dp));
        for(int i = 1 ; i <= n ; i++)
            for (int j = 1 ; j <= m ; j++)
              if (i != 1) dp[i][j] = max({dp[i - 1][j - 1] , dp[i - 1][j] , dp[i - 1][j + 1]}) + w[i][j];
              else dp[i][j] = w[i][j];
        x = get(); 
        
        memset(dp, -0x3f, sizeof(dp));
        for (int i = 1 ; i <= n ; i++)
            for (int j = 1 ; j <= m ; j++)
           {
        	dp[i][j] = max({dp[i - 1][j - 1] , dp[i - 1][j] , dp[i - 1][j + 1]}) + w[i][j];
        	if (a[i][j] == 1) dp[i][j] = max(dp[i][j] , w[i][j]);
		   }
		y = get();
		
        for (int i = 1 ; i <= m ; i++) z = max(z , dp[n][i]);
        cout << x + (c - 1) * y + z;
    }
}
int main()
{
	file();
  cin >> n >> m >> c ;
  for (int i = 1 ; i <= n ; i++)
  for (int j = 1 ; j <= m ; j++)
  cin >> a[i][j];
  for (int i = 1 ; i <= n ; i++)
  for (int j = 1 ; j <= m ; j++)
  cin >> w[i][j];
 if (c == 0) sub2::solve();
 else sub4::solve();
 
  return 0;
}

