#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back

const int N = 5e5 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
    freopen("mst.inp" , "r" , stdin);
	freopen("mst.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , m , t , par[N] , ans[N] , Time , low[N] , num[N] , used[N];
vector<pi> Adj[N];

struct mst {
	int x , y , w , id;
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
    num[u] = low[u] = ++Time;
	for(auto x : Adj[u]) if(!used[x.se]) {
		int v = x.fi , cnt = x.se;
		used[x.se] = 1;
		if(num[v]) low[u] = min(low[u] , num[v]);
		else {
			Dfs(v);
			low[u] = min(low[u] , low[v]);
			if(low[v] > num[u]) ans[cnt] = 1;
		}
	}
}

int main() {
	file();
	memset(par , -1 , sizeof(par));
	cin >> t >> n >> m;
	for(int i = 1 ; i <= m ; i++) {
		cin >> E[i].x >> E[i].y >> E[i].w;
		E[i].id = i;
	}
	sort(E + 1 , E + m + 1);
	for(int i = 1 ; i <= m ; i++) {
		vector<int> Root;
		Time = 0;
		int j = i;
		while(j <= m && E[i].w == E[j].w) {
			int x , y;
			x = parent(E[j].x) , y = parent(E[j].y);
			if(x != y){
				Adj[x].pb({y , E[j].id});
			    Adj[y].pb({x , E[j].id});
			    Root.pb(x) , Root.pb(y);
			} 
			j++;
		}
		if(Root.size()) {
			Root.erase(unique(Root.begin() , Root.end()) , Root.end());
			for(auto x : Root) if(!num[x]) Dfs(x);
			for(auto x : Root) {
				low[x] = num[x] = 0;
				Adj[x].clear();
			}
		}
		
		j = i;
		while(j <= m && E[i].w == E[j].w) {
			merge(E[j].x , E[j].y);
			j++;
		}
		i = j - 1;
	}
	for(int i = 1 ; i <= m ; i++) cout << ((ans[i]) ? "Yes" : "No") << ' ';
	return 0;
}


