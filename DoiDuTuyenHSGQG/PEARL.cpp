#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int,int>
const ll N = 1000001 , MOD = 1e9 +7 , inf = 1e15;
void file()
{
	freopen("PEARL.inp" , "r" , stdin);
	freopen("PEARL.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
 int  a[N] , n , m = 0 , st[N] , ed[N] ;
 pi b[N];
 vector<int> f;
void solve(int p)
{
	ll dem = 0 , ans = inf , hs = 0; 
	for (int i = 1 ; i <= n ; i++)
	{
		if (st[i] < hs * p + 1) dem++;
		if(i == hs * p + p)
		{
			ans = min(ans , dem);
			dem = 0;
			hs++;
		}
	}
	cout << p << ' ' << ans << '\n';
}
int main()
{
	file();
   cin >> n;
   for (int i = 1 ; i <= n ; i++) cin >> a[i] , b[i].fi = a[i] , b[i].se = i;
   for (int i = 1 ; i <= n ; i++) if (n % i == 0) f.pb(i);
   sort(b + 1 , b + n + 1);
   st[b[1].se] = 0 ;
   for (int i = 2 ; i <= n ; i++) 
   {
   	if (b[i].fi != b[i - 1].fi) st[b[i].se] = 0;
   	else st[b[i].se] = b[i - 1].se;
   }
   cout << f.size() << '\n';
   for (int i = 0 ; i < f.size() ; i++) solve(f[i]);
   return 0;
}

