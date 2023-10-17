#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1000001 , MOD = 1e9 +7 , inf = 1e15;
void file()
{
	freopen("sumdiv.inp" , "r" , stdin);
	freopen("sumdiv.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
 
ll a, b;
 
namespace subfull
{
	
	ll ans = 0 , f[N];
	ll calc(ll l , ll r)
	{
		if(l > r) return 0;
		return (l + r) * (r - l + 1) / 2;
	}
	
	void solve()
	{
		ll pre = inf;
		for (int i = 1 ; i <=sqrt (b); i++)
		{
		 ll	l = (a + i - 1) / i , r = b / i;
		 if(l <= r) f[i] = 1;
		 r = min(r , pre - 1);
	   	 pre = l;
     	 ans += calc(l , r);
		}
		for (int i = 1 ; i < pre ; i++) if(f[i]) ans += i;
		cout << ans << ' ';
	}
}
 
 
int main()
{
	file();
	cin >> a >> b;
	  	subfull::solve();
  return 0;
}
