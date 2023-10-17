#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define eps 1e-6
#define pi pair<int , int>

const int N = 205 , MOD = 1e9 + 7 , inf = 1e9 + 7;

using namespace std;

void file() {
	freopen("CNT.inp" , "r" , stdin);
	freopen("CNT.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

struct node {
	int u , sum , t;
} ;

int n , k , dp[N][N][5];
vector<int> G[N] , ans;
vector<node> s[N][N][5];

void Dfs(int u , int pa) {
	for(int v : G[u]) {
		if(pa == v) continue;
		Dfs(v , u);
	}
	dp[u][0][0] = 0 , dp[u][1][1] = 0;
	for(int v : G[u]) {
		if(pa == v) continue;
		for(int i = k ; i >= 1 ; i--)
			for(int j = 1 ; j <= i ; j++) {
			    //dp[u][i][0] = min(dp[u][i][0] , min(dp[v][j][0] , dp[v][j][1]) + dp[u][i - j][0]);
				if(dp[v][j][0] <= dp[v][j][1] && dp[v][j][0] + dp[u][i - j][0] < dp[u][i][0]) { 
					s[u][i][0] = s[u][i - j][0];
					s[u][i][0].pb({v , j , 0});
					dp[u][i][0] = dp[v][j][0] + dp[u][i - j][0];
				}
				else if(dp[v][j][0] > dp[v][j][1] && dp[v][j][1] + dp[u][i - j][0] < dp[u][i][0]) {
					s[u][i][0] = s[u][i - j][0];
					s[u][i][0].pb({v , j , 1});
					dp[u][i][0] = dp[v][j][1] + dp[u][i - j][0];
				}
				//dp[u][i][1] = min(dp[u][i][1] , min(dp[v][j][0] , dp[v][j][1] + 1) + dp[u][i - j][1]);
				if(dp[v][j][0] <= dp[v][j][1] + 1 && dp[v][j][0] + dp[u][i - j][1] < dp[u][i][1]) {
					s[u][i][1] = s[u][i - j][1];
					s[u][i][1].pb({v , j , 0});
					dp[u][i][1] = dp[v][j][0] + dp[u][i - j][1];
				}
				else if(dp[v][j][0] > dp[v][j][1] + 1 && dp[v][j][1] + 1 + dp[u][i - j][1] < dp[u][i][1]) {
					s[u][i][1] = s[u][i - j][1];
					s[u][i][1].pb({v , j , 1});
					dp[u][i][1] = dp[v][j][1] + 1 + dp[u][i - j][1];
				}
			}
	}
}

void Dfs2(int u , int sum , int t) {
	if(t == 1) ans.pb(u);
	for(auto x : s[u][sum][t]) {
		Dfs2(x.u ,  x.sum , x.t);
	}
}

int main() {
	file();
	cin >> n >> k;
	for(int i = 1 ; i < n ; i++) {
		int u , v ; cin >> u >> v;
		G[u].pb(v);
		G[v].pb(u);
	}
	memset(dp , 0x3f , sizeof(dp));
	Dfs(1 , 0);
	cout << min(dp[1][k][0] , dp[1][k][1]) << '\n';
	Dfs2(1 , k , (dp[1][k][0] < dp[1][k][1]) ? 0 : 1);
	for(int u : ans) cout << u << ' ';
	return 0;
}


