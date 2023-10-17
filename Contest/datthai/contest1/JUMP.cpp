#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int,int>
const int N = 4002 , MOD = 1e9 +7 ;
void file()
{
	freopen("JUMP.inp" , "r" , stdin);
	freopen("JUMP.out" , "w" , stdout);
}
 int n , m , k , a[N] , b[N] , s , row[N][N] , col[N][N];
 int mod(int x , int y)
 {
 	int res = x + y;
 	if (res >= MOD) return res - MOD;
 	if(res > 0) return res ;
 	return res + MOD;
 }
int main()
{
	file();
  cin >> m >> n >> k;
  for (int i = 1 ; i <= m ; i++) cin >> a[i];
  for (int i = 1 ; i <= n ; i++) cin >> b[i];
  	row[1][1] = 1;
  	row[1][2] = -1;
  	for (int i = 1 ; i <= m ; i++)
  	for (int j = 1 ; j <= n ; j++)
  	{
  		row[j][i] =  mod(row[j][i - 1] , row[j][i] ) ;
  		col[i][j] =  mod(col[i][j] , col[i][j - 1] ) ;
  		s = mod(row[j][i] , col[i][j]) ;
  		int r = i + (a[i] + b[j]) % k + 2, l = j +  (a[i] + b[j]) % k + 2;
  		if (r <= m) row[j][r] = mod(row[j][r]  ,-s );
  		if (l <= n) col[i][l] = mod(col[i][l] ,-s);
  		col[i][j + 1]  = mod(col[i][j + 1] , s) ;
  	    row[j][i + 1] = mod(row[j][i + 1] , s) ; 
	}
  
 cout << s;
  return 0;
}

