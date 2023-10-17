#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1000001 , MOD = 1e9 +7 , inf = 1e15;
ll n , s , d , q , a[N];
void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
void solve()
{
	s = 0;
	cin >> n >> d;
  	for (int i = 1 ; i <= n ; i++) cin >> a[i] , s += a[i];
  	if (s <= (n + 1) / 2 * d) cout << "YES" << '\n';
  	else cout << "NO" << '\n';
}
int main()
{
	file();
  cin >> q;
  while (q--) solve();
}

