#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 200 , MOD = 1e9 +7 , inf = 1e15 , M = 201;
void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
ll n , k , a[M] , base = N * N , dp[M][2 * M * M] , t;
void solve()
{
	cin >> n >> k;
	for (int i  = 1 ; i <= n ; i++) cin >> a[i] , a[i] -= k;
	for (int i = 1 ; i <= n ; i++)
	dp[0][base] = 1;
    for (int i = 1 ; i <= n ; i++)
    for (int j = - N * N ; j <= N * N ; j++)
    {
    	dp[i][j + base] = dp[i - 1][j + base];
    	if (j - a[i] >= - N * N) dp[i][j + base] = (dp[i - 1][j - a[i] + base] + dp[i][j + base]) % MOD;
	}
	cout << dp[n][base] - 1 << '\n';
}
int main()
{
	file();
	cin >> t;
  while (t--) solve();
  return 0;
}

