#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 10005;
struct edge
{
	ll w, u , v;
} ;
ll par[N] , ans = 0, n , m;
vector <edge> ve;

void file()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
bool cmp(const edge &a, const edge &b)
 {
    return a.w > b.w;
 }
 int root(int v) {
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
int main()
{
   cin >> n >> m;
   
   for( int k = 1; k <= m; k++)
   {
   	      ll x, i ,j;
		 	 cin >> i >> j >> x;
   		 ve.pb ( {x, i , j});	 
   }
   sort( ve.begin() , ve.end() , cmp );
   memset( par , -1 , sizeof (par) );
   for (auto m : ve) 
   {
   	//cout << m.w<<" ";
    if( merge ( m.u , m.v) == false ) ans += m.w; 
   // cout<<ans<<endl;
   }
   cout << ans;
    return 0;
}

