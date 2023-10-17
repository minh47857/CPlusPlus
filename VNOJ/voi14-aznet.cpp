#include<bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 1e4 + 5 , M = 1e5 + 5 , inf = 1e9 + 7;

using namespace std;

struct node {
	int u , v , id;
};

struct Dsu {
	vector<int> par;
	Dsu(int n) : par(n + 1) {
		for(int i = 1 ; i <= n ; i++) par[i] = -1;
	}
	int parent(int u) {
		if(par[u] < 0) return u;
		return par[u] = parent(par[u]);
	}
	bool merge(int x , int y) {
		if((x = parent(x)) == (y = parent(y))) return false;
		if(par[x] > par[y]) swap(x , y);
		par[x] += par[y];
		par[y] = x;
		return true;
	}
	void reset() {
		for(int i = 1 ; i < par.size() ; i++) par[i] = -1;
	}
};

int n , m , t , a[N] , b[N];
bool ans[M];
vector<node> A , B;

void solve() {
	int Mincost , Maxcost , res = 0 , NumEdgeA; 
	ll cost = LLONG_MAX;
	A.clear() , B.clear();
	cin >> n >> m;
	for(int i = 1 ; i < n ; i++) cin >> a[i];
	for(int i = 1 ; i < n ; i++) cin >> b[i];
	for(int i = 1 ; i <= m ; i++) {
		int u , v , c ; cin >> u >> v >> c;
		if(c == 1) A.pb({u , v , i});
		else B.pb({u , v , i});
		ans[i] = false;
	}
	Dsu f(n);
	for(auto x : B) if(f.merge(x.u , x.v)) res++;
	Mincost = n - 1 - res;
	f.reset() , res = 0;
	for(auto x : A) if(f.merge(x.u , x.v)) res++;
	Maxcost = res;
	for(int i = Mincost ; i <= Maxcost ; i++) 
		if(cost > a[i] + b[n - i - 1]) 
			cost = a[i] + b[n - i - 1] , NumEdgeA = i;
	f.reset();
	for(auto x : B) f.merge(x.u , x.v);
	for(auto x : A) ans[x.id] = f.merge(x.u , x.v);
	f.reset();
	for(auto x : A) if(ans[x.id]) f.merge(x.u , x.v) , NumEdgeA--;
	for(auto x : A) 
		if(NumEdgeA && f.merge(x.u , x.v)) ans[x.id] = true , NumEdgeA--;
	for(auto x : B)	ans[x.id] = f.merge(x.u , x.v);
	for(int i = 1 ; i <= m ; i++) 
		if(ans[i]) cout << i << ' ';
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> t;
	while(t--) solve();
	return 0;
}

