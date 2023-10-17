#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
const long long N=1000001;
ll x, y, n, q, s[N][20], tree[N][20], h[N], u, v;
vector<ll> adj[N];
void file()
{
	//freopen(".inp","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

void Dfs( int u)
{
	for( auto x : adj[u] )
	{
		if( h[x] != 0 ) continue;
		h[x]= h[u] + 1;
		 s[x][0]= u;
		 tree[x][0]= x;
		Dfs(x); 
	}
}

int lca(int x, int y)
{
	if(h[x] < h[y]) swap( x, y);
	int k= (int) log2(h[x]);
	for( int i = k; i >= 0; i--)	if( h[x] - (1 << i) >= h[y] ) x= s[x][i];
	if ( x==y ) return x;
	k= (int) log2 (h[x]);
	for( int i = k; i >=0 ; i--)    
	{
		if( s[x][i]  != s[y][i] )
		{
			x= s[x][i];
			y= s[y][i];
		}
	}
	return s[x][0];
}

void build()
{
	for (ll j = 1 ; (1 << j) < n ; ++j)
	for (ll i = 1 ; i <= n ; ++i)   
	{
	s[i][j] = s[s[i][j - 1]][j - 1];
//	cout<<s[i][j]<<" "<<i<<" "<<j<<endl;
    }
	
	for (ll j = 1 ; (1 << j) < n ; ++j)
	for (ll i = 1 ; i <= n ; ++i)   
	{
			tree[i][j]= lca( tree[i][j-1] , tree[i + ( 1<< (j-1) ) ][j-1] );
		//	cout<<tree[i][j]<<" "<<i<<" "<<j<<endl;
	}


}
int solve(int l, int r)
{
	int k= (int) log2( r- l+ 1);
	return lca( tree[l][k] , tree[r + 1- (1<<k)][k]);
}
int main()
{
	file();
  cin>> n >> q;
  for( int i = 1; i < n; i++) 
  {
  	cin>> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  h[1]= 1, s[1][0]= 1, tree[1][0]= 1;
  Dfs(1);
  build();
  for(int i = 1; i <= q; i++) 
  {
  	cin>> x >> y;
  	cout<< solve(x, y) << '\n';
  }
  return 0;
}

