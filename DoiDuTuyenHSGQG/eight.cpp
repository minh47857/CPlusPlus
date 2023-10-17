#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const int N = 302 ;

int n , m , top[N][N][N] , bot[N][N][N] , dp[N][N][N] , ans = 0 , Row[N][N];
vector<int> s[N][N];
char a[N][N];

void sq_prepare()
{
	
	for(int i  = 1 ; i <= n ; i++)
	  for(int j = 1 ; j <= n ; j++)
	    top[0][i][j] = 1 , bot[n + 1][i][j] = n;
	
	
   for(int i = 1 ; i <= n ; i++)
    for(int c1 = 1 ; c1 <= n - 2 ; c1++)
      for(int c2 = c1 + 2 ; c2 <= n ; c2++)
        {
        	if(a[i][c1] == '*'|| a[i][c2] == '*') top[i][c1][c2] = i;
        	else 
			{
				int j = top[i - 1][c1][c2] ;
				if(Row[j][c2] - Row[j][c1 - 1] == 0) top[i][c1][c2] = j;
				else top[i][c1][c2] = i;
			}
		}
		
    for(int i = n ; i >= 1 ; i--)
      for(int c1 = 1 ; c1 <= n - 2 ; c1++)
      for(int c2 = c1 + 2 ; c2 <= n ; c2++)
        {
        	if(a[i][c1] == '*'|| a[i][c2] == '*') bot[i][c1][c2] = i;
        	else 
			{
				int j = bot[i + 1][c1][c2] ;
				if(Row[j][c2] - Row[j][c1 - 1] == 0) bot[i][c1][c2] = j;
				else bot[i][c1][c2] = i;
			}
		}
}

void solve()
{ 
    for(int i = 1 ; i <= n ; i++)
      for(int l = n - 2 ; l >= 1 ; l--)
        for(int r = l + 2 ; r <= n ; r++)
         {
             if(Row[i][r] - Row[i][l - 1] != 0) break;
               dp[i][l][r] = max({(r - l - 1) * max(0 , i - top[i][l][r] - 1) , dp[i][l + 1][r] , dp[i][l][r - 1]});
              // cout << i << ' ' << l << ' ' << r << ' ' << dp[i][l][r] << '\n';
         }
         
         
    for(int i = 1 ; i <= n ; i++)
      for(int l = 1 ; l <= n - 2 ; l++)
        for(int r = l + 2 ; r <= n ; r++)  
          {
              if(Row[i][r] - Row[i][l - 1] != 0) break;
              ans = max(ans , dp[i][l][r] * max(bot[i][l][r] - i - 1 , 0) * (r - l - 1));
          }
    if(ans == 0) cout << -1;
    else cout << ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  cin >> n ;
  for(int i = 1 ; i <= n ; i++)
    for(int j = 1 ; j <= n ; j++)
      {
         cin >> a[i][j] ;
         Row[i][j] = Row[i][j - 1] + (a[i][j] == '*');
      }
     
   sq_prepare();
   solve();
    return 0;
}

