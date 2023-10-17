#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back
#define Bit(x , k) ((x >> k) & 1)

const ll N = 3e5 + 5 , MOD = 998244353 , inf = 1e9;

void file() {
    freopen("cnt-mst.inp" , "r" , stdin);
	freopen("cnt-mst.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll ans = 1;
int n , m , t , par[N] , S , vis[N];
vector<int> G[N];

struct mst {
	int x , y , w;
	bool operator < (const mst&s) const {return w < s.w;}
} E[N];

int parent(int u) {
	if(par[u] < 0) return u;
	par[u] = parent(par[u]);
	return par[u];
}

void merge(int x , int y) {
	if((x = parent(x)) == (y = parent(y))) return;
	if(par[x] > par[y]) swap(x , y);
	par[x] += par[y];
	par[y] = x;
}

void Dfs(int u) {
	for(auto v : G[u]) if(!vis[v]) {
		vis[v] = 1;
		S++;
		Dfs(v);
	}
}

void Solve(vector<pi> a) {
	int k = a.size();
	pi res = {0 , 1};
	for(int mask = 1 ; mask < (1 << k) ; mask++) {
		vector<int> P;
		S = 0;
		for(int i = 0 ; i < k ; i++) if(Bit(mask , i)) {
			G[a[i].fi].pb(a[i].se);
			G[a[i].se].pb(a[i].fi);
			P.pb(a[i].fi) , P.pb(a[i].se);
		}
		P.erase(unique(P.begin() , P.end()) , P.end());
		for(auto x : P) if(!vis[x]) vis[x] = 1 , Dfs(x);
		if(__builtin_popcount(mask) == S && res.fi <= S) {
			if(res.fi == S) res.se++;
			else res = {S , 1};
		}
		for(auto x : P) G[x].clear() , vis[x] = 0; 
	}
	ans = (ans * res.se) % MOD;
}

int main() {
	file();
	memset(par , -1 , sizeof(par));
	cin >> t >> n >> m;
	for(int i = 1 ; i <= m ; i++) {
		cin >> E[i].x >> E[i].y >> E[i].w;
	}
	sort(E + 1 , E + m + 1);
	for(int i = 1 ; i <= m ; i++) {
		int j = i;
		vector<pi> Cp;
		while(j <= m && E[i].w == E[j].w) {
			int x , y;
			x = parent(E[j].x) , y = parent(E[j].y);
			Cp.pb({x , y});
			j++;
		}
		Solve(Cp);
		j = i;
		while(j <= m && E[i].w == E[j].w) {
			merge(E[j].x , E[j].y);
			j++;
		}
		i = j - 1;
	}
	cout << ans;
	return 0;
}


