#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<ll,ll>
#define fi first
#define se second
#define pb push_back
const ll N = 205 , MOD = 1e9 + 7 , inf = 1e15;

ll n , ans = inf , a[5][N] , dp[N][N][N];
void file()
{
//	freopen(".inp" , "r" , stdin);
//	freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
namespace sub3
{
	ll x[5][3005] , A = 0 , B = 0 , C = 0;
	void solve()
	{
		for (int i = 1 ; i <= n ; i++) 
       for (int t = 1 ; t <= 3 ; t++)
         cin >> x[t][i]; 
         for (int i = 1 ; i <= n ; i++) A += x[1][i] , B += (x[2][i] - i + 1) , C += (x[3][i] - i + 1);
         cout << min({A , B , C});
	}
}
int main()
{
	file();
  cin >> n ;
  if (n < 200)
  {
  	sub3::solve();
  	return 0;
  }
  for (int i = 1 ; i <= n ; i++) 
  for (int t = 1 ; t <= 3 ; t++)
  cin >> a[t][i];
 
  for (int i = 0 ; i <= n ; i++)
  	for (int j = 0 ; j <= n ; j++)
  	  for (int k = 0 ; k <= n ; k++)
  	dp[i][j][k] = inf;
  	dp[0][0][0] = 0;
  for (int i = 1 ; i <= n ; i++)
  {
  	for (int j = 0 ; j <= i ; j++)
  	   for (int k = 0 ; k <= i ; k++)
  	    {
  	    if(dp[i - 1][j][k] != inf)	      dp[i][j][k] = dp[i - 1][j][k] + a[1][i] ;
  	    if(dp[i - 1][j - 1][k] != inf && j > 0)    dp[i][j][k] = min(dp[i - 1][j - 1][k] + a[2][i] - j + 1 , dp[i][j][k]) ;// cout << 2 << ' ' << dp[i - 1][j - 1][k] << ' ';
  	    if(dp[i - 1][j][k - 1] != inf && k > 0)    dp[i][j][k] = min(dp[i - 1][j][k - 1] + a[3][i] - k + 1 , dp[i][j][k]) ;// cout << 3 << ' ' << a[3][i] << ' ';
  	       if (i == n) ans = min(dp[i][j][k] , ans);
	    }
  }
  cout << ans;
  return 0;
}
