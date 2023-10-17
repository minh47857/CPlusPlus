#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 305 , MOD = 1e9 +7 , inf = 1e15;
void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

bool cmp (const pi&a , const pi&b)
{
	if(a.fi < b.fi) return true;
	if(a.fi == b.fi && a.se > b.se) return true;
	return false;
}

ll ans = 0 , n , m , t , d[N];
pi a[N];

void solve()
{
	cin >> n >> m;
	ans = 0;
	for(int i = 1 ; i <= m ; i++) cin >> a[i].fi , a[i].se = i , d[i] = 0;
	sort(a + 1 , a + m + 1 , cmp);
	for(int i = 1 ; i <= m ; i++)
	{
	//	cout << a[i].fi << ' ' << a[i].se << "|";
		for(int j = 1 ; j <= a[i].se ; j++) ans += d[j];
		d[a[i].se]++;
	}
	cout << ans << '\n';
}
int main()
{
	file();
  cin >> t;
  while(t--) solve();
}

