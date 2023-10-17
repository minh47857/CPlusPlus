#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1001 , MOD = 1e9 +7;
ll m , n , a , b , c , d , s[N][N] , dp[N][N] , num[N][N] , Max = 0 ; 
pi minS[N][N] , pos1 , pos2;
void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
ll getS(int u , int v , int x , int y)
{
	return dp[u][v] - dp[u][y] - dp[x][v] + dp[x][y];
}
int main()
{
	file();
    cin >> m >> n >> a >> b >> c >> d; 
    a -= 2 , b -= 2;
    for (int i = 1 ; i <= n ; i++)
    {
    	for (int j = 1 ; j <= m ; j++)
    {
    	 cin >> s[i][j] ;
    	 dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1] + s[i][j];
	} 
	}
    
   for (int i = d + 1 ; i < n ; i++)
   {
   	deque <pi> dq;
   	for (int j = c + 1 ; j < m ; j++)
   	   {
   	    num[i][j] = getS(i , j , i - d  , j - c ) ;
   		while (dq.size() != 0 && num[i][j] <= num[dq.back().fi][dq.back().se]) dq.pop_back();
   		dq.push_back({i , j});
   		if (dq.front().se - c + 1 + a <= j) dq.pop_front();
   		if (j > a) minS[i][j] = {dq.front().fi , dq.front().se}  ;
	   }
   }
   
   for (int i = a + 1 ; i < m ; i++ )
   {
   	deque <pi> dq;
   	for (int j = d + 1 ; j < n ; j++)
   	   {
   		while (dq.size() != 0 && num[minS[j][i].fi][minS[j][i].se] <= num[minS[dq.back().fi][dq.back().se].fi][minS[dq.back().fi][dq.back().se].se]) dq.pop_back();
   		dq.push_back({j , i});
   		if (dq.front().fi + b - d + 1 <= j) dq.pop_front();
   		ll u = minS[dq.front().fi][dq.front().se].fi , v = minS[dq.front().fi][dq.front().se].se ;
   		if (j > b) 
   		   {
   			  ll area = getS(j + 1 , i + 1 , j - b - 1 , i - a - 1) - num[u][v];
   			  if(area > Max) 
				 {
				 	Max = area ;
				 	pos1 = make_pair (j - b  , i - a);
				 	pos2 = make_pair (u - d + 1 , v - c + 1);
				 }
		   }
	   }
   }
   cout << pos1.se << ' ' << pos1.fi << '\n';
   cout << pos2.se << ' ' << pos2.fi ;
   return 0 ;
}

