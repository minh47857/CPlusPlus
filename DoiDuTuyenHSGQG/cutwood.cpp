#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1000001 , MOD = 1e9 +7 , inf = 1e15;
ll n , k , a[N] , dp[N][35] ;
void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
ll binary(ll d , ll c , ll x)
{
	ll kq;
	while (d <= c)
	{
		ll g = (d + c) / 2 ;
		if (a[g] * 2 > x)
		{
			kq = g ;
			c = g - 1;
		}
		else d = g + 1;
	}
	return kq - 1;
}
int main()
{
  cin >> n >> k;
  for (ll i = 1 ; i <= n ; i++) cin >> a[i];
  sort(a + 1 , a + n + 1);
  for (ll i = 0 ; i <= n ; i++)
  for (ll j = 0 ; j <= 31 ; j++) 
  dp[i][j] = inf;
    dp[0][0] = 0;
  for (ll i = 1 ; i <= n ; i++)
  {
  	dp[i][0] = dp[i - 1][0] + 1;
  	//cout << i << ' ' << 0 << ' ' << dp[i][0] << endl;
  	for (ll j = 1 ; j <= 30 ; j++)	dp[i][j] = min(dp[i - 1][j] + 1 , dp[binary(1 , i , a[i])][j - 1]);
  //	cout << i << ' ' << j << ' ' << dp[i][j] << endl;
  }
  //cout << binary(1 , 4 , a[4] / 2);
  for (ll i = 0 ; i <= 31 ; i++)
  {
  	if (dp[n][i] <= k) 
  	{
  	  cout << i << ' ' << dp[n][i];
		return 0;	
	}
  }
}

