#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1000001 , MOD = 1e9 +7 , inf = 1e15;
ll n , l , r , k , f[3][105][10005] , ans = 0 , a[103] , d1[N] , d2[N] , p1 = 0 , p2 = 0;
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
   cin >> n >> l >> r >> k;
   for (int i = 1 ; i <= n ; i++) cin >> a[i];
   for (int i = 1 ; i < l ; i++) d1[++p1] = i;
   for (int i = r + 1 ; i <= n ; i++) d1[++p1] = i;
   for (int i = l ; i <= r ; i++) d2[++p2] = i ,  ans += a[i];
   
   for (int i = 0 ; i <= n ; i++)
   for (int j = 0 ; j <= k ; j++)
   f[0][i][j] = f[1][i][j] = inf;
   f[1][0][0] = ans;
    for(int i = 0 ; i <= n ; i++) f[0][i][0] = ans;
    for(int i = 1 ; i <= p1 ; i++)
        for (int j = 1 ; j <= p2 ; j++)
            for(int t = 1 ; t <= k ; t++)
            {
                f[i % 2][j][t] = min( f[1 - i % 2][j][t] , f[i % 2][j - 1][t] );
                ll val = t - abs(d1[i] - d2[j]);
                if( val >=0 && f[1 - i % 2][j - 1][val] != inf ) f[i % 2][j][t] = min( f[i % 2][j][t], f[1 - i % 2][j - 1][val] - (a[d2[j]] - a[d1[i]]) );
                ans = min(ans, f[i % 2][j][t]);
            }
  cout << ans;
  return 0;
}

