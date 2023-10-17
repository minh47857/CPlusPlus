#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200 + 10;
const int MOD = (int)(1e9) + 7;

int n;
int a[MAXN];
long long f[MAXN][MAXN];
int amin[MAXN][MAXN][2], amax[MAXN][MAXN][2];
long long C[MAXN][MAXN];

int brute_force() {
    vector<int> tmp_a(n + 1);
    for(int i = 1; i <= n; ++i) tmp_a[i] = a[i];
    int res = 0;
    vector<int> b(n - 1);
    for(int i = 0; i < n - 1; ++i) b[i] = i + 1;

    do {
        for(int i = 1; i <= n; ++i) a[i] = tmp_a[i];
        for(int i = 0; i < n - 1; ++i) swap(a[b[i]], a[b[i] + 1]);

        bool ok = true;
        for(int i = 1; i <= n; ++i)
            if (a[i] != i) {
                ok = false; break;
            }

        if (ok) res++;
    }
    while (next_permutation(b.begin(), b.end()));

    return res;
}

int combi(int k, int n) {
    if ((k < 0) || (k > n)) return 0;
    if (k == 0) return 1;
    if (k == n) return 1;
    if (C[k][n] != -1) return C[k][n];
    C[k][n] = (combi(k, n - 1) + combi(k - 1, n - 1)) % MOD;
    return C[k][n];
}

int main() {
    freopen("count2.in", "r", stdin);
    freopen("count2.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];

    for(int i = 0; i <= n; ++i)
        for(int j = 0; j <= n; ++j)
            C[i][j] = -1;

    for(int i = n; i >= 1; --i) {
        f[i][i] = 1;
        amin[i][i][0] = a[i]; amin[i][i][1] = n + 1;
        amax[i][i][0] = a[i]; amax[i][i][1] = -1;
        for(int j = i + 1; j <= n; ++j) {
            //update amin, amax
            amin[i][j][0] = amin[i][j - 1][0]; amin[i][j][1] = amin[i][j - 1][1];
            if (a[j] < amin[i][j][0]) {
                amin[i][j][1] = amin[i][j][0];
                amin[i][j][0] = a[j];
            }
            else if (a[j] < amin[i][j][1]) {
                amin[i][j][1] = a[j];
            }

            amax[i][j][0] = amax[i][j - 1][0]; amax[i][j][1] = amax[i][j - 1][1];
            if (a[j] > amax[i][j][0]) {
                amax[i][j][1] = amax[i][j][0];
                amax[i][j][0] = a[j];
            }
            else if (a[j] > amax[i][j][1]) {
                amax[i][j][1] = a[j];
            }

            f[i][j] = 0;
            for(int k = i; k < j; ++k) {
                if ((amax[i][k][1] < amin[k + 1][j][0]) && (amin[k + 1][j][0] < amax[i][k][0]) && (amax[i][k][0] < amin[k + 1][j][1])) {
                    int inc = (1LL * combi(k - i, k - i + j - k - 1) * ((f[i][k] * f[k + 1][j]) % MOD)) % MOD;
                    f[i][j] = (f[i][j] + inc) % MOD;
                }
            }
        }
    }

    cout << f[1][n] << "\n";
    /*if (n <= 10)
        cout << brute_force() << "\n";
    else cout << "-1\n";*/
}
