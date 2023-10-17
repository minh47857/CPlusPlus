#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e4 + 5;
ll n, a[N], cnt[N], Max, t;
void files()
{
   
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
void sol() 
{
    if(n < 4)
    {
        cout << 0 << '\n'; return;
    }

    memset(cnt, 0, sizeof cnt);
    Max = 0;

    for (int i = 1; i <= n; ++i) 
    {
        cin >> a[i];
        int x = a[i]; Max = max(Max, a[i]);
        for (int j = 1; j <= sqrt(x); ++j)
            if(x % j == 0) {
                ++cnt[j];
                if(j != x / j) ++cnt[x / j];
            }
    }

    ll res = 0;
    for (int i = 2; i <= Max; ++i) {
        int gc = 0, x = i;
        bool flag = false;
        for (int j = 2; j <= sqrt(x); ++j) {
            int cnt = 0;
            while(x % j == 0) x /= j, ++cnt;
            if(cnt == 1) ++gc;
            else if (cnt >= 2) {
                flag = true; break;
            }
        }
        if (flag) continue;
        if(x != 1) ++gc;

        ll s = 1;
        for (int j = 0; j < 4; ++j)
            s *= (cnt[i] - j);
        s /= 24;

        if(gc % 2) res += s;
        else res -= s;
    }

    cout << (ll)((n * (n - 1) * (n - 2) * (n - 3) / 24) - res)  << '\n';
}

int main() 
{
    files();
    while(cin >> n)
        sol();
}
