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
ll n , k , a[N] , f[N][N][200];
int main()
{
	file();
  cin >> n >> k;
  for (int i = 1 ; i <= n ; i++) cin >> a[i];
  for (int i = n - 1 ; i >= 1 ; i--)
  	for (int j = i + 1 ; j <= n ; j++)
  	{
  		for (int t = 1 ; t <= k ; t++)
  		{
  			f[i][j][t] = max({f[i + 1][j - 1][t - 1] + abs(a[i] - a[j]) , f[i + 2][j][t - 1] + abs(a[i] - a[i + 1]) , f[i][j - 2][t - 1] + abs(a[j] - a[j - 1]) , f[i + 1][j][t] , f[i][j - 1][t]});
	//	cout << i << ' ' << j << ' ' << k << ' ' << f[i][j][t] << '\n';
		}
    }
  		 cout << f[1][n][k];
  		 return 0;
}

