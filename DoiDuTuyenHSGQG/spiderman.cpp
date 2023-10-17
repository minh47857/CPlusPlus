#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1e6 + 5 , MOD = 1e9 +7 , inf = 1e15;
pi a[N] ;
ll n , k , sl[N] , res[N] , d[N]  , dem;
void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
int main()
{
	file();
  cin >> n >> k;
  for (int i = 1 ; i <= n ;  i++) cin >> a[i].fi , a[i].se = i;
  sort(a + 1 , a + n + 1 );
  for (int i = 1 ; i <= n ; i++)
  {
  	dem = 1;
  	while (a[i].fi == a[i + 1].fi) i++ , dem ++;
     if (a[i].fi > k) for (int j = a[i].fi ; j <= 1e6 ; j += a[i].fi) d[j] += dem;
  }
  for (int i = n ; i >= 1 ; i--)
  if (a[i].fi != a[i + 1].fi) sl[i] = n - i;
  else sl[i] = sl[i + 1];
 // cout << sl[1] << ' ';
  for (int i = 1 ; i <= n ;  i++)
  {
  	if (a[i].fi == a[i - 1].fi) res[a[i].se] = res[a[i - 1].se];
  	else
  	{
  		if (k > a[i].fi) continue;
  		if (k == a[i].fi)
  		{
  			res[a[i].se] = sl[i];
  			continue;
		}
		res[a[i].se] = d[a[i].fi - k];
		if (k == 0) res[a[i].se] --;
	}
  }
  for (int i = 1 ; i <= n ; i++) cout << res[i] << ' ';
  return 0;
  
}

