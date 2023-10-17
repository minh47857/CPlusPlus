#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1000001 , MOD = 1e9 +7;
ll n , m , prsum[N] , sufsum[N] , f[N] , g[N] ;
pi a[N];
void file()
{
	freopen("TALENT.inp" , "r" , stdin);
	freopen("TALENT.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
int tknp(ll x)
{
	int d = 1 , c = n , kq = 0 , g ;
	while ( d <= c)
	{
		g = (d + c) / 2 ;
		if (a[g].fi <= x) kq = g , d = g + 1 ;
		else c = g - 1 ;
	}
	return kq;
}
int main()
{
	file();
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i++) cin >> a[i].fi;
    for (int i = 1 ; i <= n ; i++) cin >> a[i].se;
    sort (a + 1 , a + n + 1) ;
    for (int i = 1 ; i <= n ; i++) prsum[i] = prsum[i - 1] + a[i].fi * a[i].se , f[i] = f[i - 1] + a[i].se;
    for (int i = n ; i >= 1 ; i--) sufsum[i] = sufsum[i + 1] + a[i].fi * a[i].se , g[i] = g[i + 1] + a[i].se;
    for (int i = 1 ; i <= m ; i++)
    {
    	ll p ;
    	cin >> p;
    	int pos = tknp(p);
    	cout << p * f[pos] - prsum[pos] + sufsum[pos + 1] - p * g[pos + 1] << '\n';
	}
    return 0;
}

