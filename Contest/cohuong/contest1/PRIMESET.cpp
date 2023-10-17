#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 205 , MOD = 1e9 +7 , inf = 1e15 , M = 1 << 16;
void file()
{
	freopen("PRIMESET.inp" , "r" , stdin);
	freopen("PRIMESET.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
 int n , m , a[N] , b[N] , dp[N][M] , t[N];
 
Bit(int x , int k)
{
	return (x >> k) & 1;
}

int solve(int x , int y)
{
	int ans = 0;
	for (int i = 0 ; i < m ; i++) if (Bit(y , i) && !Bit(x , i)) ans += (1 << i);
	return ans;
}

int main()
{
	//file();
  cin >> n ;
  for (int i = 1 ; i <= n ; i++) cin >> a[i];
  cin >> m;
  for (int i = 1 ; i <= m ; i++) cin >> b[i];

  for (int i = 1 ; i <= n ; i++)
    for (int j = 1 ; j <= m ; j++)
  	  if (a[i] % b[j] == 0) t[i] += (1 << (j - 1)) ;
  dp[0][0] = 1;
  for (int i = 1 ; i <= n ; i++)
  	for (int j = 0 ; j < (1 << m) ; j++)
  	{
  		int neww = solve(t[i] , j);
	  dp[i][j] = (dp[i - 1][j] + dp[i - 1][neww] ) % MOD;	
	}
  
  cout << dp[n][(1 << m) - 1];
  return 0;
}

