#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 101 , MOD = 1e9 +7 , inf = 1e15;
ll n , si[5] , a[101] , ans = inf , sum = 0;
void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
void gen(int t)
{
	for (int i = 1 ; i <= 3 ; i++)
	{
		si[i] += a[t];
		if (t == n )
		{
			 if (si[3] >= si[2] && si[2] >= si[1]) ans = min(ans , si[3] - si[1]);
		}
		else gen(t + 1);
		si[i] -= a[t];
	}
}
namespace sub4
{
	ll dp[N][1001][401] , res = inf;
	void solve()
	{
		dp[0][0][0] = 1;
		for (int i = 0 ; i <= n ; i++)
		{
			for (int j = 0 ; j <= 1000 ; j++)
			{
				for (int k = 0 ; k <= 400 ; k++)
				{
					if (!dp[i][j][k]) continue;
					dp[i + 1][j + a[i + 1]][k] = 1;
					dp[i + 1][j][k + a[i + 1]] = 1;
					dp[i + 1][j][k] = 1;
				}
			}
		}
		for (ll i = 0 ; i <= 1000 ; i++)
		for (ll j = 0 ; j <= 400 ; j++)
			if (dp[n][i][j] && i >= sum - i - j && sum - i - j >= j) res = min(i - j , res);
		cout << res;
	}
}
namespace sub3
{
	ll s[25] , f[(1 << 21)] , res = inf;
	int BIT(int x ,int k)
	{
		return (x >> k) & 1;
	}
	void solve()
	{
		for (int i = 0 ; i < (1 << n) ; i++)
		   for (int j = 0 ; j < n ; j++)
		   if (!BIT(i , j)) s[i | (1 << j)] = s[i] + a[j + 1];
		for (int i = 1 ; i < (1 << n) ; i++)
		{
			if (s[i] <= sum / 3) f[i] = s[i];
			else 
			{
				for (int j = 0 ; j < n ; j++)	if (BIT(i , j)) f[i] = max(f[i ^ (1 << j)] , f[i]);
			}
			if (s[i] - f[i] >= sum - s[i] && sum - s[i] >= f[i]) res = min(res , s[i] - f[i] - f[i]);
		}  
		cout << res; 
	}
	
}
int main()
{
	file();
 cin >> n ;
 for (int i = 1 ; i <= n ; i++) cin >> a[i] , sum += a[i];
 if (n <= 10)
 {
 	gen(1);
    cout << ans ;
 }
 if (n > 10 && n <= 20) sub3::solve();
 if (n > 20) sub4::solve();
 
 return 0;
}

