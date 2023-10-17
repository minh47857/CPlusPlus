#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1000001 , MOD = 1e9 +7;
ll p[N] , n , m , c , t;
void file()
{
	freopen("marble.inp" , "r" , stdin);
	freopen("marble.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
ll sqr (ll x)
{
    return (x * x) % MOD;
}
ll poww(ll x, ll y)
{
    if(y == 0) return 1;
    if(y % 2 == 0) return sqr(poww(x , y / 2)) ;
    return (sqr(poww(x , y / 2)) * x) % MOD;
}
ll tinh(ll k , ll x)
{
	if (k > x) return 0;
    return ( p[x] * poww( (p[k] * p[x - k]) % MOD , MOD - 2) )  % MOD;
}
int main()
{
	file();
    cin >> t;
    p[0] = 1;
    for (ll i = 1 ; i < N ; i++) p[i] = (p[i - 1] * i) % MOD;
    while (t --)
    {
    	cin >> n >> m >> c;
    	if (n == m && c == 0 ) cout << 1 << '\n';
    	else cout << ( tinh( c , m + 1) * tinh(c - 1 , n - m - 1) ) % MOD << '\n';
	}
	return 0;
}

