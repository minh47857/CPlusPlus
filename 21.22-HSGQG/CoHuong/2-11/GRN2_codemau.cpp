#include <bits/stdc++.h>
#define TASK "GRN2"

using namespace std;

#define int long long
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int N = 1010;
const int MOD = 111539786;

int n;
int gt[2*N];
map < int, int > flag, mp, cnt, tmp;

void add(int &a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
}
main() {
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);

    fast;

    cin >> n;
    n *= 2;
    gt[0] = 1;
    for(int i = 1; i <= n; ++i)
        gt[i] = (gt[i-1] * i) % MOD;
    vector < int > a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i], cnt[a[i]] ++;
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());
    n = a.size();
    for(int i = 0; i < n; ++i)
        flag[a[i]] = true, tmp[a[i]] = cnt[a[i]];
    int rez = 0;
    for(int i = 0; i < n; ++i) {
        int dis = a[i] - a[0], up = 1;
        bool OK = true;
        for(int j = 0; j < n; ++j)
            if (!mp[a[j]]) {
                if (!dis) {
                    if (cnt[a[j]] & 1) {
                        OK = false;
                        break;
                    }
                    up = (up * gt[cnt[a[j]]/2]) % MOD;
                } else {
                    if (flag[a[j]+dis] && !mp[a[j]+dis] && cnt[a[j]+dis] == cnt[a[j]]) {
                        mp[a[j]] = mp[a[j]+dis] = true;
                        up = (up * gt[cnt[a[j]]]) % MOD;
                    } else {
                        OK = false;
                        break;
                    }
                }
            }
        for(int j = 0; j < n; ++j)
            mp[a[j]] = false;
        //cout << dis << ' ' << up << '\n';
        if (OK) add(rez, up);
    }
    cout << rez;
}
