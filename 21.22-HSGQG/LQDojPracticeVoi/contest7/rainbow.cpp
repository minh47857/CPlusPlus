#include<bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 505 , MOD = 1e9 + 9;

using namespace std;

int n , f[N] , k;
ll ans = 1;
bool ok = true;
vector<int> adj[N];

void Dfs(int u , int pa , int h) {
	if(!ok) return;
	int child = 0 , cnt = 0;
	for(int v : adj[u]) 
		if(v != pa) child++;
	for(int v : adj[u]) 
		if(v != pa) {
			f[v] = child;
			ll w = k - (f[u] + cnt + (h >= 3));
			if(w <= 0) ok = false;
			else ans = ans * w % MOD;
			cnt++;
			Dfs(v , u , h + 1);
		}
}

int main() {
	cin >> n >> k;
	int dem = 0;
	for(int i = 1 ; i < n ; i++) {
		int u , v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
		dem++;
	}
	assert(dem == n - 1);
	Dfs(1 , 0 , 1);
	cout << ((ok) ? ans : 0);
	return 0;
}

