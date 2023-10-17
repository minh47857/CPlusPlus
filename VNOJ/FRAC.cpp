#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 10000001 , MOD = 1e9 +7 , inf = 1e15;
ll n , a[101] , d[N] , e[N] ,s = 1;
vector<ll> v;
void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
void nt(ll x)
{
//	cout << x << endl;
	for (int i = 2 ; i <= sqrt(x) ; i++)
	{
		if (x % i != 0) continue;
		ll dem = 0;
		while (x % i == 0)
		{
			dem ++;
			x = x / i;
		}
		if (d[i] == 0 && e[i] == 0) v.pb(i);
		d[i] += dem;
		e[i] = max(e[i] , dem);
	}
	if (x == 1) return;
	if (d[x] == 0 && e[x] == 0) v.pb(x);
	d[x] ++;
	e[x] = max(e[x] , 1LL);
}
ll sqr(ll x)
{
	return x * x;
}
ll Pow(ll a , ll b)
{
	if (b == 0) return 1;
	if (b % 2 == 0) return sqr(pow(a , b / 2));
	return a * sqr(pow(a , b / 2));
}
int main()
{
	file();
  cin >> n ;
  if (n == 0)
  {
  	cout << "impossible";
  	return 0;
  }
  memset(d , 0 , sizeof (d));
  memset(e , 0 , sizeof (e));
  for (int i = 1 ; i <= n ; i++) cin >> a[i] ;
  for (int i = 1 ; i <= n ; i++) 
  {
  	nt(a[i]);
  	if (a[i] == 0) 
  	{
  		cout << "impossible";
  	return 0;
	  }
  }
  for (auto x : v) s = s * Pow(x , d[x] - e[x] ) ;
  cout << s;
  return 0;
}

