#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<ll,ll>
#define fi first
#define se second
#define pb push_back

ll t , n , dp[15][15][15] , a[15] , f[15][15][15];

ll solve(ll n)
{
	memset(dp , 0 , sizeof dp);
	memset(a , 0 , sizeof a);
	ll cnt = 0;
	while(n > 0)
	{
		a[++cnt] = n % 10;
		n /= 10;
	}
	dp[0][0][0] = 1;
	for (ll i = 0 ; i < cnt ; ++i)
	for (ll j = 0 ; j <= 1 ; ++j)
	for (ll k = 0 ; k <= 1 ; ++k)
	for (ll x = 0 ; x <= 9 ; ++x)
	for (ll y = 0 ; y <= 9 ; ++y)
	{
		if ((x + y + j) % 10 == a[i + 1])
			dp[i + 1][k][(x + y + j) / 10] += dp[i][j][k];
	}
  return dp[cnt][0][0] - f[cnt][0][0] - 2;
}
int main()
{
	cin >> t;
	while(t--)
	{
		cin >> n;
		cout << solve(n) << '\n';
	}
	return 0;
}
