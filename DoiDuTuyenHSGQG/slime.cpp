#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 401 , MOD = 1e9 +7 , inf = 1e18;
ll n , f[N][N] , a[N] , s[N];
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
  cin >> n ;
  for (int i = 1 ; i <= n ; i++) cin >> a[i] , s[i] = s[i - 1] + a[i];
 for (int i = 1 ; i <= n ; i++ ) f[i][i] = 0;
 for (int i = n - 1 ; i >= 1 ; i--)
 for (int j = i + 1 ; j <= n ; j++)
 {
 	f[i][j] = inf;
 	for (int k = i ; k < j ; k++) f[i][j] = min(f[i][j] , f[i][k] + f[k + 1][j] + s[j] - s[i - 1]);
 }
 cout << f[1][n];
  return 0;
}

