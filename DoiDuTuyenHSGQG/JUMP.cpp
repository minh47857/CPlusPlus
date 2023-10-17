#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 4005 , MOD = 1e9 +7 , inf = 1e15;
void file()
{
	freopen("JUMP.inp" , "r" , stdin);
	freopen("JUMP.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
 ll n , m , k , a[N] , b[N] , dp[N][N] , c[N][N] , row[N][N] , col[N][N];
int main()
{
	file();
  cin >> m >> n >> k;
  for (int i = 1 ; i <= m ; i++) cin >> a[i];
  for (int i = 1 ; i <= n ; i++) cin >> b[i];
  for (int i = 1 ; i <= m ; i++)
  for (int j = 1 ; j <= n ; j++) c[i][j] = 1 + (a[i] + b[j]) % k;
  dp[1][1] = 1;
  
  	row[1][1] = 1;
  	row[1][2] = -1;
  	for (int i = 1 ; i <= m ; i++)
  	for (int j = 1 ; j <= n ; j++)
  	{
  		row[j][i] =  (row[j][i - 1] + row[j][i] ) % MOD;
  		col[i][j] =  (col[i][j] + col[i][j - 1] ) % MOD;
  		dp[i][j] = (row[j][i] + col[i][j]) % MOD;
  		ll r = i + c[i][j] + 1, l = j + c[i][j] + 1;
  		if (r > m) r = m + 1;
  		if (l > n) l = n + 1;
  		col[i][j + 1]  = (col[i][j + 1] + dp[i][j]) % MOD;
  		col[i][l] = (col[i][l] - dp[i][j] + MOD) % MOD;
  	    row[j][i + 1] = (row[j][i + 1] + dp[i][j]) % MOD;
  	    row[j][r] = (row[j][r] - dp[i][j] + MOD) % MOD;
	}
  
 cout << dp[m][n];
  return 0;
}

