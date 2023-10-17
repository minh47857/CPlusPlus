#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1001 , MOD = 1e9 +7 , inf = 1e15;
void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
ll n;
namespace sub1
{
	ll dp[N][N];
	void solve()
	{
		dp[0][0] = 1;
		for (int i = 0 ; i <= n ; i++)
		{
			for (int j = 1 ; j <= n ; j++)
			{
				dp[i][j] = dp[i][j - 1] ;
				if(j <= i) dp[i][j] = (dp[i][j] + dp[i - j][max(j - 2 , 0)]) % MOD;
				//cout << i << ' ' << j << ' ' << dp[i][j] << '\n';
			}
		}
		cout << dp[n][n];
	}
}

namespace sub2
{
	ll dp[100005][350] , ans = 0;
	void solve()
	{
		dp[0][0] = 1;
		for (int i = 1 ; i <= n ;i++)
		  for (int j = 1 ; j <= sqrt(i) ; j++)
		     dp[i][j] = (dp[i][j] + dp[i - j][j] + dp[i - 2* j + 1][j - 1]) % MOD;
		for (int i = 1 ; i <= sqrt(n) ; i++) ans = (ans + dp[n][i]) % MOD;
		cout << ans;
	}
}
int main()
{
  cin >> n;
sub2::solve();
}

