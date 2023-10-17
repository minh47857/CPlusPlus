#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 5005 , MOD = 1e9 +7 , inf = 1e15;
void file()
{
	freopen("ToyNano.inp" , "r" , stdin);
	freopen("ToyNano.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
pi a[N];
ll n ;

bool operator <  ( pi x , pi y)
{
  return ( ( x.fi+x.se < y.fi+y.se ) || ( ( x.fi+x.se == y.fi+y.se ) && x.fi<y.fi ) );
}

bool cmp( pi x, pi y )
    {
        return ( ( x.fi+x.se < y.fi+y.se ) || ( ( x.fi+x.se == y.fi+y.se ) && x.fi<y.fi ) );
    }

namespace sub1
{
	ll ans = 0;
	ll s[15] , m[15];
	void gen(int t)
	{
		for(int i = 0 ; i <= 1 ; i++)
		{
			s[t] = s[t - 1];
			m[t] = m[t - 1];
			if(i == 1) 
			{
				if(a[t].fi < s[t - 1]) continue;
				s[t] += a[t].se;
				m[t] += 1;
			}
			if(t == n) ans = max(ans , m[t]);
			else gen(t + 1);
		}
	}
	
	void solve()
	{
		gen(1);
		cout << ans << '\n';
	}
}

namespace sub2
{
	ll dp[N][N];
	void solve()
	{
		for(int i = 0 ; i <= n ; i++)
		 for(int j = 1 ; j <= n ; j++)
		  dp[i][j] = inf;
		for(int i = 1 ; i <= n ; i++)
		{
			cout << a[i].fi << ' ';
			dp[i][0] = 0;
			for(int j = 1 ; j <= i ; j++)
			{
				dp[i][j] = dp[i - 1][j];
				if(a[i].fi >= dp[i - 1][j - 1])
				{
					dp[i][j] = min(dp[i - 1][j - 1] + a[i].se , dp[i][j]);
				}
			}
		}
		for(int i = n ; i >= 1 ; i--) 
		if(dp[n][i] != inf) 
		 {
			cout << i;
			return ;
		 }
	}
}
int main()
{
//	file();
  cin >> n;
  for(int i = 1 ; i <= n ; i++) cin >> a[i].fi >> a[i].se;
  sort(a + 1 , a + n + 1 );
 // sub1::solve();
  sub2::solve();
}

