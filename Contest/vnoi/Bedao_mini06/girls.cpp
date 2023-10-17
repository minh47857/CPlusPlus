#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1000005 , MOD = 1e9 +7 , inf = 1e15;
void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
ll n , m , k , a[N] , s[N], ans = -inf;
int main()
{
	file();
  cin >> m >> n >> k;
  for (int i = 1 ; i <= m ; i++) cin >> a[i];
  sort(a + 1 , a + m + 1 , greater<ll>());
  for (int i = 1 ; i <= m ; i++) s[i] = s[i - 1] + a[i];
  for (int i = 1 ; i <= m - n + 1 ; i++)
  {
  	if(a[i] - a[i + n - 1] <= k) ans = max(ans , s[i + n - 1] - s[i - 1]);
  }
  if (ans == -inf) cout << -2;
  else cout << ans;
  return 0;
}
