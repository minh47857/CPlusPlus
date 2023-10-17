#include<bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define eb emplace_back

using namespace std;

const int maxn = 501, INF = 1e9;
const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

typedef pair<int, int> ii;

int N, M, Ans = INF;
int A[maxn][maxn];
int F[maxn][maxn];
int D[5][10][maxn][maxn];
vector<ii> V[4], Q[10001];

bool inside(int i, int j) {
  return 1 <= i && i <= N && 1 <= j && j <= M;
}

void dijkstra(int id, int val) {
  #define P D[id][val]
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= M; ++j) {
      P[i][j] = INF;
    }
  }
  for (ii E : V[id]) {
    P[E.x][E.y] = abs(A[E.x][E.y] - val);
    Q[P[E.x][E.y]].eb(E);
  }
  for (int w = 0; w < 10001; ++w) {
    while (!Q[w].empty()) {
      ii cur = Q[w].back(); Q[w].pop_back();
      int u = cur.x, v = cur.y;
      if (P[u][v] != w) continue;
      int nw, nu, nv;
      for (int i = 0; i < 4; ++i) {
        nu = u + dx[i], nv = v + dy[i];
        if (inside(nu, nv)) {
          nw = w + abs(A[nu][nv] - val);
          if (P[nu][nv] > nw) {
            P[nu][nv] = nw;
            Q[nw].eb(nu, nv);
          }
        }
      }
    }
  }
  #undef P
  return;
}

void go(int val) {
  int Res = INF;
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= M; ++j) {
      F[i][j] = D[0][val][i][j] + D[1][val][i][j] - abs(A[i][j] - val);
      Q[F[i][j]].eb(i, j);
    }
  }
  for (int w = 0; w < 10001; ++w) {
    while (!Q[w].empty()) {
      ii cur = Q[w].back(); Q[w].pop_back();
      int u = cur.x, v = cur.y;
      if (F[u][v] != w) continue;
      Res = min(Res, D[2][val][u][v] + D[3][val][u][v] + w - 2 * abs(A[u][v] - val));
      int nw, nu, nv;
      for (int i = 0; i < 4; ++i) {
        nu = u + dx[i], nv = v + dy[i];
        if (inside(nu, nv)) {
          nw = w + abs(A[nu][nv] - val);
          if (F[nu][nv] > nw) {
            F[nu][nv] = nw;
            Q[nw].eb(nu, nv);
          }
        }
      }
    }
  }
  Ans = min(Ans, Res);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> N >> M;
  for (int i = 1; i <= N; ++i) {
  for (int j = 1; j <= M; ++j) {
      char c; cin >> c;
      A[i][j] = c - '0';
    }
  }
  for (int i = 1; i <= M; ++i) {
    V[0].eb(1, i);
    V[2].eb(N, i);
  }
  for (int i = 1; i <= N; ++i) {
    V[1].eb(i, 1);
    V[3].eb(i, M);
  }
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 10; ++j) {
      dijkstra(i, j);
    }
  }
  for (int i = 0; i < 10; ++i) go(i);
  reverse(A + 1, A + 1 + N);
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 10; ++j) {
      dijkstra(i, j);
    }
  }
  for (int i = 0; i < 10; ++i) go(i);
  cout << Ans << '\n';
  return 0;
}
