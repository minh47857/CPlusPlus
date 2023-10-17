#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n;

namespace sub1 {
	const int Lim = 7200;
	vector<pi> a[35];
	int pos , ans = 0 , sum = 0 , f[35][7205] , id[125];
	void solve() {
		for(int i = 1  , t , x ; i <= 4 * n ; i++) {
			cin >> x >> t;
			a[t].pb({x , i});
			sum += x;
		}
		f[0][0] = 1;
		for(int i = 1 ; i <= n ; i++) {
			for(int S = 0 ; S <= Lim ; S++)
			for(int j = 0 ; j < 3 ; j++)
			for(int k = j + 1 ; k <= 3 ; k++)
			if(a[i][j].fi + a[i][k].fi <= S) f[i][S] |= f[i - 1][S - a[i][j].fi - a[i][k].fi];
		}
		for(int i = 0 ; i <= Lim ; i++) 
		   if(f[n][i] && abs(2 * i - sum) <= abs(2 * ans - sum)) ans = i; 
		pos = n;
		while(pos) {
			for(int j = 0 ; j < 3 ; j++) {
				bool check = true;
				for(int k = j + 1 ; k <= 3 ; k++)
					if(a[pos][j].fi + a[pos][k].fi <= ans && f[pos - 1][ans - a[pos][j].fi - a[pos][k].fi]) {
						ans = ans - a[pos][j].fi - a[pos][k].fi;
						id[a[pos][j].se] = id[a[pos][k].se] = 1;
						pos--;
						check = false;
						break;
				    }
				if(!check) break;
			}
		}
		for(int i = 1 ; i <= 4 * n ; i++) if(id[i]) cout << i << ' ';
    }
}

namespace sub2 {
	int vis[30005] , used[120005] , m[120005] , c[120005];
	vector<pi> adj[30005];
	vector<int> Q;
	void Dfs(int u , int id) {
		vis[u] = 1;
		while(adj[u].size()) {
			pi x = adj[u].back();
			adj[u].pop_back();
			if(!used[x.se]) used[x.se] = 1 , Dfs(x.fi , x.se);
		}
		if(id) Q.pb(id);
	}
	void solve() {
		for(int i = 1 ; i <= 4 * n ; i++) cin >> m[i] >> c[i];
		for(int i = 1 ; i <= 2 * n ; i++) {
			adj[c[i]].pb({c[4 * n + 1 - i] , i});
			adj[c[4 * n + 1 - i]].pb({c[i] , i});
		}
		for(int i = 1 ; i <= n ; i++) {
			if(!vis[i]) {
				Q.clear();
				Dfs(i , 0);
				for(int i = 0 ; i < Q.size() ; i += 2) cout << Q[i] << ' ' << 4 * n + 1 - Q[i] << ' ';
			}
		}
	} 
	
}

int main() {
	cin >> n;
	if(n <= 30) sub1::solve();
	else sub2::solve();
	return 0;
}
