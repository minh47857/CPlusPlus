#include <bits/stdc++.h>
#define y1          asdf
#define rank      afjlg
using namespace std;
const int N = 1e3 + 3;
int n, m, st, dem, visit[N], rank[N];
vector <int> a[N];
bool ok;

void dfs(int u) {
     visit[u] = 1;
     dem += (rank[u] % 2 == 1);
     for (int i = 0; i < a[u].size(); ++i) {
          int v = a[u][i];
          if (! visit[v]) dfs(v);
     }
}

int main() {
     //ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
     //freopen("ceramic.inp","r",stdin);
     //freopen("ceramic.out","w",stdout);
     while (cin >> n >> m >> st, n > 0) {
          memset(visit, -1, sizeof(visit));
          memset(rank, 0, sizeof(rank));
          for (int i = 1; i <= n; ++i) a[i].clear();
          ok = true; dem = 0;
          int u, v;
          while (m--) {
               cin >> u >> v;
               visit[u] = visit[v] = 0;
               a[u].push_back(v);
               a[v].push_back(u);
               rank[u]++; rank[v]++;
          }
          dfs(st);
          for (int i = 1; i <= n; ++i)
               if (! visit[i]) ok = false;
            for(int i = 1 ; i <= n ; i++) cout << visit[i] << endl;
        cout << ok << ' ' << dem << endl;
          if (ok && dem < 1) cout << "YES" << '\n'; else cout << "NO" << '\n';
     }
}
