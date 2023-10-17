#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 10001 , MOD = 1e9 +7;
struct node
{
	ll  u , v , c;
};
ll n , m , k , t  ;
vector <node> ve;
bool operator < (const node&a , const node&b)
{
	return a.c < b.c ;
}
void file()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
namespace sub1
{
	ll par[N] , ans = 0;
int root(int v)
{
    return par[v] < 0
            ? v
            : (par[v] = root(par[v]));
}

bool merge(int x, int y) 
{
    if ((x = root(x)) == (y = root(y)) )   return false ;
    if (par[y] < par[x])  swap(x, y);
    par[x] += par[y];
    par[y] = x;
    return true;
}
	void solve()
	{
		memset(par , -1 , sizeof(par));
		for (auto x : ve)	if (merge(x.u , x.v)) ans += x.c;
		cout << ans;
	}
}
int main()
{
  cin >> n >> m  ;
 // for (int i = 1 ; i <= k ; i++) cin >> x , d[x] = 1;
  for (int i = 1 ; i <= m ; i++)
  {
  	ll x , y , c;
  	cin >> x >> y >> c;
  //	adj[u].pb({v , c});
  //	adj[v].pb({u , c});
  	ve.push_back({x , y , c});
  }
  sort (ve.begin() , ve.end());
  sub1::solve();
}
