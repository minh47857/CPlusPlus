#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1000001 , MOD = 2370823708;
ll m , n , k , c[10][10] , f[10] , res = 0;
void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
ll sqr(ll x)
{
	return (x * x) % MOD;
}
ll poww (ll a , ll b)
{
	if (b == 0) return 1 ;
	if (b % 2 == 0) return sqr(pow(a , b / 2)) % MOD;
	return ((sqr(pow(a , b / 2)) % MOD) * a) % MOD;
}
int main()
{
	file();
  cin >> m >> n >> k;
  c[0][0] = 1;
  for(int i = 1 ; i <= 7 ; i++)
  {
  	c[i][0] = 1;
  	for (int j = 1 ; j <= i ; j ++)
  	c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD ;// cout << i << ' ' << j << ' ' << c[i][j] << endl;
  }
  for (int i = 1 ; i <= 7 ; i++)
  {
  	f[i] = poww(i , n);
  	ll ans = 0;
  //	cout << f[i] << ' ';
  	for (int j = 1 ; j < i ; j++) ans = (ans + c[i][j] * f[j]) % MOD;
  //	cout << ans << ' ';
  	f[i] = (f[i] - ans + MOD) % MOD ;
  //	cout << f[i] << ' ';
  	if (i >= k) res = (res + c[7][k] * f[i]) % MOD;
  //	cout << res << endl;
  }
  cout << poww(res , m);
  return 0;
}

