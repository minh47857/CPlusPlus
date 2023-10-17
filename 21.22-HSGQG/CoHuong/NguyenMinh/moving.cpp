#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>

const ll N = 105 , M = 5e3 + 5, inf = 1e15;

void file() {
    freopen("moving.in" , "r" , stdin);
    freopen("moving.out" , "w" , stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int t , n , m , k , s[M] , d[M];
ll ans , c[N][N] , f[N][M][3][3];

ll calc(int u , int mission , int p1 , int p2) {
    
    if(mission == k) return 0;
    if(f[u][mission][p1][p2] != -1) return f[u][mission][p1][p2];
    ll best = inf;
    if(p1 == 0) {
        best = min(best , calc(s[mission + 1] , mission , 1 , 0) + c[u][s[mission + 1]]);
    }
    else {
        best = min(best , calc(d[mission + 1] , mission + 1, p2 , 0) + c[u][d[mission + 1]]);
        if(p2 == 0) best = min(best , calc(s[mission + 2] , mission , p1 , 1) + c[u][s[mission + 2]]);
    }
    f[u][mission][p1][p2] = best;
    return best;
}

void solve() {
    cin >> n >> m >> k;
    memset(f , -1 , sizeof(f));
    for(int i = 0 ; i <= n ; i++)
      for(int j = 0 ; j <= n ; j++)
        c[i][j] = (i == j) ? 0 : inf;
        
    for(int i = 1 ; i <= m ; i++) {
        ll u , v , w;
        cin >> u >> v >> w;
       c[u][v] = min(w , c[u][v]) , c[v][u] = min(w , c[v][u]);
    }
    
    for(int l = 1 ; l <= n ; l++)
        for(int i = 1 ; i <= n ; i++)
      for(int j = 1 ; j <= n ; j++)
       c[i][j] = min(c[i][j] , c[i][l] + c[l][j]);
        
    for(int i = 1 ; i <= k ; i++)    cin >> s[i] >> d[i];
    s[k + 1] = d[k + 1] = s[k + 2] = d[k + 2] = 0;
    ans = calc(1 , 0 , 0 , 0) ;
    if(ans == inf) cout << -1 << '\n';
    else cout << ans << '\n';
}

int main() {
    file();
  cin >> t;
  while(t--) solve();
  return 0;
}
