#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll  N = 55 , MOD = 1e9 +7,
          row[5] = {0 , -1 , 1 , 0} , 
          col[5] = {1 , 0 , 0 , -1} ;
ll ans = LLONG_MAX , n , m , dp[N][N][N][N] , x , y , u , v ;
char s[N][N];
struct node
{
    ll a , b, c , d ;
} ;
    queue<node> q;
bool check(ll x1 , ll y1 ,ll u1 ,ll v1)
{
    if(dp[x1][y1][u1][v1] != LLONG_MAX || x1 > n || x1 < 1 || y1 > m || y1 < 1 || s[x1][y1] =='#' ) return false;
    return true;
}
void BFS()
{
    q.push({u , v , x , y});
    dp[u][v][x][y] = 0;
    while(q.size() != 0)
    {
        node t = q.front();
        q.pop();
    //    cout << t.a << ' ' << t.b << ' ' << t.c <<' ' << t.d <<endl;
      for (ll i = 0 ; i <= 3 ; i++) 
      {
        ll    n_row = t.a + row[i],
            n_col = t.b + col[i],
            nx = t.c,
            ny = t.d;
        if(n_row == t.c && n_col == t.d) nx = t.a , ny = t.b;
          if (check(n_row , n_col , nx , ny) ) 
          {
             dp[n_row][n_col][nx][ny] = dp[t.a][t.b][t.c][t.d] + 1 ;
           q.push({n_row , n_col , nx , ny});
        }
      }
    }
    
    for (ll i = 1; i <= n ; i ++)
    for (ll j = 1; j <= m ; j ++)
        ans = min (ans , dp[i][j][1][1]); 
    if (ans == LLONG_MAX) cout << "Impossible";
    else cout << ans;
}
int main()
{
   cin >> n >> m; 
   
   for (ll i = 1; i <= n ; i++) 
    for (ll j = 1; j <= m; j ++) 
    {
        cin >> s[i][j] ;
        if (s[i][j] == '.') u = i , v = j;
        if (s[i][j] == 'X')  x = i , y = j;
    }
   
   for (ll i = 1; i <= n ; i++)
    for (ll j = 1; j <= m ; j++)
       for (ll k = 1 ; k <= n ; k++)
          for (ll l = 1; l <= m; l++)
              dp[i][j][k][l] = LLONG_MAX;
   BFS();
   return 0;
}

