#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 5005 , MOD = 1e9 +7 , inf = 1e15;
void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
ll n , c[N] , dp[N][N] , ans = inf , d[N];
int main()
{
 cin >> n;
 for(int i = 1 ; i <= n ; i++) cin >> c[i];
 
 for(int i = 1 ; i <= n ; i++)
 for(int j = i ; j >= 1 ; j--)
  if(c[i] == c[j]) d[i] = j;
  else break;
  
 for(int i = 1 ; i <= n ; i++)
 {
 	for(int j = 1 ; j <= 5000 ; j++) 
	 {
	   dp[i][j] = min(dp[d[i] - 1][j] + (c[i] != j) , dp[max(d[d[i]] - 1] - 1][[	]);
     }
 }
 for(int i = 1 ; i <= 5000 ; i++) ans = min(dp[n][i] , ans);
 cout << ans;
}

