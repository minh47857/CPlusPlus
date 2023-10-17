#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>
#define mp make_pair
const int N = 1e3 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("banbi.inp" , "r" , stdin);
	freopen("banbi.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int ans = 0 , res , n , m , f[5][5] , d[N][N][5] , s[N][N] , P , K;
pi nx[5];
char x;

bool check(int u , int v) {
	if(u < 1 || v < 1 || u > m || v > n) return false;
	return true;
}

int Dfs(int u , int v , int t) {
	if(d[u][v][t] != -1) return d[u][v][t];
	d[u][v][t] = 0;
	int nu = u + nx[t].fi , nv = v + nx[t].se;
	if(check(nu , nv)) d[u][v][t] = Dfs(nu , nv , f[t][s[nu][nv]]) + 1;
	else d[u][v][t] = 1;
	return d[u][v][t];
}

int main() {
	file();
  cin >> m >> n;
  for(int i = 1 ; i <= m ; i++)
   for(int j = 1 ; j <= n ; j++)
    cin >> x , s[i][j] = x - '0';
    f[1][0] = 1 , f[1][1] = 3 , f[1][2] = 4; nx[1] = mp(0 , 1);
    f[2][0] = 2 , f[2][1] = 4 , f[2][2] = 3; nx[2] = mp(0 , -1);
    f[3][0] = 3 , f[3][1] = 2 , f[3][2] = 1; nx[3] = mp(1 , 0);
    f[4][0] = 4 , f[4][1] = 1 , f[4][2] = 2; nx[4] = mp(-1 , 0);
    memset(d , -1 , sizeof(d));
    
  for(int i = 1 ; i <= m ; i++) {
  	res = Dfs(i , 0 , 1);
  	if(res > ans) ans = res , P = 1 , K = i; 
  }
  
  for(int i = 1 ; i <= m ; i++) {
  	res = Dfs(i , n + 1 , 2);
  	if(res > ans) ans = res , P = 2 , K = i; 
  }
  
  for(int i = 1 ; i <= n ; i++) {
  	res = Dfs(0 , i , 3);
  	if(res > ans) ans = res , P = 3 , K = i; 
  }
  
  for(int i = 1 ; i <= n ; i++) {
  	res = Dfs(m + 1 , i , 4);
  	if(res > ans) ans = res , P = 4 , K = i; 
  }
  
  cout << P << ' ' << K << '\n';
  return 0;
}

