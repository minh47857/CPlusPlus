#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <math.h>
#include <bitset>

using namespace std;

#define taskname "MINE"
#define LL long long
#define uLL unsigned long long
#define FOR(i, l, r) for (int i = l; i <= r; ++i)
#define REP(i, l, r) for (int i = l; i < r; ++i)
#define FORD(i, r, l) for (int i = r; i >= l; --i)
#define REPD(i, r, l) for (int i = r; i > l; --i)
#define pi pair<int, int>
#define pii pair<int, pi>
#define mp make_pair
#define fi first
#define se second
#define pb push_back

const int maxN = 4e5 + 11;
const LL MOD = 1e6 + 3;

int tcases = 1;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

int n, m;
int a[maxN];
LL g[maxN], h[maxN], p[maxN], inv[MOD], C[maxN], F[maxN];

void init() {
    h[0] = 1;
    FOR(i, 1, 2 * n) h[i] = (h[i - 1] * i) % MOD;
    //
    inv[1] = 1;
    REP(i, 2, MOD) { inv[i] = (MOD - (MOD / i * inv[MOD % i]) % MOD) % MOD; }
    C[0] = 1;
    FOR(i, 1, n) { C[i] = ((h[i * 2] * inv[h[i]]) % MOD * inv[h[i + 1]]) % MOD , cout << i << ' ' << C[i] << ' ' << h[i * 2] << endl; }
}
void abcxyz() {
    // dp
    F[0] = 1;
    for (int i = 2; i <= 2 * n; i += 2) {
        for (int j = 0; j < i; j += 2) {
            if (a[i] - a[j + 1] <= m) {
                F[i] += F[j] * C[(i - j - 2) / 2];
                F[i] %= MOD;
            }
        }
    }
    cout << F[2 * n];
}
void testcase() {
    scanf("%d %d", &n, &m);
    init();
    FOR(i, 1, 2 * n) scanf("%d", &a[i]);
    if (n <= 2000)
        abcxyz();
    else
        printf("%lli\n", C[n]);
}

int main() {
    // cin >> tcases;

    FOR(i, 1, tcases) testcase();

    return 0;
}
