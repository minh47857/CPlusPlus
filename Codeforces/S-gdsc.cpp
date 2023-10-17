#include<bits/stdc++.h>
using namespace std;

const int N = 30;

int t, n, ans = 0, maxchar, cnt[N], f[N];
string s;

void solve() {
    memset(f, 0, sizeof(f));
    memset(cnt, 0, sizeof(cnt));
    ans = 0;
    maxchar = 0;
    cin >> n >> s;
    for(int i = 0; i < n; i++) 
        cnt[s[i] - 'a']++;
    for(int i = 0; i < n / 2; i++) {
        if(s[i] == s[n - i - 1]) f[s[i] - 'a']++;
        maxchar = max(f[s[i] - 'a'], maxchar);
    }
    if(n % 2 == 1) {
        cout << -1 << '\n';
        return;
    }
    for(int i = 0; i <= 25; i++) {
        if(cnt[i] > n / 2) {
            cout << -1 << '\n';
            return;
        }
        ans += f[i];
    }
    cout << max((ans + 1)/ 2, maxchar) << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--) {
        solve();
    }
}