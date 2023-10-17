#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 20 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , a[N][N];
pi ans = {inf , inf} , start , End , d[N][N][N * N][5];
vector<int> row[5] , col[5];

struct chess {
	int x , y , cur , type;
};
queue<chess> Q;

bool check(int u , int v) {
	if(u < 1 || v < 1 || u > n || v > n) return false;
	return true;
}

void Bfs() {
	for(int i = 1 ; i <= n ; i++)
	 for(int j = 1 ; j <= n ; j++)
	  for(int k = 0 ; k <= n * n ; k++)
	   for(int l = 1 ; l <= 3 ; l++)
	    d[i][j][k][l] = {inf , inf};
	for(int i = 1 ; i <= 3 ; i++) Q.push({start.fi , start.se , 1 , i}) , d[start.fi][start.se][1][i] = {0 , 0};
	while(Q.size()) {
  	int u = Q.front().x , v = Q.front().y , c = Q.front().cur , t = Q.front().type ; 
  	pi w = d[u][v][c][t];
  	Q.pop();
  	  for(int i = 0 ; i < row[t].size() ; i++) {
  	    int	nxu = u + row[t][i] , nxv = v + col[t][i] , nxc = c;
  		if(!check(nxu , nxv)) continue;
  		if(a[nxu][nxv] == c + 1) nxc = c + 1;
  		if(d[nxu][nxv][nxc][t] > make_pair(w.fi + 1 , w.se)) 
		  d[nxu][nxv][nxc][t] = {w.fi + 1 , w.se} , Q.push({nxu , nxv , nxc , t});
	   }
	
     for(int nxt = 1 ; nxt <= 3 ; nxt++) 
      if(d[u][v][c][nxt] > make_pair(w.fi + 1 , w.se + 1)) 
	      d[u][v][c][nxt] =  make_pair(w.fi + 1 , w.se + 1), 
		  Q.push({u , v , c , nxt});
  }  
}

int main() {
	file();
  cin >> n;
 for(int i = 1 ; i <= n ; i++) 
   for(int j = 1 , u; j <= n ; j++) {
   	cin >> a[i][j] ;
   	if(a[i][j] == n * n) End = {i , j};
   	if(a[i][j] == 1) start = {i , j};
   } 
   
   row[1].pb(1) , row[1].pb(2) , row[1].pb(2) , row[1].pb(1) , row[1].pb(-1) , row[1].pb(-2) , row[1].pb(-2) , row[1].pb(-1);
   col[1].pb(2) , col[1].pb(1) , col[1].pb(-1) , col[1].pb(-2) , col[1].pb(-2) , col[1].pb(-1) , col[1].pb(1) , col[1].pb(2);
   
   for(int i = 1 ; i <= n ; i++) {
   	row[3].pb(i) , col[3].pb(i);
   	row[3].pb(i) , col[3].pb(-i);
   	row[3].pb(-i) , col[3].pb(-i);
   	row[3].pb(-i) , col[3].pb(i);
   	row[2].pb(i) , col[2].pb(0);
   	row[2].pb(-i) , col[2].pb(0);
   	row[2].pb(0) , col[2].pb(i);
   	row[2].pb(0) , col[2].pb(-i);
   }   
   Bfs();
   for(int i = 1 ; i <= 3 ; i++) {
   	pi tmp = d[End.fi][End.se][n * n][i];
   	if((tmp.fi == ans.fi && tmp.se < ans.se) || tmp.fi < ans.fi) ans = tmp;
   }
   cout << ans.fi << ' ' << ans.se ;
   return 0;
}

