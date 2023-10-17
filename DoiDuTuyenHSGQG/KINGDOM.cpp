#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1005 , MOD = 1e9 +7 , inf = 1e9;
ll ans = inf , n , dp[N][N] , c[N][N];
void file()
{
	//freopen(".inp","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
int main()
{
	file();
    cin >> n; 
    for (int i = 1 ; i <= n ; i++)
    for (int j = 1;  j <= n ; j++)
    	cin >> c[i][j];
    	
    	for (int i = 1 ; i <= n + 1 ; i++)
    	for (int j = 1 ; j <= n + 1 ; j++) dp[i][j] = inf;
    	
    	dp[n + 1][n + 1] = dp[n + 1][n] = dp[n][n + 1] = 0;
    	
	for (int i = n + 1; i >= 1 ; i--)
	{
		for (int j = n + 1; j >= 1 ;j--)
	    {
	    	if (i == j) continue;
	    	if ( i > j)
	    	{
	    		if (i == j + 1)
	    		       for (int k = i + 1; k <= n + 1 ; k++)  dp[i][j] = min(dp[i][j] , dp[i][k] + c[k][j]);
	    	    else dp[i][j] = min(dp[i][j] , dp[i][j + 1] + c[j][j + 1]);	
			}
			else
			{
				if (i + 1 == j)
				       for  (int k = j + 1; k <= n + 1 ; k++) dp[i][j] = min(dp[i][j] , dp[k][j] + c[k][i]) ;
				else dp[i][j] = min(dp[i][j] , dp[i + 1][j] + c[i][i + 1]);
			}
		}
		
	}
	
	for (int i = 2; i <= n + 1 ; i++) ans = min(ans , min(dp[i][1] , dp[1][i]) + c[i][1]);
	cout << ans;
	return 0;
}

