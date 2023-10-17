#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ii pair<ll,ll>
#define fi first
#define se second
#define mp(a,b) make_pair(a,b)
#define pb push_back
const string FILE_NAME = "dweight";
const ll maxx = 305;
ll n , t;
ii a[maxx];
set<ii> st;
void solve()
{
	cin >> n;
	for (ll i = 1 ; i <= n ; ++i)
		cin >> a[i].fi >> a[i].se;
	for (ll i = 1 ; i <= n ; ++i)
	for (ll j = i + 1 ; j <= n ; ++j)
	{
		if (a[i].fi == a[j].fi) continue;
		ll x = (a[i].se - a[j].se) , y = (a[j].fi - a[i].fi);
		ll uc = __gcd(x , y);
		x /= uc;
		y /= uc;
		if ((x > 0 && y > 0) || (x < 0 && y < 0))
		{
				st.insert({x , y});
				cout<<x<<" "<<y<<" "<<st.size()endl;
		}
		
	}
	cout << st.size() + 1 << '\n';
	st.clear();
}
int main()
{
	cin >> t;
	while(t--)
		solve();
	return 0;	
}
