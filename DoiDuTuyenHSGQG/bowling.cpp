#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1000001 , MOD = 1e9 +7 , inf = 1e17;
void file()
{
//	freopen("bowling.inp" , "r" , stdin);
//	freopen("bowling.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

 int  t ;
 ll a[N] , f[N][3] , s[N] , ans , n , r;


void solve()
{
 cin >> n >> r;
 
 for (int i = 1 ; i <= n ; i++) cin >> a[i + r] ;
 for (int i = 1 ; i <= r ; i++) a[i] = a[n + r + i] = 0;
 for (int i = 1 ; i <= n + 2 * r ; i++) s[i] = s[i - 1] + a[i] ;
 for (int i = 0 ; i <= n + 2 * r ; i++)
     for (int j = 0 ; j <= 1 ; j++) f[i][j] = -inf;
 f[0][0] = 0;
 
 for (int i = 1 ; i <= 2 * r + n ; i++)
 {
 	f[i][0] = max(f[i - 1][0] , f[i - 1][1]);
 	f[i][1] = f[i - 1][1] + a[i];
 	if(i >= 2 * r + 1) f[i][1] = max(f[i][1] , f[i - 2 * r - 1][0] + s[i] - s[i - 2 * r - 1]);
 }
 
 ans = -inf;
 for (int i = 1 ; i <= n + 2 * r ; i++) ans = max(ans , f[i][1]);
 cout << ans << '\n';
 
}

int main()
{
	file();
  cin >> t;
  while(t--) solve();
  return 0;
}

