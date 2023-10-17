#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 2005 , MOD = 1e9 +7;
string s ;
ll  dp[N][N] , n;
void file()
{
	freopen("sspalind.inp","r",stdin);
	freopen("sspalind.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
int main()
{
	file();
    cin >> s; 
    s = ' ' + s; 
    n = s.size() - 1;
    for (int i = 1 ; i <= n ; i ++) dp[i][i] = 1;
    for (int i  = 1 ; i <= n - 1 ; i++)
    {
    	for (int j = 1; j <= n - i ; j++)
    	{
    		int k = i + j;
    		if (s[j] == s[k]) dp[j][k] = dp[j + 1][k - 1] + 2 ;
    		else dp[j][k] = max(dp[j + 1][k] , dp[j][k - 1]);
		}
	}
  cout << dp[1][n];
}

