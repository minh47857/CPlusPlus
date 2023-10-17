#include <bits/stdc++.h>
#define BIT(x,k) ((x) >> k & 1)
using namespace std;

const int N = 21;
int f[1 << N];
int n, b, s[N][N];
pair <int, int> bonus[N];

int cntBit(int n) {
    int cnt = 0;
    for (int i = 0; i < 20; i++)
        if (BIT(n, i)) cnt++;
    return cnt;
}

int main() {
   // freopen ("assign.inp", "r", stdin);
  //  freopen ("assign.out", "w", stdout);

    cin >> n >> b;
    for (int i = 1; i <= b; i++) {
        int k, p, a;
        cin >> k >> p >> a;
        bonus[k] = {p, a};
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> s[i][j];

    for (int mask = 0; mask < (1 << n); mask++) {
        int numBit = cntBit(mask);
        for (int i = 0; i < n; i++) if (!BIT(mask, i)) {
            int newMask = mask | (1 << i);
            int point = f[mask] + s[i][numBit];
            if (point >= bonus[numBit+1].first)
                point += bonus[numBit+1].second;
                cout <<point<<endl;
            f[newMask] = max(f[newMask], point);
        }
    }

    cout << f[(1 << n) - 1] << '\n';

    return 0;
}
