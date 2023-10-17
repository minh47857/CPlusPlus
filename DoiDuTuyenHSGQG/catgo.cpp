#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 52 , MOD = 1e9 +7 , inf = 1e15 , M = 2501;
void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , m , a[N] , c[N] , ans = 0, dp[N][N][M] , pos;

int main()
{
	file();
 cin >> n;
 for(int i = 1 ; i <= n ; i++) cin >> a[i];
 cin >> m;
 for(int i = 1 ; i <= m ; i++)
 {
 	int x , y;
 	cin >> x >> y;
 	c[x] = y;
 }
 memset(dp , -1 , sizeof(dp));
 dp[1][0][0] = 0;
 for(int i = 1 ; i <= n ; i++)
   for(int j = 0 ; j < a[i] ; j++)
     for(int k = 0 ; k < M  ; k++)
     {
     //	cout << i << ' ' << j << ' ' << k << ' ' << dp[i][j][k] << '\n';
     	if(dp[i][j][k] == -1) continue;
     	dp[i + 1][0][k] = max(dp[i + 1][0][k] , dp[i][j][k] + c[a[i] - j]);
     	ans = max(ans , dp[i + 1][0][k]);
     	for(int l = j + 1 ; l < a[i] ; l++)
     	 dp[i][l][k + 1] = max(dp[i][l][k + 1] , dp[i][j][k] + c[l - j] - k - 1) , ans = max(ans , dp[i][l][k + 1]) ;
	 }
 cout << ans;
 return 0;
}

