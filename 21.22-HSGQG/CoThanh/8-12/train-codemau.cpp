#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100000 + 10;
const int MAXM = 200000 + 10;
const int INF = (int)(1e9);

int u[MAXM], v[MAXM], r[MAXM];
int f[MAXN], deg[MAXN];
vector<int> adj[MAXN], aff[MAXN];
bool mark[MAXN];
set<pair<int, int>> se;
int n, m, q, res;

void input() {
    scanf("%d %d %d\n", &n, &m, &q); //cin >> n >> m >> q;
    for(int i = 1; i <= m; i++) {
        scanf("%d %d\n", &u[i], &v[i]); //cin >> u[i] >> v[i];
        adj[u[i]].push_back(v[i]);
        adj[v[i]].push_back(u[i]);
    }
    for(int i = 1; i <= q; i++) scanf("%d", &r[i]); //cin >> r[i];
}

void BFS(int u) {
    for(int i = 1; i <= n; i++) f[i] = INF;
    f[u] = 0;
    queue<int> q;
    q.push(u);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for(int v : adj[u])
        if ((f[v] == f[u] + 1) || (f[v] == INF)) {
            if (f[v] == INF) q.push(v);
            f[v] = f[u] + 1;
            aff[u].push_back(v);
            deg[v]++;
        }
    }
}

void init() {
    BFS(1);
}

void DFS(int u, int par) {
    if (se.find(make_pair(par, u)) != se.end()) return;
    se.insert(make_pair(par, u));
    deg[u]--;
    if (deg[u] != 0) return;
    res++;
    for(int v : aff[u]) {
        DFS(v, u);
    }
}

void solve() {
    res = 0;
    for(int i = 1; i <= q; i++) {
        int x = u[r[i]], y = v[r[i]];
        if (f[x] < f[y]) swap(x, y);
        if (f[x] == f[y] + 1) DFS(x, y);
        printf("%d\n", res);
    }
}

void run() {
    input();
    init();
    solve();
}

int main()
{

    int ntests = 1;
    //cin >> ntests;
    for(int tc = 1; tc <= ntests; tc++) {
        run();
    }
}