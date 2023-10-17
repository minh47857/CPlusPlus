#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 1005 , M = 5e4 + 5 ,
          row[] = {1 , 0 , -1 , 0},
		  col[] = {0 , 1 , 0 , -1};

void file() {
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , m , q , a[N][N];
pi u[M] , v[M];

namespace sub1 {
	int d[1000005];
	void calc(int x , int y , int x1 , int y1) {
	    vector<int> H;
		int  res = 0;
		for(int i = x ; i <= x1 ; i++)
			for(int j = y ; j <= y1 ; j++)
				if(!d[a[i][j]]) res++ , d[a[i][j]] = 1 , H.pb(a[i][j]);
		for(auto x : H) d[x] = 0;
		cout << res << '\n';
	}
	
	void solve() {
		memset(d , 0 , sizeof(d));
		for(int i = 1 ; i <= q ; i++) 
			calc(u[i].fi , u[i].se , v[i].fi , v[i].se);
	}
}

namespace sub3 {
	int dp[N][N][25];
	bool calc(int x , int y , int u , int v , int k) {
		return dp[u][v][k] - dp[u][y - 1][k] - dp[x - 1][v][k] + dp[x - 1][y - 1][k];
	}
	
	void solve() {
		for(int i = 1 ; i <= n ; i++)
		for(int j = 1 ; j <= m ; j++) 
		for(int k = 1 ; k <= 20 ; k++)
		   dp[i][j][k] = dp[i - 1][j][k] + dp[i][j - 1][k] - dp[i - 1][j - 1][k] + (a[i][j] == k);
		
		for(int i = 1 ; i <= q ; i++) {
		    int res = 0;
			for(int k = 1 ; k <= 20 ; k++) res += (calc(u[i].fi , u[i].se , v[i].fi , v[i].se , k));
			cout << res << '\n';
		}
	}
}

namespace sub4 {
	int d[N][N] , dp[N][N];
	pi par[N][N];
	void Dfs(int x , int y) {
		for(int i = 0 ; i < 4 ; i++) {
		int	nx = x + row[i] , ny = y + col[i];
			if(nx < 1 || ny < 1 || nx > n || ny > m || a[x][y] != a[nx][ny] || par[nx][ny].fi) continue;
			par[nx][ny] = par[x][y];
			Dfs(nx , ny);
		}
	}
	
	int Get(int x , int y , int u , int v) {
		return dp[u][v] - dp[u][y - 1] - dp[x - 1][v] + dp[x - 1][y - 1];
	}
	
	void calc(int x1 , int y1 , int x2 , int y2) {
		vector<pi> Back;
		int res = Get(x1 , y1 , x2 , y2);
		for(int i = x1 ; i <= x2 ; i++) {
			pi p;
			p = par[i][y1];
			if((p.fi < x1 || p.fi > x2 || p.se < y1 || p.se > y2) && !d[p.fi][p.se]) res++ , d[p.fi][p.se] = 1 , Back.pb(p); 
			p = par[i][y2];
			if((p.fi < x1 || p.fi > x2 || p.se < y1 || p.se > y2) && !d[p.fi][p.se]) res++ , d[p.fi][p.se] = 1 , Back.pb(p); 
		}
		for(int i = y1 ; i <= y2 ; i++) {
			pi p;
			p = par[x1][i];
			if((p.fi < x1 || p.fi > x2 || p.se < y1 || p.se > y2) && !d[p.fi][p.se]) res++ , d[p.fi][p.se] = 1 , Back.pb(p); 
			p = par[x2][i];
			if((p.fi < x1 || p.fi > x2 || p.se < y1 || p.se > y2) && !d[p.fi][p.se]) res++ , d[p.fi][p.se] = 1 , Back.pb(p); 
		}
		cout << res << '\n';
		for(auto x : Back) d[x.fi][x.se] = 0;
	}
	
	void solve() {
		for(int i = 1 ; i <= n ; i++)
		 for(int j = 1 ; j <= m ; j++) {
		 	dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
		 	if(!par[i][j].fi) {
		  	   par[i][j] = {i , j} , Dfs(i , j);
		  	   dp[i][j]++;
		    }
		}
		for(int i = 1 ; i <= q ; i++)
		 calc(u[i].fi , u[i].se , v[i].fi , v[i].se);
	}
}

int main() {
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++) 
		for(int j = 1 ; j <= m ; j++)
			cin >> a[i][j];
	cin >> q;
	for(int i = 1 ; i <= q ; i++) cin >> u[i].fi >> u[i].se >> v[i].fi >> v[i].se;
	sub4::solve();
	return 0;
}

