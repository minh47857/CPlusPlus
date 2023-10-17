#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 101 , MOD = 1e9 +7 , inf = 1e15;
ll n , p[N] , k[N] , f[N][100005] ;
pi a[N];
void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
ll solve(ll m , ll b)
{
	if (b == 0) return 0;
	if (m == 0) return 1 ;
	if (b <= 1e5 && f[m][b] != -1) return f[m][b];
	
	ll cnt = 0 , q = 1;
	for (int i = 0 ; i <= k[m] ; i++)
	{
		cnt += solve(m - 1 , b / q);
		q *= p[m];
		if (b < q) break;
	}
//	cout << m << ' ' << b << ' ' << cnt << '\n';
	if (b <= 1e5) f[m][b] = cnt;
	return cnt;
} 
int main()
{
   	file();
  cin >> n ;
  for (int i = 1 ; i <= n ; i++) cin >> a[i].fi >> a[i].se;
  sort(a + 1 , a + n + 1);
  for (int i = 1 ; i <= n ; i++) p[i] = a[i].fi , k[i] = a[i].se;
  int t = 3;
  memset(f , -1 , sizeof (f));
  while (t--)
  {
  	ll x , y;
  	cin >> x >> y;
  	cout << solve(n , y)  - solve(n , x - 1) << '\n';
  }
}

