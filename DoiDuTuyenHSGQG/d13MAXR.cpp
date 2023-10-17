#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1001 , MOD = 1e9 +7;
ll n , a[N] , dp[N][N];
void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
ll solve(int l , int r)
{
	if (dp[l][r] != 0) return dp[l][r];
	if (l + 1 == r) return 0;
	ll Max = 0;
	for (int k = l + 1 ; k <= r - 1 ; k++) 	dp[l][r] = max(solve(l  , k ) + solve(k  , r) + a[l] * a[r] , dp[l][r]);
	return dp[l][r];
}
int main()
{
	file();
   cin >> n ;
   for (int i = 1 ; i <= n ; i++) cin >> a[i];
   cout << solve(1 , n);
   return 0;
}

