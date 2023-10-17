#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 2005 , MOD = 1e9 +7 , inf = 1e16;
ll n , c[N][N] , dp[N][N] , ans = inf ;
void file()
{
	freopen("bitonic.inp","r",stdin);
	freopen("bitonic.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
int main()
{
	file();
   cin >> n; 
   for (int i = 1 ; i <= n ; i++)
   for (int j = 1 ; j <= n ; j++)
   cin >> c[i][j];
   
   for (int i = 1; i < n ; i++)
   for (int j = 1; j < n ; j++)
   dp[i][j] = inf;
   dp[1][1] = 0;
   dp[1][2] = c[2][1];
   dp[2][1] = c[1][2];
   
   for (int i = 1; i < n ; i ++)
   for (int j = 1 ; j < n ; j++)
   {
   	  if ( i == j) continue;
   	  if ( i < j)
   	  {
   	  	if ( i == j - 1) for (int k = 1; k <= i - 1 ; k++) dp[i][j] = min(dp[i][j] , dp[i][k] + c[j][k]);
   	  	else dp[i][j] = min(dp[i][j] , dp[i][j - 1] + c[j][j - 1]);
	  }
	  else 
	  {
	  	if (j == i - 1) for (int k = 1 ; k <= j - 1 ; k++) dp[i][j] = min(dp[i][j] , dp[k][j] + c[k][i]);
	  	else dp[i][j] = min (dp[i][j] , dp[i - 1][j] + c[i - 1][i]);
	  }
   }
   for (int i = 1; i < n; i++)  	ans = min({dp[n - 1][i] + c[n - 1][n] + c[n][i] , ans , dp[i][n - 1] + c[i][n] + c[n][n - 1] });
   cout << ans ;
   return 0;
} 

