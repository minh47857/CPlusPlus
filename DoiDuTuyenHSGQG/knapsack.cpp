#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 101 , MOD = 1e9 +7 , inf = 1e15 , M = 1e5 + 1;
ll n , w , a[N] , b[N] , dp[N][M] , res = 0 , sum = 0;
void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
int main()
{
	file();
  cin >> n >> w;
  for (int i = 1 ; i <= n ; i++) cin >> a[i] >> b[i] , sum += b[i];
  for (int i = 1 ; i <= sum ; i++) dp[0][i] = inf;
  dp[0][0] = 0;
  for (int i = 1 ; i <= n ; i++)
  {
  	for (ll j = 0 ; j <= sum ; j++)
      {
      	dp[i][j] = dp[i - 1][j];
  	    if (j >= b[i] && dp[i - 1][j - b[i]] != inf)	dp[i][j] = min(dp[i][j]  , dp[i - 1][j - b[i]] + a[i]);
      }
  }
  for (ll j = 1 ; j <= sum ; j++) if (dp[n][j] <= w) res = max(res , j);
  cout << res;
  return 0;
}

