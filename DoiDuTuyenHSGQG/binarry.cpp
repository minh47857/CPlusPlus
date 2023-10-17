#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1000001 , MOD = 1e9;
ll dp[N] , n , k;
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
	dp[0] = 2 , dp[1] = 2;
   cin >> n >> k;
   for (int i = 2 ; i <= n ;i++)
   {
   	dp[i] =( dp[i - 1] * 2 ) % MOD;
   	if (i > k) dp[i] = (dp[i] -dp[i - k - 1] + MOD ) % MOD;
   	//	cout << dp[i] << endl;
   }
   cout << dp[n];
   return 0;
}

