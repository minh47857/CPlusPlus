#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ii pair<ll,ll>
#define fi first
#define se second
#define mp(a,b) make_pair(a,b)
#define pb push_back
const string FILE_NAME = "";
const ll maxx = 1e6 + 5;
const ll INF = 1e15;
ll n , st[4 * maxx] , mx = -INF , ans = -INF;
ii a[maxx];
bool compare(ii a , ii b)
{
	return (a.fi < b.fi) || (a.fi == b.fi && a.se > b.se);
}
void update(ll id , ll l , ll r , ll i , ll v)
{
	if (i < l || i > r) return;
	if (l == r)
	{
		st[id] = v;
		return;
	}
	ll mid = (l + r) / 2;
	update(2 * id , l , mid , i , v);
	update(2 * id + 1 , mid + 1 , r , i , v);
	st[id] = max(st[2 * id] , st[2 * id + 1]);
}
ll get(ll id , ll l , ll r , ll x)
{
	if (r < x) return 0;
	if (l >= x)
		return st[id] + 1;
	ll mid = (l + r) / 2;		
	return max(get(2 * id , l , mid , x) , get(2 * id + 1 , mid + 1 , r , x));
}
int main()
{
//	file();
	cin >> n;
	for (ll i = 1 ; i <= n ; ++i)
	{
		cin >> a[i].fi >> a[i].se;
		mx = max(mx , a[i].se);
	}
	sort(a + 1 , a + n + 1 , compare);
	for (ll i = 1 ; i <= n ; ++i)
	{
		ll res = get(1 , 1 , mx , a[i].se);
		ans = max(ans , res);
		update(1 , 1 , mx , a[i].se , res);
	}
	cout << ans;
	return 0;
}
