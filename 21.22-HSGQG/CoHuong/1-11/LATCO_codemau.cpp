#include <bits/stdc++.h>
#define TASK "LATCO"

using namespace std;

#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int inf = (int) 1e9 + 7;

const int N = 110;

int n, m, rez = inf;
int a[2*N], tmp[2*N];
string s, t;

int get(int x, int k) { return (x >> k) & 1; }
void solve(string &s) {
    for(int i = 0; i < n; ++i)
       tmp[i] = (s[i] != t[i]);
    for(int i = 0; i < (1 << m); ++i) {
        int ans = 0;
        for(int j = 0; j < n; ++j) a[j] = tmp[j];
        for(int bit = 0; bit < m; ++bit)
            if (get(i, bit)) {
                for(int j = 0; j < m; ++j)
                    a[(bit+j) % n] ^= 1;
                ans ++;
            }
        for(int bit = m; bit < n; ++bit)
            if (a[bit]) {
                for(int j = 0; j < m; ++j)
                    a[(bit+j) % n] ^= 1;
                ans ++;
            }
        bool OK = true;
        for(int j = 0; j < n; ++j)
            if (a[j]) OK = false;
        if (OK) rez = min(rez, ans);
    }
}
int main() {
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);

    fast;

    cin >> n >> m;
    cin >> s >> t;
    for(int i = 0; i < n; ++i) {
        string tmp1 = s.substr(i, n-i) + s.substr(0, i);
        solve(tmp1);
    }
    cout << rez ;
}
