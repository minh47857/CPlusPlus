#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 105 , MOD = 1e9 +7 , inf = 1e15 , M = 10005;
void file()
{
	freopen("treegcd.inp" , "r" , stdin);
	freopen("treegcd.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll n , m , c[N][M] , res = 0 , ans[M] ;
int best = 0;
vector<int> adj[N] , f[M];
void Dfs(int u , int pa)
{
	for(auto x : adj[u]) if(x != pa) Dfs(x , u);
	for (int i = 1 ; i <= m ; i++)
	    for(auto v : adj[u])
	    {
	    	if(v == pa) continue;
	    	ll tmp = 0;
     	    for(auto x : f[i]) tmp = (tmp + c[v][x]) % MOD;
     	    c[u][i] = (c[u][i] * tmp) % MOD;
     	}
}

int main()
{
	file();
   cin >> n >> m;
   for (int i = 1 ; i < n ; i++) 
   {
   	int u , v;
   	  cin >> u >> v ;
   	  adj[u].pb(v);
   	  adj[v].pb(u);
   }
   
   for (int i = 1 ; i <= m ; i++)
      for (int j = 1 ; j <= m ; j++) if(__gcd(i , j) != 1) f[i].pb(j) ;
      
    for (int i = 1 ; i <= n ; i++)
      for (int j = 1 ; j <= m ; j++)
         c[i][j] = 1;
      Dfs(1 , 0);
    for(int i = 1 ; i <= m ; i++) res = (res + c[1][i]) % MOD;
    cout << res;
    return 0;
}

