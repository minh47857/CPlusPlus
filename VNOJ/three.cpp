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
ll n , a[N] , d[N];
void sieve()
{
	d[1] = 1;
	for (int i = 2 ; i <= sqrt(N) ; i++)
	if (!d[i]) for (int j = i * i ; j < N ; j += i ) d[j] = 1;
}
bool squarenum(ll x)
{
	ll m = sqrt(x);
	if (m * m == x) return true;
	return false;
}
int main()
{
	file();
	sieve();
  cin >> n ;
  for (int i = 1 ; i <= n ; i++) cin >> a[i];
  for (int i = 1 ; i <= n ; i++)
  	if (squarenum(a[i]) && !d[int(sqrt(a[i]))]) cout << 1 << '\n';
  	else cout << 0 << '\n';
  
}

