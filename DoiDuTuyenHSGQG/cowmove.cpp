#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 200005 , MOD = 1e9 + 7 , inf = 1e15 , M = 3005;

void file()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

 ll n , t , k , m , f[M] , factor[N] , inv[N];
 pi a[M];
 
ll sqr(ll x)
{
	return (x * x) % MOD;
}

ll Pow(ll a , ll b)
{
	if (b == 0) return 1;
	if(b % 2 == 0) return sqr(Pow(a , b / 2));
	return (a * sqr(Pow(a , b / 2))) % MOD;
}

ll c (int y, int x)
{
	if (y == 0 || x == y) return 1;
	return ( (factor[x] * inv[x - y] ) % MOD * inv[y]) % MOD;
}

ll w (int x , int y , int u , int v)
{
	int p1 = u - x + 1 , p2 = v - y + 1;
	return c(p1 - 1 , p1 + p2 - 2);
}

void solve()
{
	cin >> n >> m >> k;
	for (int i = 1 ; i <= k ; i++) cin >> a[i].fi >> a[i].se;
	sort(a + 1 , a + k + 1);
	a[k + 1] = {n , m};
	for (int i = 1 ; i <= k + 1 ; i++)
	{
		f[i] = w(1 , 1 , a[i].fi , a[i].se);
		ll tmp = 0;
		for (int j = 1 ; j < i ; j++)
		{
			if (a[j].se > a[i].se ) continue;
			tmp = (tmp + f[j] * w(a[j].fi , a[j].se , a[i].fi , a[i].se)) % MOD;
		}
		f[i] = (f[i] - tmp + MOD) % MOD;
	}
	cout << f[k + 1] << '\n';
}
int main()
{
	file();
	factor[0] = 1;
	for (int i = 1 ; i <= 2e5 ; i++) factor[i] = (factor[i - 1] * i) % MOD;
	inv[N - 5] = Pow(factor[N - 5] , MOD - 2);
	cout << c(0 , 2) << '\n';
	for (int i = 2e5 - 1 ; i >= 1 ; i--) inv[i] = (inv[i + 1] * (i + 1)) % MOD;
    solve();
	return 0;
}

