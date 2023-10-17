#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl '\n'
#define bit(s, i) (s & (1<<i)

using namespace std;

const int inf = 2e9;
const int mod = 1e9 + 7;

typedef pair < int, int > ii;

int n, b[200];

bool checksuf(int l, int r, long long x) {
    vector < int > a;
    while(x) {
        a.pb(x % 10);
        x /= 10;
    }
    reverse(a.begin(), a.end());
    for(int i=l;i<=min(r, l + int(a.size()) - 1);++i) {
        if(b[i] != a[i - l]) return 0;
    }
    return 1;
}

bool checkpre(int l, int r, long long x) {
    vector < int > a;
    while(x) {
        a.pb(x % 10);
        x /= 10;
    }

    for(int i=r;i>=max(l, r - int(a.size())
                        + 1);--i) {
        if(b[i] != a[r - i]) return 0;
    }
    return 1;
}

void solve(int num) {
    for(int i=1;i<=n;++i) {
        long long cur = 0, loz;
        for(int j=1;j<=min(n, i + num - 1)) {
            cur = cur * 10 + b[i];
        }
        int p = min(n, i + num - 1) + 1;
        loz = cur +
        while(p <= n) {
            p
        }
    }
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("table.inp", "r", stdin);
    freopen("table.out", "w", stdout);

    cin >> n;
    for(int i=1;i<=n;++i) {
        char x;
        cin >> x;
        b[i] = int(x - '0');
    }

    long long ans;
    for(int i=1;i<=15;++i) if(solve(i) != -1) ans = solve(i);
}

