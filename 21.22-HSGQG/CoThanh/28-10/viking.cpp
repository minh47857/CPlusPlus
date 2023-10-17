#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 705 , MOD = 1e9 + 7 , inf = 1e9 + 7 , 
       row[] = {1 , -1 , 0 , 0} , 
       col[] = {0 , 0 , 1 , -1} ;

void file() {
	freopen("viking.in" , "r" , stdin);
	freopen("viking.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int t , m , n , a[N][N] , b[N][N] , U[N][N] , D[N][N] , L[N][N] , R[N][N];
pi PosB , PosT , PosA;
char s[N][N];

bool check1(int u , int v) {
	if(u < 1 || v < 1 || u > m || v > n || s[u][v] == 'I' || b[u][v] != inf) return false;
	return true;
}

void BfsB(int u , int v) {
   queue<pi> Q;
	for(int i = 1 ; i <= m ; i++)
	 for(int j = 1 ; j <= n ; j++)
	  b[i][j] = inf;
	  
	Q.push({u , v});
	b[u][v] = 0;
	while(Q.size()) {
	  int	x = Q.front().fi , y = Q.front().se;
	  Q.pop();
	  for(int i = 0 ; i < 4 ; i++) {
	  	int nx = x + row[i] , ny = y + col[i];
	  	if(!check1(nx , ny)) continue;
	  	b[nx][ny] = b[x][y] + 1;
	  	Q.push({nx , ny});
	  }
	}
	
	for(int i = 1 ; i <= m ; i++) {
		for(int j = 1 ; j <= n ; j++) 
	 	  if(s[i][j] == 'I')  L[i][j] = inf;
		    else  {
		    	if(j == 1) L[i][j] = b[i][j];
		    	else L[i][j] = min(L[i][j - 1] , b[i][j]);
			}
		for(int j = n ; j >= 1 ; j--) 
	 	  if(s[i][j] == 'I')  R[i][j] = inf;
		    else  {
		    	if(j == n) R[i][j] = b[i][j];
		    	else R[i][j] = min(R[i][j + 1] , b[i][j]);	  
			}  
	}
	
	for(int i = 1 ; i <= n ; i++) {
		for(int j = 1 ; j <= m ; j++) 
	 	  if(s[j][i] == 'I')  U[j][i] = inf;
		    else  {
		    	if(j == 1) U[j][i] = b[j][i];
		    	else U[j][i] = min(U[j - 1][i] , b[j][i]);
			}
		for(int j = m ; j >= 1 ; j--) 
	 	  if(s[j][i] == 'I')  D[j][i] = inf;
		    else {
		    	if(j == m) D[j][i] = b[j][i];
		    	else D[j][i] = min(D[j + 1][i] , b[j][i]);  
			}
	}
	
	  
}

bool check2(int u , int v , int Time) {
	if(u < 1 || v < 1 || u > m || v > n || s[u][v] == 'I' || a[u][v] != -1) return false;
	if(U[u][v] <= Time || D[u][v] <= Time || L[u][v] <= Time || R[u][v] <= Time) return false;
	return true;
}

void BfsA(int u , int v) {
	queue<pi> Q;
	memset(a , -1 , sizeof(a));
	a[u][v] = 0;
	Q.push({u , v});
	while(Q.size()) {
	  int	x = Q.front().fi , y = Q.front().se;
	  Q.pop();
	  for(int i = 0 ; i < 4 ; i++) {
	  	int nx = x + row[i] , ny = y + col[i];
	  	if(!check2(nx , ny , a[x][y] + 1)) continue;
	  	a[nx][ny] = a[x][y] + 1;
	  	Q.push({nx , ny});
	  }
	}
}

void solve() {
	cin >> m >> n;
	for(int i = 1 ; i <= m ; i++)
	 for(int j = 1 ; j <= n ; j++) {
	 	cin >> s[i][j];
	 	if(s[i][j] == 'Y') PosA = {i , j};
	 	if(s[i][j] == 'V') PosB = {i , j};
	 	if(s[i][j] == 'T') PosT = {i , j};
	 }  
	BfsB(PosB.fi , PosB.se);
	BfsA(PosA.fi , PosA.se);
	if(a[PosT.fi][PosT.se] != -1) cout << "YES" << '\n';
	else cout << "NO" << '\n';
}

int main() {
	file();
  cin >> t;
  while(t--) solve();
  return 0;
}

