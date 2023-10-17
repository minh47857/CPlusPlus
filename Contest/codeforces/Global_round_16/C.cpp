#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1000001 , MOD = 1e9 +7 , inf = 1e15;
void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
int n , t , a[N][5] , dp[N];
string s[3];
int main()
{
	file();
  cin >> t;
  while(t--)
  {
  	cin >> n;
  	//cout << "?";
  	cin >> s[1];
  	cin >> s[2];
  	for(int j = 1 ; j <= 2 ; j++)
  	  for(int i = 1 ; i <= n ; i++)
  	     a[i][j] = s[j][i - 1] - '0';
  	dp[0] = 0;
  //	cout << "?";
  	for(int i = 1 ; i <= n ; i++)
  	{
  		if(a[i][1] - a[i][2] != 0)
  		{
  				dp[i] = dp[i - 1] + 2;
  				continue;
  		}
		  
  	  dp[i] = dp[i - 1] + (1 - a[i][1]);
  	  if(i >= 2 && a[i - 1][1] - a[i - 1][2] == 0 && a[i][1] != a[i - 1][1]) dp[i] = max(dp[i] , dp[i - 2] + 2);
	}
	cout << dp[n] << '\n';
  }
}

