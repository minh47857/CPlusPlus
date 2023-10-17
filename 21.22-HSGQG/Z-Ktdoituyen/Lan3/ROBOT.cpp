#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define eps 1e-6
#define pi pair<int , int>

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

using namespace std;

void file() {
	freopen("ROBOT.inp" , "r" , stdin);
	freopen("ROBOT.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int n , m , p , k;
string str;

namespace sub3 {
	pi nextxy (int x , int y , char s) {
		if(s == 'D') return {x + 1 , y};
		if(s == 'U') return {x - 1 , y};
		if(s == 'L') return {x , y - 1};
		if(s == 'R') return {x , y + 1};
	}
	
	void solve() {
		int c[m + 5][n + 5] , dp[m + 5][n + 5][k + 5];
		memset(c , 0 , sizeof(c));
		for(int l = 0 ; l <= k ; l++)
			for(int i = 1 ; i <= m ; i++)
				for(int j = 1 ; j <= n ; j++)
					dp[i][j][l] = inf;
		for(int i = 1 ; i <= p ; i++) {
			int u , v ; cin >> u >> v;
			c[u][v] = 1;
		}
		dp[1][1][0] = 0;
		for(int l = 0 ; l < k ; l++) {
			for(int i = 1 ; i <= m ; i++)
				for(int j = 1 ; j <= n ; j++) {
					pi nx = nextxy(i , j , str[l + 1]);
					dp[i][j][l + 1] = min(dp[i][j][l + 1] , dp[i][j][l]);
					if(nx.fi >= 1 && nx.fi <= m && nx.se >= 1 && nx.se <= n && !c[nx.fi][nx.se]) 
						dp[nx.fi][nx.se][l + 1] = min(dp[nx.fi][nx.se][l + 1] , dp[i][j][l] + 1);
				}
		}
		cout << ((dp[m][n][k] == inf) ? -1 : (k - dp[m][n][k]));
	}
}

int main() {
	file();
	cin >> m >> n >> p >> k >> str;
	str = ' ' + str;
	sub3::solve();
	return 0;
}


