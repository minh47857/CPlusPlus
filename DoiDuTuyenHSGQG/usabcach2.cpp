#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 101 , MOD = 1e9 +7 , inf = 1e15;
ll ans , r , n , k[N] , p[N] , f[N][1e5 + 5];
pi a[N];
void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
void dq(int id , int s)
{
	
	if (id > n) 
	{
		if (s <= r) ans++;
		return;
	}
	if (p[id] * s > r)
	{
		if (s <= r) ans++;
		return;
	}
	ll Pow = 1;
	for(ll i = 0 ; i <= k[id] ; i++)
	{
		if (s * Pow > r) break;
		dq(id + 1 , s * Pow);
		Pow *= p[id];
	}
}

ll solve(ll x)
{
	ans = 0 , r = x;
	dq(1 , 1);
	return ans;
}
int main()
{
	file();
  cin >> n ;
  for (int i = 1 ; i <= n ; i++) cin >> a[i].fi >> a[i].se;
  sort(a + 1 , a + n + 1);
  for (int i = 1 ; i <= n ; i++) p[i] = a[i].fi , k[i] = a[i].se;
  int t = 3;
  while (t--)
  {
  	ll x , y;
  	cin >> x >> y;
  	cout << solve(y) - solve(x - 1) << '\n';
  }
}


