#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<ll,ll>
#define fi first
#define se second
#define pb push_back
const ll N = 1000005 , MOD = 1e9 + 7 , inf = 1e15;
ll n , m , d , c , deg[N] ; 
vector <ll> ans , edge[N] , adj[N];
void file()
{
	freopen("order.inp" , "r" , stdin);
    freopen("order.out" , "w" , stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
bool check(int x)
{
    memset(deg , 0 , sizeof (deg));
    vector<ll>  res;
    priority_queue<ll , vector<ll> , greater<ll>> Q;
    for (int i = 1 ; i <= n ; i++) adj[i].clear();
    for (int i = 1 ; i <= x ; i++)
    {
        for (int j = 0 ; j < edge[i].size() - 1 ; j++)
        {
            adj[edge[i][j]].pb(edge[i][j + 1]);
            deg[edge[i][j + 1]]++;
        }
    }
    for (int i = 1 ; i <= n ; i++)     if (deg[i] == 0) Q.push(i) ;
    while (Q.size())
    {
      int    u = Q.top();
      res.pb(u);
      Q.pop();
      for (auto x : adj[u])
      {
        deg[x]--;
        if (deg[x] == 0) Q.push(x);
      }
    }
  if (res.size() == n)    
  {
      ans = res;
      return true;
  }
  return false;
}
int main()
{
    file();
  cin >> n >> m ;
  for (int i = 1 ; i <= m ; i++)
  {
      int k , x;
      cin >> k; 
      for (int j = 1 ; j <= k ; j++) cin >> x , edge[i].pb(x);    
  }
  d = 0 , c = m;
  while (d <= c)
  {
      int g = (d + c) / 2;
      if(check(g)) d = g + 1;
      else c = g - 1;
  }
  for (auto x : ans) cout << x << ' ';
  return 0;
}
