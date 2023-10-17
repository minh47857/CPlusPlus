#include<bits/stdc++.h>
using namespace std;
int const MOD = 123456789;

int t, ans, n, m, k, f[2][65537][150];

int get_bit(int i, int x) {
    if(i >= m || i < 0) return 0;
    return (x >> i) & 1;
}

void update(int i, int x, int k, int pre_x) {
   // cout << "x";
   // cout << i << ' ' << x << ' ' << k << ' ' << pre_x << '\n';
    if(i == -1) {
        f[1 - t%2][x][k + __builtin_popcount(x)] = (f[1 - t%2][x][k + __builtin_popcount(x)] + f[t%2][pre_x][k]) % MOD;
        return;
    }
    if(!get_bit(i - 1, pre_x) && !get_bit(i + 1, pre_x) && !get_bit(i, pre_x) && !(x & 1))
        update(i - 1, (x << 1) | 1, k, pre_x);
    update(i - 1, x << 1, k, pre_x);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m >> k;
    if(n < m) swap(n, m);
     if(k > m * n / 2 + 1) {
        cout << 0;
        return 0;
     }
    f[0][0][0] = 1;
    for(; t < n; t++) {
        for(int mask = 0; mask < (1 << m); mask++) 
            for(int s = 0; s <= m * n /2 + 1; s++) {
                    if(f[t % 2][mask][s]) {
                        if(!get_bit(m - 1 , mask) && !get_bit(m - 2, mask)) update(m - 2, 1, s, mask);
                        update(m - 2, 0, s, mask);
                    }
                    f[t%2][mask][s] = 0;
                }
    }
    for(int mask = 0; mask < (1 << m); mask++)
        ans = (ans + f[n % 2][mask][k]) % MOD;
    cout << ans;
    return 0;
}