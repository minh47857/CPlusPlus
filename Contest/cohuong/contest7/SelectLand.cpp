#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define lb  long double
#define pi pair<ll,ll>
const ll N = 1000001 , MOD = 1e9 +7 , inf = 1e15;
void file()
{
	freopen("SelectLand.inp" , "r" , stdin);
	freopen("SelectLand.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
int n;

namespace sub2
{
	lb dp[N][3]  ;
	int m , node , x[N] , y[N];
	pair<int , int> a[N];
	vector<int> polygon;
	lb calc(int x , int y , int z)
	{
		ll res = (a[y].fi - a[x].fi) * (a[z].se - a[x].se) - (a[z].fi - a[x].fi) * (a[y].se - a[x].se);
		cout << res << ' ';
		return res ;
	}
	
	void solve()
	{
		for(int i = 1 ; i <= n ; i++) cin >> a[i].fi >> a[i].se;
		for(int i = 1 ; i <= n - 3; i++) 
		{
			cin >> x[i] >> y[i]  ; 
			if(max(x[i] , y[i]) == max(x[i - 1] , y[i - 1])) node = max(x[i] , y[i]);
			if(min(x[i] , y[i]) == min(x[i - 1] , y[i - 1])) node = min(x[i] , y[i]);
		}
		for(int i = node + 1 ; i <= n ; i++) polygon.pb(i);
		for(int i = 1 ; i <= node - 1 ; i++) polygon.pb(i);
		m = polygon.size() - 1;
		for(int i = 1 ; i <= m ; i++)
		{
			cout << node  << ' ' <<  polygon[i - 1] << ' '  << polygon[i] << ' ' << calc(node , polygon[i - 1] , polygon[i]) << '\n';
			dp[i][0] = max(dp[i - 1][0] , dp[i - 1][1]);
			dp[i][1] = dp[i - 1][0] + calc(node , polygon[i - 1] , polygon[i]);
		}
		lb res = 10000000000;
		cout << res << '\n';
		cout << max(dp[m][0] , dp[m][1]);
	}
}

int main()
{
	file();
  cin >> n;
  sub2::solve();
}

