#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1000001 , MOD = 1e9 +7 , inf = 1e15 , 
      row[5] = {1 , 0 , 0 , -1} ,
      col[5] = {0 , -1 , 1 , 0} ;
void file()
{
	freopen("CLIMB.inp" , "r" , stdin);
	freopen("CLIMB.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
struct node
{
	int val , fi , se;
};

 bool operator < (const node&a , const node&b)
 {
 	return a.val < b.val;
 }
 
 int n , m , ans = 0;
 vector<node> num;
 
int main()
{
//	file();
  cin >> m >> n;
  int a[m + 5][n + 5] , dp[m + 5][n + 5];
  
  for(int i = 1 ; i <= m ; i++)
     for(int j = 1 ; j <= n ; j++)
       cin >> a[i][j] , num.pb({a[i][j] , i , j});
  sort(num.begin() , num.end());
  
  for(auto x : num)
  {
    int u = x.fi , v = x.se ;
  		dp[u][v] = 1;
	for(int i = 0 ; i < 4 ; i++)
	{
		int x = u + row[i];
		int y = v + col[i];
		if(x > m || y > n || x < 1 || y < 1 || a[x][y] >= a[u][v]) continue;
		dp[u][v] = max(dp[u][v] , dp[x][y] + 1);
	}
	ans = max(ans , dp[u][v]);
  }
  cout << ans;
  return 0;
}

