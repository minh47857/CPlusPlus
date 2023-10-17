#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 100001 , MOD = 1e9 +7 , inf = 1e15;
void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
 
 ll n , m , q , u[N] , d[N] , c[N] , colour[N] , f[N][15];
 vector<int> adj[N];
void solve(int a , int b , int c)
{
	if(f[a][b] || b < 0) return;
	f[a][b] = 1;
	if(colour[a] == 0) colour[a] = c;
	for (auto x : adj[a]) solve(x , b - 1 , c);
}

int main()
{
	file();
   cin >> n >> m;
   for (int i = 1 ; i <= m ; i++)
   {
   	int x , y;
   	cin >> x >> y;
   	adj[x].pb(y);
   	adj[y].pb(x);
   }
   cin >> q;
   for (int i = 1 ; i <= q ; i++) cin >> u[i] >> d[i] >> c[i];
   for (int i = q ; i >= 1 ; i--)	solve(u[i] , d[i] , c[i]);
   for (int i = 1 ; i <= n ; i++) cout << colour[i] << '\n';
   return 0;
   
}

