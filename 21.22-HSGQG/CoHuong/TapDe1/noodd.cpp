#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 1005 , MOD = 1e9 + 7 , inf = 1e9 + 7;

int t , n , m , c[N][N] , side[N] , p[2] , dp[N] , f[N];
queue<int> Q;

void file() {
	freopen("noodd.in" , "r" , stdin);
	freopen("noodd.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

void solve() {
	cin >> n >> m;
	int ans = 0;
	bool ok = true;
	vector<int> A;
	memset(c , 0 , sizeof(c));
	memset(side , -1 , sizeof(side));
	for(int i = 1 ; i <= m ; i++) {
		int u , v;
		cin >> u >> v;
		c[u][v] = c[v][u] = 1;
	}
	for(int i = 1 ; i <= n ; i++) {
		if(side[i] != -1) continue;
		side[i] = p[0] = p[1] = 0;
		Q.push(i);
		while(!Q.empty()) {
			int u = Q.front();
			Q.pop();
			p[side[u]]++;
			for(int v = 1 ; v <= n ; v++) if(c[u][v]) {
				if(side[v] == -1) side[v] = 1 - side[u] , Q.push(v);
				else ok &= (side[v] != side[u]);
			}
		}
		A.pb(abs(p[0] - p[1]));	
	}
	memset(dp , 0 , sizeof(dp));
	dp[0] = 1;
	for(auto x : A) {
		for(int i = 0 ; i <= n ; i++) f[i] = dp[i] , dp[i] = 0;
		for(int i = 0 ; i <= n ; i++) if(f[i]) dp[i + x] = 1 , dp[abs(i - x)] = 1;
	}
	for(int i = 0 ; i <= n ; i++)
		if(dp[i]) ans = max(ans , (n * n - i * i) / 4);
	cout << ((ok) ? (ans - m) : -1) << '\n';
}

int main() {
	file();
	cin >> t;
	while(t--) solve();
}

