#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int t, n, a[N], f[N];

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    f[0] = 1;
    for(int i = 1; i <= n; i++) {
        if(i > a[i]) f[i] = max(f[i], f[i - a[i] - 1]);
        if(i + a[i] <= n) f[i + a[i]] = max(f[i + a[i]], f[i - 1]);
    }
    cout << ((f[n]) ? "YES\n" : "NO\n");
    for(int i = 1; i <= n ; i++) f[i] = 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--) solve();
    return 0;
}