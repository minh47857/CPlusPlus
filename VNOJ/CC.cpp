#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1000001 , MOD = 1e9 +7;
void file()
{
	freopen("CC.inp" , "r" , stdin);
	freopen("CC.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
ll a[N] , n , k;
void k1()
{
	double ans = 0 ;
	sort (a + 1 , a + n + 1);
	ll x = a[n / 2 + 1];
	for (int i = 1 ; i <= n ; i++) ans += abs(a[i] - x);
	cout << fixed << setprecision(2) << ans;
}
void k2()
{
    double ans = 0 , x;
	ll res = 0;
	for (int i = 1 ; i <= n ; i++) res += a[i];
	x = res * 1.0 / n ;
	for (int i = 1 ; i <= n ; i++) ans = ans + (a[i] - x)*(a[i] - x)*1.0;
    cout << fixed << setprecision(2) << ans;
}
int main()
{
	file();
  cin >> n >> k;
  for (int i = 1 ; i <= n ; i++) cin >> a[i];
  if (k == 1) k1();
  else k2();
}

