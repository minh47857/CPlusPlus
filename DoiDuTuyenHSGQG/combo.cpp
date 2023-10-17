#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 100001 , MOD = 1e9 +7 , inf = 1e15;
void file()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
 
 ll k , n , m , a[N] , cost[N][30] , f[N][30] , Min[N] , c[30][30] , ans = inf;
 string s;
 
int main()
{ 
    file();
    cin >> n >> m >> k >> s;
  	for (int i = 1 ; i <= m ; i++)
  	    for (int j = 1 ; j <= m ; j++)
  	        cin >> c[i][j];
  	     
  	for (int i = 0 ; i < n ; i++) a[i + 1] = s[i] -'a' + 1;
    for (int t = 1 ; t <= m ; t++)
  	    for (int i = 1 ; i <= m ; i++)
  	        for (int j = 1 ; j <= m ; j++)
  	        c[i][j] = min(c[i][t] + c[t][j] , c[i][j]);
  	      
  	for (int i = 1 ; i <= n ; i++) 
  	    for (int j = 1 ; j <= m ; j++)
  	        cost[i][j] = cost[i - 1][j] + c[a[i]][j] ;
  	     
  	for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            f[i][j] = inf , Min[i] = inf;
            
	for (int i = k  ; i <= n ; i++)
  	    for (int j = 1 ; j <= m ; j++)
  	     {
  	        f[i][j] = min(f[i - 1][j] + c[a[i]][j] , Min[i - k] + cost[i][j] - cost[i - k][j])	;
  	        Min[i] = min(f[i][j] , Min[i]); 
		 }
	
  	
  	for (int i = 1 ; i <= m ; i++) ans = min(ans , f[n][i]);
  	cout << ans ;
  	 return 0;
}

