#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 10000001 , MOD =  998244353 , inf = 1e15;
void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int t , minprime[N];

void sieve()
{
  for(int i = 2 ; i * i <= N ; i++)	
    if(minprime[i] == 0)
	  for(int j = i * i ; j < N ; j += i)
       if(minprime[j] == 0) minprime[j] = i;
  for(int i = 1 ; i < N ; i++)	if(minprime[i] == 0) minprime[i] = i;
}

int factorize(int x)
{
	int dem = 0 , ans = 1 , pre = 0;
	while(x != 1)
	{
	//	cout << x  << ' ' << pre << ' ' << minprime[x] << ' ' << dem << ' '<< "|";
		if(minprime[x] == pre && pre != 0) dem++;
		else ans *= (dem + 1) , dem = 1 , pre = minprime[x];
		x /= minprime[x];
	}	ans *= (dem + 1);
//	cout << ans << endl;
	return ans;
}

ll sqr(ll x)
{
	return (x * x) % MOD;
}

ll Pow(ll a , ll b)
{
	if(b == 0) return 1;
	if(b % 2 == 0) return sqr(Pow(a , b / 2));
	return (sqr(Pow(a , b / 2)) * a) % MOD;
}

void solve()
{
//	cout << "?";
	ll x;
	cin >> x;
	int fac = factorize(x);
	ll ans =  Pow(x , fac / 2 );
	if(fac % 2) ans = (ans * int(sqrt(x))) % MOD;
	cout << ans << '\n';
}

int main()
{
	file();
  sieve();
  cin >> t;
  while(t--) solve();
}

