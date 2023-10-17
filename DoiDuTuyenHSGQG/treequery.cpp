#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
const long long N=1000001;
ll  n, q, x, y, s[N][20], h[N], u, v, a, b, k;
string type;
vector<ll> adj[N];
void file()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
void Dfs(int u)
{
	for(auto x : adj[u])
	{
		if(h[x] != 0 || x == 1) continue;
		s[x][0] = u;
		h[x] = h[u] + 1;
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
ll dist(int j , int l)
{
	return h[j] + h[l] - 2 * h[lca(j , l)];
}
bool check(ll len , ll p)
{
	if ( len <= p && (p - len ) % 2 == 0) return true;
	return false;
}
void solve()
{
	cin >> u >> v >> a >> b >> k;
	ll dist_1 = dist(a , b) ;
	ll dist_2 = dist(a , u) + dist( b , v) + 1;
	ll dist_3 = dist(a , v) + dist( b , u) + 1;	
	if( (check(dist_1 , k) ) || check(dist_2 , k) || check(dist_3 , k) ) cout << "YES" << '\n';
	else cout << "NO" << '\n';
}
int main()
{
	file();
	cin >> n;
	 for(int i = 1 ;i < n ; i++ ) 
    {
    	cin >> x >> y;
    	adj[x].pb(y);
    	adj[y].pb(x);
	}
	h[1] = 0;
	Dfs(1); 
	build();
	cin >> q;
	for (int i = 1; i <= q; i++)  solve();
	return 0;
}
