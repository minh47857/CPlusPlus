#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 55;

void file() {
	freopen("pikachu.inp" , "r" , stdin);
	freopen("pikachu.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int m , n , k , row[N][N] , col[N][N] , ans = 0;
char a[N][N];

bool check(int u , int v , int x , int y , int t) {
	if(t == 1) {
		if(a[u][v] == '.' || a[u][v] != a[x][y]) return false;
	}
	else {
		if(a[u][v] != '.') return false;
	}
	
	if(x == u) {
		if(v > y) swap(v , y);
		if(row[u][y - 1] - row[u][v] == 0) return true;
	}
	if(v == y) {
		if(u > x) swap(u , x);
		if(col[v][x - 1] - col[v][u] == 0) return true;
	}
	return false;
}

int solve1() {
	int res = 0;
	for(int i = 1 ; i <= m ; i++)
	 for(int j = 1 ; j <= n ; j++)
	   for(int l = j + 1 ; l <= n ; l++)
	     	if(check(i , j , i , l , 1)) res++;
	for(int i = 1 ; i <= n ; i++)
	  for(int j = 1 ; j <= m ; j++)
	   for(int l = j + 1 ; l <= m ; l++)
	        if(check(j , i , l , i , 1)) res++;
	return res;
}

int solve2() {
	int res = 0;
	for(int i = 1 ; i <= m ; i++)
	  for(int j = 1 ; j <= n ; j++)
	   for(int u = i + 1 ; u <= m ; u++)
	    for(int v = 1 ; v <= n ; v++) {
	    	if(j == v || a[u][v] == '.' || a[u][v] != a[i][j]) continue;
	    	int x = i , y = v , xx = u , yy = j;
	    	if((check(x , y , i , j , 2) && check(x , y , u , v , 2)) || (check(xx , yy , i , j , 2) && check(xx , yy , u , v , 2) )) res++;
		}
    return res;
}

void solve3() {
	for(int i = 1 ; i <= m ; i++)
	  for(int j = 1 ; j <= n ; j++) {
	  	 for(int l = j - 1 ; l >= 1 ; l--) if(a[i][l] != '.') { L[i][j] = {i , l} ; break ;}
	  	 for(int l = j + 1 ; l <= n ; l++) if(a[i][l] != '.') { R[i][j] = {i , l} ; break ;}
	  	 for(int l = i - 1 ; l >= 1 ; l--) if(a[l][i] != '.') { T[i][j] = {i , l} ; break ;}
	  	 for(int l = i + 1 ; l <= n ; l++) if(a[l][i] != '.') { B[i][j] = {i , l} ; break ;}
	  }
	
	for(int i = 1 ; i <= m ; i++)
	 for(int j = 1 ; j <= n ; j++)
	
}

int main() {
	file();
  cin >> m >> n >> k;
  for(int i = 2 ; i <= m + 1; i++)
   for(int j = 2 ; j <= n + 1; j++) cin >> a[i][j];
  m += 2 , n += 2;
  for(int i = 1 ; i <= n ; i++) a[1][i] = a[m][i] = '.';
  for(int i = 1 ; i <= m ; i++) a[i][1] = a[i][n] = '.';
  for(int i = 1 ; i <= m ; i++)
    for(int j = 1 ; j <= n ; j++)
      row[i][j] = row[i][j - 1] + ((a[i][j] != '.') ? 1 : 0);
  for(int i = 1 ; i <= n ; i++)
    for(int j = 1 ; j <= m ; j++)
      col[i][j] = col[i][j - 1] + ((a[j][i] != '.') ? 1 : 0);  
  if(k >= 1) ans += solve1();
  if(k >= 2) ans += solve2();
  //if(k >= 3) ans += solve3();
  cout << ans;
  return 0;
}

