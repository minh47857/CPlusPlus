#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back

const ll N = 1e3 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
    freopen("Guard.inp" , "r" , stdin);
	freopen("Guard.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll n , dp[N][5];
vector<int> adj[N];

void Dfs(int u , int pa) {
	// dp[u][0] : u ko co sung , u da co it nhat 1 con co sung
	// dp[u][1] : u co sung
	// dp[u][2] : u ko co sung , con cua u ko co sung
	if(adj[u].size() == 1 && u != 1) {
		dp[u][0] = inf;
		dp[u][1] = 1;
		dp[u][2] = 0;
		return;
	}
	ll best0 = inf , tmp;
	for(int v : adj[u]) {
		if(v == pa) continue;
		Dfs(v , u);
		tmp = min(dp[v][0] , dp[v][1]);
		best0 = min(best0 , dp[v][1] - tmp);
		dp[u][1] += min(tmp , dp[v][2]);
		dp[u][2] += dp[v][0];
		dp[u][0] += tmp;
	}
	dp[u][1]++;
	dp[u][0] += best0;
}

int main() {
	file();
	cin >> n;
	for(int i = 1 , u , v ; i < n ; i++)
		cin >> u >> v,
		adj[u].pb(v) , adj[v].pb(u);
	Dfs(1 , 0);	
	cout << min(dp[1][0] , dp[1][1]);
	return 0;
}


