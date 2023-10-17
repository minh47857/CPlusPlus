#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 200005 , MOD = 1e9 +7 , inf = 1e15;
void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
 ll ans = -inf , n , a[N] , dp_l[N] , dp_r[N] , Min_l[N] , Min_r[N] , s ;
int main()
{
	file();
  cin >> n ;
  for (int i = 1 ; i <= n ; i++) cin >> a[i];
  for (int i = 0 ; i < 3 ; i++) Min_l[i] = Min_r[i] = inf;
  
  s = 0;
  Min_l[0] = 0 , dp_l[0] = -inf;
  for (int i = 1 ; i <= n ; i++)
  { 
    s += a[i];
    dp_l[i] = dp_l[i - 1];
  if (Min_l[i%3] != inf)	dp_l[i] = max(dp_l[i] , s - Min_l[i % 3]);
  	Min_l[i % 3] = min(Min_l[i % 3] , s);
  //	cout << i << ' ' << dp_l[i] << endl;
  }
  
  s = 0;
  Min_r[(n + 1) % 3] = 0 , dp_r[n + 1] = -inf;
  for (int i = n ; i >= 1 ; i--)
  {
  	s += a[i];
  	dp_r[i] = dp_r[i + 1];
  	if (Min_r[i%3] != inf) dp_r[i] = max(dp_r[i] , s - Min_r[i%3]);
  	Min_r[i % 3] = min(Min_r[i % 3] , s);
  }
  
  for (int i = 1 ; i < n ; i++) ans = max(ans , dp_l[i] + dp_r[i + 1]);
  cout << ans;
  return 0;
}

