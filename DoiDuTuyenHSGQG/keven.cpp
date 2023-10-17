#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1000001 , MOD = 1e9 +7;
ll n , k , w[N][2] , dp[N][2] , a[N];
void file()
{
	freopen("keven.inp","r",stdin);
	freopen("keven.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
int main()
{
	file();
   cin >> n >> k; 
   for (int i = 1 ; i <= n ; i++) cin >> a[i];
   for (int i = 1 ; i <= k ; i++)
   for (int j = i ; j <= n ; j += k)
   {
   	if(a[j] % 2 == 0) w[i][1] ++;
   	else w[i][0] ++;
   }
   dp[1][0] = w[1][0];
   dp[1][1] = w[1][1];
   for (int i = 2 ; i <= k ; i++)
   {
   	 dp[i][0] = min (dp[i - 1][0] + w[i][0] , dp[i - 1][1] + w[i][1]);
   	 dp[i][1] = min (dp[i - 1][1] + w[i][0] , dp[i - 1][0] + w[i][1]);
   }
   cout << dp[k][0];
   return 0;
}

