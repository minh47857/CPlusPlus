#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 10000001 , MOD = 1e9 +7 , inf = 1e15;
ll d[N] , n , ans = 1 ;
void file()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
void sieve()
{
	d[2] = 0;
	for (ll i = 2 ; i <= sqrt(n) ; i++)
	if (d[i] == 0) for (ll j = i * i ; j <= n ; j += i) d[j] = 1;
}
ll calc(ll x , ll m)
{
	ll res = 0 , p = x;
	  while (p <= m)
	  {
	  	res += (m / p);
	  	p *= x;
	  }
	  return res;
}
ll sqr(ll x )
{
	return (x * x) % MOD;
}
ll Pow(ll a , ll b)
{
	if (b == 0) return 1;
	if (b % 2 == 0) return sqr(Pow(a , b / 2));
	return (sqr(Pow(a , b / 2)) * a) % MOD;
}
int main()
{
	file();
  cin >>  n;
  sieve();
  for (ll i = 2 ; i <= n ; i++)
  {
  	if (d[i] == 0) 
	  {
	  ll	 num = calc(i , n);
	//  cout << i << ' ' << num << '\n';
	  	 if (num % 2 == 1) num--;
	  	 ans = ( ans * Pow(i , num)) % MOD;
      }
  }
  cout << ans;
  return 0;
}

