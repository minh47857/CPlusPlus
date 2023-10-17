#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1e3 + 1 , MOD = 1e9 +7 , inf = 1e15 , M = 2e4 + 1;
void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
struct node
{
	ll  w , s , v;
} a[N];
 ll n , dp[N][M] , ans = -inf;
bool operator < (const node&x , const node&y)
{
	return x.w + x.s < y.w + y.s;
}

int main()
{
	file();
  cin >> n;
  for (int i = 1 ; i <= n ; i++) cin >> a[i].w >> a[i].s >> a[i].v;
  sort(a + 1 , a + n + 1);
  
  for (int i = 0 ; i < n ; i++)
   for (int j = 0 ; j <= 2e4 ; j++)
     dp[i][j] = -inf;
     
    dp[0][0] = 0;
  for (int i = 0 ; i < n ; i++)
  {
  	for (int j = 0 ; j <= 2e4 ; j++)
  	{
  	  if (a[i + 1].s >= j)	dp[i + 1][j + a[i + 1].w] = max(dp[i + 1][j + a[i + 1].w] , dp[i][j] + a[i + 1].v);
  	  dp[i + 1][j] = max(dp[i + 1][j] , dp[i][j]);
	}
  }
  for (int i = 1 ; i <= 2e4 ; i++) ans = max(dp[n][i] , ans);
  cout << ans;
  return 0;
}

