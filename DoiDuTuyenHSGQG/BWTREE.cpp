#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1e5 + 5 , MOD = 1e9 +7 , inf = 1e15;
ll n , d1[N] , d0[5][N] ;
vector <ll> adj[N];
void file()
{
	freopen("BWTREE.inp" , "r" , stdin);
	freopen("BWTREE.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
void Dfs(ll u , ll pa)
{
	d1[u] = 1;
	bool check = false;
	ll Min = inf;
    for (int i = 0 ; i < adj[u].size() ; i++)
    {
    	ll v = adj[u][i];
    	if (v == pa) continue;
    	Dfs(v , u);
    	d1[u] += min(d0[0][v] , min( d1[v] , d0[1][v]));
		d0[0][u] += d0[1][v];
		if (adj[v].size() == 1) 
		{
			d0[1][u] += d1[v];
			d0[0][u] = inf;
			check = true;
		}
		else
		{
			if (d1[v] <= d0[1][v]) check = true;
		    d0[1][u] += min(d1[v] , d0[1][v]);
		}
		
		Min = min(d1[v] - d0[1][v] , Min);
	}
	if (check == false) d0[1][u] += Min;
}
int main()
{
	file();
   cin >> n ;
   for (int i = 1 ; i < n ; i++)
   {
   	ll u , v;
   	cin >> u >> v ;
   	adj[u].pb(v);
   	adj[v].pb(u);
   }
   Dfs(1 , 0);
   cout << min(d1[1] , d0[1][1]);
   return 0;
}


