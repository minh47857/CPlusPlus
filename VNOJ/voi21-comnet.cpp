#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1005 , MOD = 1e9 +7 , inf = 1e15;
void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
ll n , k , a , b , f[N][N][5] , edge[N] , ans = 0;
vector<int> adj[N];

void Dfs(int u , int pa)
{
	f[u][0][1] = f[u][0][0] = 1;
	for(auto v : adj[u])
	if(v != pa)
	 {
	 	Dfs(v , u);
		for(int cur = edge[u] ; cur >= 0 ; cur--)
		  for(int vedge = edge[v] ; vedge >= 0 ; vedge--)
		     for(int curnode = 0 ; curnode < k ; curnode++)
		       for(int vnode = 1 ; vnode + curnode <= k ; vnode++)
		         {
		         	f[u][cur + vedge + (vnode < k) ][vnode + curnode] += f[u][cur][curnode] * f[v][vedge][vnode];
				 }
		edge[u] += (edge[v] + 1);
	 }
}
int main()
{
	file();
 cin >> n >> k >> a >> b;
 for(int i = 1 ; i < n ; i++)
 {
 	int u , v;
 	cin >> u >> v;
 	adj[u].pb(v);
 	adj[v].pb(u);
 }
 Dfs(1 , 0);
 for(int i = a ; i <= b ; i++) ans += f[1][i][k];
 cout << ans;
}

