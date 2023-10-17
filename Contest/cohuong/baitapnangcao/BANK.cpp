#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 10005 , MOD = 1e9 +7 , inf = 1e15 , M = 1005;
void file()
{
	freopen("BANK.inp" , "r" , stdin);
	freopen("BANK.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
ll n , dp[N][M] , ans = 0 ;
pi a[N];
int main()
{
	file();
  cin >> n;
  for(int i = 1 ; i <= n ; i++) cin >> a[i].se >> a[i].fi;
  sort(a + 1 , a + n + 1);
  for(int i = 1 ; i <= n ; i++)
  {
  	for(int j = 0 ; j <= a[i].fi ; j++)
  	{
  	 dp[i][j] = max(dp[i - 1][j] , dp[i - 1][j - 1] + a[i].se);
	}
  }
  for(int i = 1 ; i <= a[n].fi ; i++) ans = max(ans , dp[n][i]);
  cout << ans;
  return 0;
}

