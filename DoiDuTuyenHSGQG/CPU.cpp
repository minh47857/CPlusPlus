#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 105 , MOD = 1e9 +7 , inf = 1e15;
ll n , dp[N][N] , c[21][21] , f[2000000];
string s[21];
void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
ll calc(int u , int v)
{
	memset(dp , 0 , sizeof (dp));
	for (int i = 1 ; i <= 101 ; i++) dp[i][0] = dp[0][i] = i;
	for (int i = 1 ; i < s[u].size() ; i++)
	for (int j = 1 ; j < s[v].size() ; j++)
	{
		dp[i][j] = min( dp[i - 1][j] , dp[i][j - 1]) + 1;
		//cout << dp[i][j] << ' ' ;
		if (s[u][i] == s[v][j]) dp[i][j] = min(dp[i][j] , dp[i - 1][j - 1] + 1);
		//cout << "*" << i << ' ' << j << ' ' << dp[i][j] << endl;
	}
	return dp[s[u].size() - 1][s[v].size() - 1];
}
int BIT(int x , int k)
{
	return (x >> k) & 1;
}
ll  solve(ll mask)
{
	//cout << mask << endl;
	if (f[mask] != -1) return f[mask];
	if (mask == 0) return 0;
	ll cnt = inf ;
	for (int i = 1 ; i < 2 * n ; i++)
	{
		if (!BIT(mask , i - 1)) continue;
		for (int j = i + 1 ; j <= 2 * n ; j++)
		{
			if (BIT(mask , j - 1)) cnt = min(cnt , max(solve(mask ^ (1 << (i - 1)) ^ (1 << (j - 1))) , c[i][j])) ;
		}
	}
	f[mask] = cnt;
	return cnt;
}
int main()
{
	file();
  cin >> n;
  memset(f , - 1 , sizeof(f));
  for (int i = 1 ; i <= 2 * n ; i++) cin >> s[i] , s[i] = ' ' + s[i];
  for (int i = 1 ; i  < 2 * n ; i++)
  for (int j = i + 1 ; j <= 2 * n ; j++)
     c[i][j] = c[j][i] = calc(i , j) ;// cout << i << ' ' << j << ' ' <<c[i][j] << endl;
  cout << solve((1 << (2 * n)) - 1);
  return 0;
}

