#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1000001 , MOD = 1e9 +7 , inf = 1e15 ,
   c[12] = {0 , 1 , 2 , 1 , 2 , 1 , 2 , 3 , 2 , 3};
void file()
{
	freopen("ODDCOIN.inp" , "r" , stdin);
	freopen("ODDCOIN.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll q , x , t;

ll calc(ll x)
{
	ll res = 0;
	for(int i = 1 ; i <= 5 ; i++)
	{
	int	y = x % 10;
		res += c[y];
		x /= 10;
	}
	res += (x * 2);
	return res;
}

void solve()
{
	cin >> x >> t;
	ll p = 0 , ans = inf;
	while(p <= t)
	{
		ans = min(ans , calc(t - p) + p / x);
	//	cout << t - p << ' ' << calc(t - p) << endl;
		p += x;
	}
	cout << ans << '\n';
//	cout << endl;
}

int main()
{
	file();
  cin >> q;
  while(q--) solve();
}

