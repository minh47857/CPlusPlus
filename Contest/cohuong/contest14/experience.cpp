#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<ll,ll>
#define fi first
#define se second
#define pb push_back

const ll N = 100005 , MOD = 1e9 + 7 , inf = 1e15;

void file() {
	freopen("experience.in" , "r" , stdin);
	freopen("experience.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll n , w[N] , dp[N][5];
vector<int> adj[N];
	
void Dfs(int u , int pa) {
	ll s = 0;
	for(auto v : adj[u]) {
		if(v == pa) continue;
		Dfs(v , u);
		s += max(dp[v][0] , dp[v][1]);
	}
	dp[u][0] = dp[u][1] = s;
	for(auto v : adj[u]) {
		if(v == pa) continue;
	  if(w[u] >= w[v])	dp[u][0] = max(dp[u][0] , s - max(dp[v][1] , dp[v][0]) + w[u] - w[v] + dp[v][0]);
	  if(w[u] <= w[v])  dp[u][1] = max(dp[u][1] , s - max(dp[v][1] , dp[v][0]) + w[v] - w[u] + dp[v][1]);
	}
}

int main() {
	file();
  cin >> n;
  for(int i = 1 ; i <= n ; i++) cin >> w[i];
   for(int i = 1 ; i < n ; i++) {
  	       int u , v;
  	       cin >> u >> v;
  	       adj[u].pb(v);
  	       adj[v].pb(u);
    } 
		Dfs(1 , 0);
		cout << max(dp[1][0] , dp[1][1]);
		return 0;
}

