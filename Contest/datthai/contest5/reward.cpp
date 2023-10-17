#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1000001 , MOD = 1e9 +7 , inf = 1e15;
void file()
{
	freopen("reward.inp" , "r" , stdin);
	freopen("reward.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
ll n , a[N] , dp[N][5];
int main()
{
	file();
  cin >> n;
  for (int i = 1 ; i <= n; i++) cin >> a[i];
  
  for (int i = 1 ; i <= n ; i++)
  {
  	dp[i][1] = dp[i - 1][0] + a[i];
  	dp[i][0] = max({dp[i - 1][1] , dp[i - 1][0] , dp[i - 1][2]});
  if (i >= 2)	dp[i][2] = dp[i - 1][1] + a[i];
  }
  cout << max({dp[n][0] , dp[n][1] , dp[n][2]});
}

