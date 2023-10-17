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
	freopen("CONSTRUCT.inp" , "r" , stdin);
	freopen("CONSTRUCT.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
ll n , a[N] , t , m;
void update(int l , int r , ll k)
{
	for(int i = l ; i <= r ; i++) a[i] += k;
}

ll get(int l , int r)
{
	ll ans = a[l];
	for(int i = l + 1 ; i <= r ; i++)
	{
		ans += a[i];
		if(a[i - 1] >= a[i]) ans -= a[i];
		else  ans -= a[i - 1];
	}
	return ans;
}

void solve()
{
	cin >>n >> m;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	while(m--)
	{
		ll l , r , k , type;
		cin >> type >> l >> r;
		if(type == 1) cin >> k  , update(l  , r , k);
		else cout << get(l , r) << '\n';	
	}
}
int main()
{
//	file();
	cin >> t ;
	while(t--) solve();

  
}

