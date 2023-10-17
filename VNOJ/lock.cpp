#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1000001 , MOD = 1e9 +7 , inf = 1e15;
const int c[11] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int n , m , dp[N] , trace[N] ;
vector<int> digit;
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
  cin >> n >> m;
  for (int i = 1 , x; i <= m ; i++) cin >> x , digit.pb(x);
  dp[0] = 0;
  for (int i = 1 ; i <= n ; i++)
  {
  	dp[i] = -1e9;
  	for (auto x : digit)
  	{
  		if (i == n && x == 0 && n != c[0]) continue;
  		if (c[x] <= i && dp[i] <= dp[i - c[x]] + 1) trace[i] = x , dp[i] = dp[i - c[x]] + 1;
	}
  }
//  x = dp[n];
  while (n)
  {
  	cout << trace[n];
  	n -= c[trace[n]];
  }
  return 0;
}

