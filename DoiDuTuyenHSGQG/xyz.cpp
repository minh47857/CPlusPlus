#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 35 , MOD = 1e6;
ll n , l , f[N][N][N] , s[5][N] , p[5][N] , ans = 0 , nx[5][N][N];
char str1[N][N] , str2[N][N];
void file()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
int main()
{
	file();
  cin >> n >> l;
  for (int i = 0 ; i < 5 ; i++)
  for (int j = 1 ; j <= l ; j++) cin >> str1[i][j];
  
  for (int i = 0 ; i < 5 ; i++)
  for (int j = 1 ; j <= l ; j++) cin >> str2[i][j];
  
  for (int i = 1 ; i <= l; i++) 
  for (int j = 0 ; j < 5 ; j++)
  {
  	if (str1[j][i] == '#') s[1][i] += (1 << j);
  	if (str2[j][i] == '#') s[2][i] += (1 << j);
  }
	for (int t = 1 ; t <= 2 ; t++)
   {
  		p[t][1] = 0 ;
		ll k = 0;
  		for (int i = 2 ; i <= l ; i++)
  		{
  			while (k > 0 &&s[t][k + 1] != s[t][i]) k = p[t][k];
  			if (s[t][k + 1] == s[t][i]) k++;
  			p[t][i] = k;
	    }
	    nx[t][0][s[t][1]] = 1;
	for (int i = 1 ; i < l ; i++)
	  {
		for (int j = 0 ; j < 32 ; j++)
		{
			ll	k = i;
			while (k > 0 && s[t][k + 1] != j) k = p[t][k];
			if (s[t][k + 1] == j) k++;
			nx[t][i][j] = k ;
		}
	  }
	}
	for (int i = 0 ; i < 32 ; i++) nx[1][l][i] = nx[2][l][i] = l;
   f[0][0][0] = 1;
   for (int i = 0 ; i < n ; i++)
   	for (int j = 0 ; j <= l ; j++)
   		for (int k = 0 ; k <= l ; k++)
   			for (int b = 0 ; b < 32 ; b++)
   				f[i + 1][nx[1][j][b]][nx[2][k][b]] = (f[i + 1][nx[1][j][b]][nx[2][k][b]] + f[i][j][k]) % MOD;
	
	for (int i = 0 ; i < l ; i++) ans = (ans + f[n][l][i] + f[n][i][l]) % MOD;	
	cout << ans;
	return 0;
}
