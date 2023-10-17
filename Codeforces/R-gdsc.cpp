#include<bits/stdc++.h>
using namespace std;

int t, num[] = {0, 1, 2, 3, 5, 6, 7, 8, 9};

long long k;

void solve() {
    string s;
    cin >> k;
    while(k) {
        int x = k % 9;
        k = k / 9;
        s = char(num[x] + '0') + s;
    }
    cout << s << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}