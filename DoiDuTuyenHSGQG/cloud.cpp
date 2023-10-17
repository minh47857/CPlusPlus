#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<ll,ll>
#define fi first
#define se second
#define pb push_back
const ll N = 2005 , MOD = 1e9 + 7 , inf = 1e15;
ll n , m , c , f , v , dp[3][50 * N] , ans = 0 , sum = 0;
struct node
{
    ll type , c , f , v;
};
vector <node> Q;
void file()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
bool cmp(node &a , node&b)
{
    if (a.f == b.f) return (a.type == 1);
    else return a.f > b.f;
}
int main()
{
    Q.pb({0 , 0 , inf , 0});
  cin >> n ;
  for (int i = 1 ; i <= n ; i++) cin >> c >> f >> v , Q.pb({1 , c , f , v}) , sum += c;
  cin >> m ;
  for (int i = 1 ; i <= m ; i++) cin >> c >> f >> v , Q.pb({2 , c , f , v});
  sort(Q.begin() , Q.end() , cmp);
  for (int i = 0 ; i <= 1 ; i++)
  {
      for (int j = 0 ; j <= sum ; j++)
      dp[i][j] = -inf;
  }
  dp[0][0] = 0;
  for (int i = 1 ; i < Q.size() ; i++)
  {
      for (int j = 0 ; j <= sum; j++)
      {
          if (Q[i].type == 1)
          {
              if (j >= Q[i].c)     dp[i % 2][j] = max (dp[i % 2][j] , dp[1 - i % 2][j - Q[i].c] - Q[i].v) ;
            dp[i % 2][j] = max (dp[i % 2][j] , dp[1 - i % 2][j]);
        }
       else 
       {
           if (j + Q[i].c <= sum) dp[i % 2][j] = max(dp[i % 2][j] , dp[1 - i % 2][j + Q[i].c] + Q[i].v);
           dp[i % 2][j] = max(dp[i % 2][j] , dp[1 - i % 2][j]);
       }
      // cout <<i << ' ' << j <<' ' << Q[i].type << ' ' << Q[i].c <<' '<< Q[i].f << ' ' << Q[i].v <<' ' <<dp[i][j] << endl;
    }
  }
  for (int i = 0 ; i <= sum ; i++) ans = max(ans , dp[(n + m) % 2][i]);
  cout << ans;
  return 0;
}


