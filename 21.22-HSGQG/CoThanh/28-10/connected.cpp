#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 105 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("connected.in" , "r" , stdin);
	freopen("connected.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , m , DEG = 1 , vis[N] , t = 0;
vector<int> adj[N] , f[N];
vector<pi> Ans , C;
priority_queue< pi , vector<pi> , greater<pi> > Q;

void Dfs(int u) {
	f[t].pb(u);
	for(auto v : adj[u]) {
		if(vis[v]) continue;
		vis[v] = 1;
		Dfs(v);
	}
}

int main() {
	file();
   cin >> n >> m;
   for(int i = 1 , u , v ; i <= m ; i++) {
   			cin >> u >> v;
   			adj[u].pb(v);
   			adj[v].pb(u);
   }
   for(int i = 1 ; i <= n ; i++) if(!vis[i]) t++ , vis[i] = 1 , Dfs(i);
   for(int i = 1 ; i <= t ; i++) C.pb({f[i].size() , i});
   sort(C.begin() , C.end() , greater<pi>());
   for(auto x : f[C[0].se]) Q.push({0 , x});
   for(int i = 1 ; i < C.size() ; i++) {
   	int id , u , deg_u;
   	 id = C[i].se;
     u = Q.top().se , deg_u = Q.top().fi;
     Q.pop();
     Q.push({deg_u + 1 , u});
     Q.push({1 , f[id][0]});
     if(deg_u + 1 == 2) DEG = 2;
     for(int j = 1 ; j < f[id].size() ; j++) Q.push({0 , f[id][j]});
     Ans.pb({u , f[id][0]});
   }
   cout << DEG << '\n' << Ans.size() << '\n';
   for(auto x : Ans) cout << x.fi << ' ' << x.se << '\n';
   
}

