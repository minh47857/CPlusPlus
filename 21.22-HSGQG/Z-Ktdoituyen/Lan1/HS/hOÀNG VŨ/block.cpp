#include <bits/stdc++.h>

using namespace std;

#define il i * 2
#define ir i * 2 + 1

using ii = pair<long long, int>;

const int N = 100005;

int a[N], n, k, lo, hi;
long long dp[2][N], seg[N * 4];
long long tag[N * 4];

void build(int i, int l, int r) {
    seg[i] = 1e18;
    if (l != r) {
        int m = (l + r) / 2;
        build(il, l, m);
        build(ir, m + 1, r);
    }
}

void apply(int i, long long v) {
    seg[i] += v; tag[i] += v;
}

void push(int i) {
    apply(il, tag[i]);
    apply(ir, tag[i]); tag[i] = 0;
}

void add(int i, int l, int r, int v) {
    if (l >= lo && r <= hi)
        return apply(i, v);
    int m = (l + r) / 2; push(i);
    if (m >= lo) add(il, l, m, v);
    if (m < hi) add(ir, m + 1, r, v);
    seg[i] = min(seg[il], seg[ir]);
}

void put(int i, int l, int r, long long v) {
    if (l == r) {
        seg[i] = v; return;
    }
    int m = (l + r) / 2; push(i);
    if (m >= lo) put(il, l, m, v);
    else put(ir, m + 1, r, v);
    seg[i] = min(seg[il], seg[ir]);
}

int main() {
    freopen("block.inp", "r", stdin);
    freopen("block.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    a[0] = INT_MAX;
    memset(dp[0], 0x3f, sizeof dp[0]);
    dp[0][0] = 0;
    for (int i = 1; i <= k; i++) {
        memset(dp[i & 1], 0x3f, sizeof dp[i & 1]);
        build(1, 1, n);
        stack<int> stk; stk.push(0);
        for (int j = 1; j <= n; j++) {
            while (a[j] > a[stk.top()]) {
                hi = stk.top(); stk.pop();
                lo = stk.top() + 1;
                add(1, 1, n, a[j] - a[hi]);
            }
            lo = j; stk.push(j);
            put(1, 1, n, dp[~i & 1][j - 1] + a[j]);
            dp[i & 1][j] = seg[1];
        }
    }
    cout << dp[k & 1][n];
}
