#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 5e5 + 5 , MOD = 1e9 +7;
ll n , k , a[N] , dp[3][N];
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
   cin >> n >> k;
   for (int i = 1 ; i <= n ; i++) cin >> a[i] ;
   dp[0][0] = 1;
   dp[1][0] = 1;
   for (ll i = 1 ; i <= n ; i++)
   	for (int j = 1 ; j <= min(i , k) ; j++)	
   	    dp[i % 2][j] = (dp[1 - i % 2][j] + dp[1 - i % 2][j - 1] * a[i] ) % MOD;
	   cout << dp[n % 2][k];
	return 0;
}
