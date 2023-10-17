#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 4001 , MOD = 1e9 +7 , inf = 1e15;
ll n , d , a[N] , ans = 0 , dp[N][N];
void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
int main()
{
	file();
   cin >> n >> d;
   for (int i = 1 ; i <= 2 * n ; i++) cin >> a[i];
   for (int k = 2 ; k <= 2 * n ; k++)
   {
   	 for (int i = 1 ; i <= 2 * n - k + 1 ; i++)
   	 {
   	 	dp[i][i + k - 1] = max(dp[i + 1][i + k - 1] , dp[i][i + k - 2]);
   	 	if (abs(a[i] - a[i + k - 1]) <= d) dp[i][i + k - 1] = max(dp[i][i + k - 1] , dp[i + 1][i + k -2] + 1);
   	 	ans = max(ans , dp[i][i + k - 1]);
   	 	//cout << i << ' ' << i + k - 1 << ' ' << dp[i][i + k - 1] <<endl;
	 }
   }
   cout << ans;
   return 0;
}
