#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1001 , MOD = 1e9 +7 , inf = 1e16;
ll n , m , f[N][N] , ans = 0 , a[N][N];
void file()
{
	freopen("WMT.inp" , "r" , stdin);
	freopen("WMT.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
pi tknp( ll u[] , ll v[])
{
	int d = 1, c = m , g , kq = -1 ;
	while (d <= c)
	{
		ll p1 = (d + c) / 2 ;
		ll p2 = m - p1;
		if (v[p2] > u[p1 + 1]) d = p1 + 1;
	   else{
	          if (v[p2 + 1] < u[p1]) c = p1 - 1;
	          else return { p1 , p2 };
	       } 
	}
}
int main()
{
	file();
    cin >> n >> m;
	for (int i = 1 ; i <= n ; i++)
	{
		for (int j = 1 ; j <= m ; j++)	cin >> a[i][j];
		sort(a[i] + 1 , a[i] + m + 1);
	 } 
   for (int i = 1 ; i <= n ; i++)
   	for (int j = 1 ; j <= m ; j++)
   	  f[i][j] = f[i][j - 1] + a[i][j];
	
   for (int i = 1 ; i < n ; i++)
   {
   	for (int j = i + 1 ; j <= n ; j++)
   	   {
   	   	 pi id = tknp(a[i] , a[j]);
   	   	ans = ans  - 2 * f[i][id.fi] - 2 * f[j][id.se] + f[j][m] + f[i][m];
   	   }
   }   
   cout << ans;
   return 0;
}
