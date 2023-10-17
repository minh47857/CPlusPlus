#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<ll,ll>
#define fi first
#define se second
#define pb push_back
const ll N = 1000005 , MOD = 1e9 + 7 , inf = 1e15;
ll n , s[N] , a[N] , f[N] , t;
void file()
{
	freopen("MERGESORT.inp" , "r" , stdin);
    freopen("MERGESORT.out" , "r" , stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
void solve()
{
	ll res , ans;
	memset(f , 0 , sizeof(f));
	cin >> n ; 
	s[0] = 0;
	for (int i = 1 ; i <= n ; i++) cin >> a[i] , s[i] = s[i - 1] + a[i];
	f[1] = 1;
	for (ll i = 1 ; i <= n ; i++)
	{
		ll d = i + 1 , c = n , g , kq = -1;
		f[i] = max(f[i] , f[i - 1]);
		if (i == n) break;
		
		while(d <= c)
		{
			g = (d + c) / 2;
			if (s[i] - s[f[i] - 1] <= s[g] - s[i]) c = g - 1 , kq = g;
			else d = g + 1;
		}
		if (kq == -1) continue;
		f[kq] = max(f[kq] , i + 1);
	}
	res = n;
	ans = 0;
	while(res != 0 && res != -1)
	{
		ans += (res - f[res]);
		res = f[res] - 1;
	}
	cout << ans << '\n';
}
int main()
{
  cin >> t;
  while(t --)  solve();
}
