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
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
  ll n , ip[N] , p , q;
  vector<ll> prime;
  
bool isprime(ll x)
{
	for (int i = 2 ; i <= sqrt(x) ; i++) if (x % i == 0) return false;
	return true;
}

void sieve()
{
	for (int i = 2 ; i <= sqrt(1e6) ; i++)
	if (!ip[i]) for (int j = i * i ; j < 1e6 ; j += i) ip[j] = 1;
	for (int i = 2 ; i <= 1e6 ; i++) if (!ip[i]) prime.pb(i);
}

 ll factor(ll a , ll b)
 {
 	ll res = 0;
 	while (a % b == 0) res++ , a /= b;
 	if (a == 1) return res;
 	return 0;
 }
 
int main()
{
	file();
  cin >> n;
  ll m = sqrt(n);
  if (m * m == n && isprime(m))
  {
  	cout << m << ' ' << 2 ;
  	return 0;
  }
  sieve();
  for (auto x : prime)
  {
  	if(x >= n) break;
  	q = factor(n , x);
  	if (q) 
  	{
  		p = x ;
  		break;
	}
  }
  if (p) cout << p << ' ' << q ;
  else cout << 0;
  return 0;
} 

