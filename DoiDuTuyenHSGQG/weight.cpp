#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 10000005 , MOD = 1e9 +7;
char s ;
ll a , b , c , n , m , d[N] , par[N];
void file()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
ll root(ll v) 
{
    if( par[v] < 0 ) return v ;
    ll k = root(par[v]);
    d[v] += d[par[v]];
    par[v] = k;
    return k;
}

void merge(ll x, ll y , ll z , ll  u , ll v) 
{
	if(u == v) return;
    if (par[v] < par[u])   swap(u, v) , z *= - 1 , swap (x , y);
    par[u] += par[v];
    par[v] = u;
    d[v] = z + d[x] - d[y];
}
void solve()
{
    memset(par , -1 , sizeof (par));
    memset(d , 0 , sizeof ( d));
   for (ll i = 1; i <= m ; i ++)
   {
        cin >> s >> a >> b;
        ll u , v;
         u = root(a);
      v = root(b);
        if (s == '!') cin >> c , merge(a , b , c , u , v);
        else 
        {
         if (u != v)  cout << "UNKNOWN";
         else    cout << d[b] - d[a] ;
         cout << '\n';
     }
   }
}
int main ()
{
    // file();
    while (cin >> n >> m)
    {
        if (n == 0 && m == 0) return 0;
        else solve();
    }
}

