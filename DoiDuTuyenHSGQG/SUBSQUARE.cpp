#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 205, MOD = 1e9 + 7;
ll row[N][N], col[N][N], re_row[N][N], re_col[N][N], dp[N][N][N], ans = 1, n, base = 31, po[N];
char s[N][N];

ll get(int x, int y, ll Hash[N][N], int l)
{
	return ( Hash[l][y] - Hash[l][x - 1] * po[y -x + 1] +MOD*MOD ) % MOD;
}
ll re_get(int x, int y, ll Hash[N][N], int l)
{
	return ( Hash[l][x] - Hash[l][y + 1] * po[y - x + 1] +MOD*MOD ) % MOD;
}
bool check(int a, int b, int c)
{
	ll num1 = get(b , b + c, row, a);
	ll num2 = get(a , a + c, col, b);
	if( num1 != re_get(b , b + c, re_row, a) ) return false;
	if( num2 != re_get(a , a + c, re_col, b) ) return false;
	if (num1 != get(b , b + c, row, a + c) ) return false;
	if (num2 != get(a , a + c, col, b + c ) ) return false;
	return true;
}
int main()
{
      cin >> n;
      
      for (int i = 1 ; i <= n ; i++) 
           for (int j = 1; j <= n; j++)
            cin >> s[i][j] , dp[i][j][0] = 1;
            
      po[0] = 1;
     for(int i= 1; i <= n ; i++) po[i] = ( po[i-1] * base )%MOD;
     
      for (int i = 1; i <= n ; i++) 
      for (int j = 1; j <= n ; j++)
      {
      	row[i][j] = (row[i][j - 1] * base + s[i][j] - 'a' + 1) % MOD;
      	col[i][j] = (col[i][j - 1] * base + s[j][i] - 'a' + 1) % MOD;	
	  }
	  
	  for ( int i = 1; i <= n ; i++)
	  for ( int j = n ; j >= 1; j--)
	  {
	  	re_row[i][j] = (re_row[i][j + 1] * base + s[i][j] - 'a' + 1) % MOD;
      	re_col[i][j] = (re_col[i][j + 1] * base + s[j][i] - 'a' + 1) % MOD;	
	  }

  for (ll k = 1 ; k < n ; k++)
    {
  	    for (int i = 1 ; i <= n - k ; i++)
  	    {
  	    	for (int j = 1 ; j <= n - k  ; j++ )
  	    	{
  	    		if(dp[i + 1][j + 1][k - 2] == 0 && k >= 2) continue;
  	    		if (check ( i , j, k) ) dp[i][j][k] = 1 , ans = max (ans , k + 1);	
			}
		}
	}     
	cout << ans;
	return 0; 
}

