#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 11 , MOD = 1e9 +7;
ll dp[N][1 << N][1 << N] , cp[N][N][N] , n , a , b , c , w , f[5][N][N];
void file()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
int BIT(int x , int k)
{
	return (x >> k) & 1;
}
ll cost(int i , int j , int k)
{
	return a * f[1][i][j] + b * f[2][i][k] + c * f[3][j][k] + w * cp[i][j][k];
}
ll tinh (int x , int y , int z)
{
	if (x == 0) return 0;
	if (dp[x][y][z]) return dp[x][y][z];
	ll res = 0;
	for (int i = 1 ; i <= n ; i++) 
	{
	  if(!BIT(y , i)) continue ;
	  	
	     for (int j = 1 ; j <= n ; j++)  if (BIT(z , j)) res = max(res , tinh(x - 1 , y ^ (1 << i) , z ^ (1 << j)) + cost(x , i , j)) ; 
    }
    dp[x][y][z] = res;
    return res;
}
int main()
{
	file();
  cin >> n >> a >> b >> c >> w;
  for (int k = 1 ; k <= 3 ; k++)
  for (int i = 1 ; i <= n ; i++) 
  for (int j = 1 ; j <= n ; j++)
  cin >> f[k][i][j];
  
  for (int i = 1 ; i <= n ; i++)
  for (int j = 1 ; j <= n ; j++)
  for (int k = 1 ; k <= n ; k++)
  cin >> cp[i][j][k];
  
  cout << tinh (n , ((1 << n) - 1) * 2 , ((1 << n) - 1) * 2 );
  return 0;
}

