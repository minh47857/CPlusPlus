#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const int N = 8001 , MOD = 1e9 +7;
string s , st ;
int n , kmp[N][N] , dp[N];
int tinh(int x)
{
	int dem = 0;
	while (x != 0) 
	{
		x = x / 10 ;
	    dem ++ ;
	}
	return dem;
}

int main()
{
	cin >> s;
	n = s.size();
	s = ' ' + s ;
	dp[0] = 0;
   for (int i = n ; i >= 1 ; i--)
	{
		dp[i] = N ;
		st = s[i] + st ;
		int k , p[N];
		k = 0 , p[1] = 0 , kmp[i][i] = 0;
		string str = ' ' + st;
		for (int j = 2 ; j < str.size() ; j++)
		{
			while (str[k + 1] != str[j] && k > 0) k = p[k];
			if (str[k + 1] == str[j]) k++;
			p[j] = k;
			kmp[i][j + i - 1] = k;
		}
	}
	for (int i = 1 ; i <= n ; i++)
	{
		for (int j = 1 ; j <= i ; j++)
		{
			int len = i - j + 1;
		    int	l = len / (len - kmp[j][i]) ;
			if (len % (len - kmp[j][i]) == 0) dp[i] = min (dp[j - 1] + tinh (l) + len - kmp[j][i] , dp[i]);
			else dp[i] = min (dp[j - 1] + len + 1 , dp[i]);
		}
	}
	cout << dp[n];
	return 0;
}

