#include <bits/stdc++.h>
#define ii pair<int, int>
#define X first
#define Y second
const int N = 40;
const int oo = trunc(1e9);
using namespace std;
int dx[] = {0, -1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {0, -1, 0, 1, 1, 1, 0, -1, -1};
vector<ii> v;
int a[N][N], n, tt, tx, ty, s, t;

void AddVertex(int x, int y) {
    int xx, yy;
    for(int i=0; i<=8; i++) {
        xx = x + dx[i]; yy = y + dy[i];
        v.push_back(ii(xx, yy));
        if (xx == 0 && yy == 0) s = v.size() - 1;
        if (xx == tx && yy == ty) t = v.size() - 1;
    }
}

void InitAdjacencyMatrix() {
    n = v.size(); int x, y, p, q;
    for(int i=0; i<n; i++)
    for(int j=0; j<n; j++) {
        a[i][j] = oo;
        x = v[i].X; y = v[i].Y;
        p = v[j].X; q = v[j].Y;
        if (x == p) {
            if ((x & 1) && y >= q)
                a[i][j] = min(a[i][j], y - q);
            if (!(x & 1) && y <= q)
                a[i][j] = min(a[i][j], q - y);
        }
        if (y == q) {
            if ((y & 1) && x >= p)
                a[i][j] = min(a[i][j], x - p);
            if (!(y & 1) && x <= p)
                a[i][j] = min(a[i][j], p - x);
        }
    }
}

void Floyd() {
    int i, j, k;
    for(k=0; k<n; k++)
    for(i=0; i<n; i++)
    for(j=0; j<n; j++)
    a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
}

int main()
{
        freopen("pogrid.inp", "r", stdin), freopen("pogrid.out", "w", stdout);
    scanf("%d\n", &tt);
    while (tt--) {
        scanf("%d %d\n", &tx, &ty);
        v.clear();
        AddVertex(0, 0);
        AddVertex(0, ty);
        AddVertex(tx, 0);
        AddVertex(tx, ty);
        InitAdjacencyMatrix();
        Floyd();
        printf("%d\n", a[s][t]);
    }
    return 0;
}
