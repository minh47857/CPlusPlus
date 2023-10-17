#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000 + 10;
const int INF = (int)(1e9) + 10;

int a[MAXN];
int n;
int f[MAXN][MAXN];
int decision[MAXN][MAXN];

int calc(int i, int j) {
    if ((i > n) && (j > n)) return 0;
    if (i > n) return a[j];
    if (i == n) return max(a[i], a[j]);
    
    if (f[i][j] != INF) return f[i][j];
    
    if (f[i][j] > calc(i + 2, i + 1) + max(a[j], a[i])) {
        f[i][j] = calc(i + 2, i + 1) + max(a[j], a[i]);
        decision[i][j] = 1;
    }
    if (f[i][j] > calc(i + 2, i) + max(a[j], a[i + 1])) {
        f[i][j] = calc(i + 2, i) + max(a[j], a[i + 1]);
        decision[i][j] = 2;
    }
    if (f[i][j] > calc(i + 2, j) + max(a[i], a[i + 1])) {
        f[i][j] = calc(i + 2, j) + max(a[i], a[i + 1]);
        decision[i][j] = 3;
    }

    return f[i][j];
}

void trace(int i, int j) {
    if ((i > n) && (j > n)) return;
    if (i > n) {
        cout << j << "\n"; return;
    }
    if (i == n) {
        cout << i << " " << j << "\n"; return;
    }
    
    
    if (decision[i][j] == 1) {
        cout << j << " " << i << "\n";
        trace(i + 2, i + 1);
    }
    if (decision[i][j] == 2) {
        cout << j << " " << i + 1 << "\n";
        trace(i + 2, i);
    }
    if (decision[i][j] == 3) {
        cout << i << " " << i + 1<< "\n";
        trace(i + 2, j);
    }
}

int main() {
    freopen("cashier.in", "r", stdin);
    freopen("cashier.out", "w", stdout);
    
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
        
    for(int i = 0; i <= n; ++i) 
        for(int j = 0; j <= n; ++j) f[i][j] = INF;
        
    cout << calc(2, 1) << "\n";
    //trace(2, 1);
}
