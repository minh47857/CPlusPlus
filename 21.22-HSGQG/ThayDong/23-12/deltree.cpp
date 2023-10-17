#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 3e5 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

int n , c[N] , dp[N][5];
string str;
vector<int> G[N]; 

void Dfs(int u , int pa) {
	dp[u][0] = c[u];
	dp[u][1] = 1 - c[u];
	for(int v : G[u]) {
		if(v == pa) continue;
		Dfs(v , u);
		dp[u][0] += min(dp[v][0] , dp[v][1] + 1);
		dp[u][1] += min(dp[v][1] , dp[v][0] + 1);
	}
}

int main() {
	cin >> n >> str;
	str = ' ' + str;
	for(int i = 1 ; i <= n ; i++)
		c[i] = str[i] - '0';
	for(int i = 1 ; i < n ; i++) {
		int u , v;
		cin >> u >> v;
		G[u].pb(v);
		G[v].pb(u);
	}
	Dfs(1 , 0);
	cout << min(dp[1][0] , dp[1][1]) + 1;
	return 0;
}

