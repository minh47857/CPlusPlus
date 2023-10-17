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
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
pi a[N];
int n ;

bool operator < (const pi&x , const pi&y)
{
	return x.fi + x.se < y.fi + y.se;
}

namespace sub1
{
	int ans = 0;
	ll s[15] , m[15];
	void gen(int t)
	{
		for(int i = 0 ; i <= 1 ; i++)
		{
			s[i] = s[i - 1];
			m[i] = m[i - 1];
			if(t == 1) 
			{
				if(h[i] < s[i - 1]) continue;
				s[i] += p[i];
				m[i] +=  1;
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

int main()
{
  cin >> n;
  for(int i = 1 ; i <= n ; i++) cin >> a[i].fi >> a[i].se;
  sort(a + 1 , a + n + 1);
  if(n <= 10) sub1::solve();
}

