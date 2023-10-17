#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1000001 , MOD = 1e9 +7;
ll n , a[N][3] , dp[N][3] ;
void file()
{
	//freopen(".inp","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
int main()
{
	file();
  cin >> n ; 
  for (int i = 1; i <= n ; i++) cin >> a[i][1] ;
  for (int i = 1; i <= n ; i++) cin >> a[i][2] ;
  
  for (int i = 1; i <= n ; i++)
  {
  	dp[i][0] = max({dp[i - 1][1] , dp[i - 1][0] , dp[i - 1][2]});
  	dp[i][1] = max({dp[i - 1][2] , dp[i - 1][0]}) + a[i][1];
  	dp[i][2] = max({dp[i - 1][1] , dp[i - 1][0]}) + a[i][2];
  }
  cout << max({dp[n][1] , dp[n][0] , dp[n][2]});
}

