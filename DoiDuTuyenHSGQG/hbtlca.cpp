#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
const long long N=1000001;
ll  n, q, x, y, s[N][20], h[N], l, u, v, root;
string type;
vector<ll> adj[N];
void file()
{
//	freopen(".inp","r",stdin);
//	freopen(".out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
void Dfs(int u)
{
	for(auto x : adj[u])
	{
		if(h[x]!=0) continue;
		s[x][0]=u;
		h[x]=h[u]+1;
		Dfs(x);
    }
}
void build()
{
	for (ll j = 1 ; (1 << j) < n ; ++j)
	for (ll i = 1 ; i <= n ; ++i) 
		s[i][j] = s[s[i][j - 1]][j - 1];
}

int lca(int x,int y)
{
	if( h[x] < h[y] ) swap( x , y );
	int k = (int) log2( h[x] );
	for(int i = k ; i>= 0 ; i--)   if( h[x] - (1<<i) >= h[y] )  x=s[x][i];
	if(x == y) return x;
	  k = (int ) log2( h[x] );
	for( int i = k; i >= 0 ; i--) 
	{
		if (s[x][i] != s[y][i] )
		{
			x=s[x][i];
			y=s[y][i];
		}
	}
	 return s[x][0];
	
}

int solve(int u, int v)
{
	int Lca=lca(u,v), Lca1= lca( u , root ),Lca2= lca( v ,root ),check=max({ h[Lca], h[Lca1], h[Lca2] });
	if( h[Lca1] == check ) return Lca1;
	if( h[Lca2] == check ) return Lca2;
	return Lca;
}
void mainn()
{
	root=1;
	for(int i=1 ; i <= n ; i++) adj[i].clear();
	memset( h, 0, sizeof (h));
    for(int i = 1 ;i < n ; i++ ) 
    {
    	cin>> x>> y;
    	adj[x].pb(y);
    	adj[y].pb(x);
	}
	h[1]=1;s[1][0]=1;
	Dfs(1);
	build();
	cin>>q;
	while(q--)
	{
		cin>>type;
		if(type=="!") 
		{
			cin>>l;
			root=l;
		}
		else {
			
			cin>>u>>v;
			cout<<solve( u, v)<<'\n';
		}
	}
}
int main()
{
	while(cin>>n)
	{
		if(n!=0) mainn();
		else return 0;
	}
}
