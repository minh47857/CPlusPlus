#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 405 , MOD = 1e9 +7 , inf = 1e15;
void file()
{
	freopen("RICEBALL.inp" , "r" , stdin);
	freopen("RICEBALL.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
ll n , a[N] , dp[N][N] , ans = 0;
int main()
{
	cin >> n;
	for(int i = 1 ; i <= n ; i++) cin >> a[i] , a[i] += a[i - 1] , dp[i][i] = 1;
	for (int i = n - 1 ; i >= 1 ; i--)
	
		for (int j = i + 1 ; j <= n ; j++)
		{
			int p2 = j;
			for (int p1 = i ; p1 < j ; p1++)
			{
				while(p1 + 1 < p2 && a[j] - a[p2 - 1] < a[p1] - a[i - 1]) p2--;
				if(a[j] - a[p2 - 1] == a[p1] - a[i - 1] && dp[i][p1] && dp[p2][j] && (p1 == p2 - 1 || dp[p1 + 1][p2 - 1]))
				    dp[i][j] = 1;
			}
		}
	for (int i = 1 ; i <= n ; i++)
	for (int j = i ; j <= n ; j++)
	if(dp[i][j]) ans = max(ans , a[j] - a[i - 1]);
	cout << ans;
	return 0;
}
