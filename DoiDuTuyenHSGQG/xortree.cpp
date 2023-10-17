#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1000001 , MOD = 1e9 +7;
struct node
{
    ll u , v , w , id;
};
ll n , m , pos[N] , child[N] , bit[N] , res[N] , t , par[N]; 
node a[N] , b[N];
vector <ll> v , adj[N];

void file()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
bool operator < (node&q , node&p)
{
    return  q.w < p.w;
}
void Dfs(ll u , ll pa)
{
    child[u] = 1;
    for (auto x : adj[u])
    {
        if (x == pa) continue;
        par[x] = u;
        pos[x] = v.size() + 1;
        v.pb(x);
        Dfs(x , u);
        child[u] += child[x];
    }
}
void update(ll u , ll v)
{
    for (ll i = u ; i <= n ; i += (i & (- i))) bit[i] = bit[i] ^ v ;
    return;
}
ll get(ll u)
{
    ll ans = 0;
    for (ll i = u ; i >= 1 ; i -= (i & (-i))) ans = ans ^ bit[i] ;
    return ans;
}
void solve()
{
  cin >> n ;
  for (ll i = 1; i <= n ; i++) adj[i].clear();
  memset(bit , 0 , sizeof(bit));
  memset(child , 0 , sizeof(child));
  memset(pos , 0 , sizeof(pos));
  memset(res , 0 , sizeof(res));
  memset(par , 0 , sizeof(par));
  v.clear();
  for (ll i  = 1 ; i < n ; i ++) 
  {
  ll x , y , c;    cin >> x >> y >> c;
      adj[x].pb(y);
      adj[y].pb(x);
      a[i] = {x , y , c , i};
  }
  pos[1] = 1 , par[1] = 0;
  v.pb(1);
  Dfs(1 , 0);
 
  cin >> m ;
  for (ll i = 1; i <= m ; i++)  cin >> b[i].u >> b[i].v >> b[i].w , b[i].id = i;
  for (int i = 1;  i < n ; i++)    if (par[a[i].u] == a[i].v) swap (a[i].u , a[i].v);
  sort(a + 1, a + n);
  sort(b + 1 , b + m + 1);
  ll num = 0;
  for (ll i = 1 ; i <= m; i++)
  {
      while (b[i].w >= a[num + 1].w && num < n - 1 ) 
      {
          num++;
          update(pos[a[num].v] , a[num].w);
          update(pos[a[num].v] + child[a[num].v] , a[num].w);
    }
        res[b[i].id] = get(pos[b[i].u]) ^ get(pos[b[i].v]) ;
  }
  for (ll i = 1; i <= m ; i++)
  {
       cout << res[i]  << '\n';
  }
}
int main()
{
    file();
    cin >> t;
    while (t--) solve();
    return 0;
}

