#include <bits/stdc++.h>
using namespace std;

const int N = 30;

int t, n, ans, test = 0, g[N];
pair<int, int> f[N];
string s;

int calc(int k) {
    int res = 0;
    for(int i = 0; i <= 25; i++)
        if(i != k) g[i] = f[i].first;
        else g[i] = 0;
    sort(g, g + 26, greater<int>());
    int j = 25;
    for(int i = 0; i <= 25 && i < j; i++) {
        int x  = min(g[i], g[j]);
        g[i] -= x, g[j] -= x;
        res += x;
        if(g[i] != 0) i--;
        if(g[j] == 0) j--;
    }
    if(g[j] > f[k].first) return INT_MAX;
    int check = 0;
    for(int i = 0; i < n / 2; i++) {
        if(s[i] != ('a' + k) && s[n - i - 1] != ('a' + k)) check++;
    }
   // cout << k << ' ' << check << ' ' << res << '\n';
    if(f[k].first <= check) return res + f[k].first;
    else return INT_MAX;
}

int calc_specialcase() {
    int res = 0;
    for(int i = 0; i <= 25; i++)
         g[i] = f[i].first;
  //  cout << f[2].first << '\n';
    sort(f , f + 26, greater<pair<int,int>>());
 //   cout << f[0].first << '\n';
    int j = 25;
    for(int i = 0; i <= 25 && i < j; i++) {
        int x  = min(f[i].first, f[j].first);
       // cout << i << ' ' << j << ' ' << f[i].first << ' ' << f[j].first << ' ' << x << '\n';
        f[i].first -= x, f[j].first -= x;
        res += x;
        if(f[i].first != 0) i--;
        if(f[j].first == 0) j--;
    }
    int check = 0;
    for(int i = 0; i < n / 2; i++) 
        if(s[i] != ('a' + j) && s[n - i - 1] != ('a' + j)) check++;
 //   cout << f[j].first << ' ' << check << ' ' << res << '\n';
    check -= (g[f[j].second] - f[j].first);
    if(f[j].first <= check) return res + f[j].first; 
    else return INT_MAX;
}

void solve() {
    ans = INT_MAX;
    for(int i = 0; i <= 25; i++)
        f[i] = {0, i};
    cin >> n >> s;
    if(n % 2 == 1) {
        cout << -1 << '\n';
        return;
    }
    for(int i = 0; i < n / 2; i++) {
        if(s[i] == s[n - i - 1]) 
            f[s[i] - 'a'].first++;
    }
    for(int i = 0; i <= 25; i++) 
        ans = min(ans, calc(i));
    ans = min(ans, calc_specialcase());
    cout << ((ans == INT_MAX) ? -1 : ans) << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--) {
       //test++;
        solve();
    }
    return 0;
}
