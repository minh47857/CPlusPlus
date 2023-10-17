#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>
const ll N = 100005 , MOD = 1e9 +7 , inf = 1e15;
void file()
{
	freopen("ORCHID.inp" , "r" , stdin);
	freopen("ORCHID.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , g[N];
pi f[N];
vector<pi> adj[N];

void Max(int u , int val)
{
	if(val > f[u].fi)  
	{
		f[u].se = f[u].fi;
		f[u].fi = val;
		return;
	}
	if(val > f[u].se)
	{
		f[u].se = val;
		return;
	}
}

int get(int u , int v , ll w)
{
	if(f[u].fi != f[v].fi + w) return f[u].fi;
	return f[u].se;
}

void Dfs_f(int u , int pa)
{
	for(auto x : adj[u])
	{
		int v , w;
		v = x.fi;
		w = x.se;
		if(v == pa) continue;
	    Dfs_f(v , u);
	    Max(u , f[v].fi + w);
	}
}

void Dfs_g(int u , int pa)
{
	for(auto x : adj[u])
	{
		int v , w;
		v = x.fi;
		w = x.se;
		if(v == pa) continue;
		g[v] = max(g[u] , get(u , v , w)) + w;
		Dfs_g(v , u);
	}
}

int main()
{
	file();
  cin >> n;
  for(int i = 1 ; i < n ; i++) 
  {
  	int u , v , c;
  	cin >> u >> v >> c;
  	adj[u].pb({v , c});
  	adj[v].pb({u , c});
  }
  Dfs_f(1 , 0);
  Dfs_g(1 , 0);
  for(int i = 1 ; i <= n ; i++) cout << max(g[i] , f[i].fi) << ' ';
  return 0;
  
}

