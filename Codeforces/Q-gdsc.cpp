#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;

int t, point[N];
pair<int, int> a[N];

void solve() {
    int n, m, index = 0, ans = 0;
    cin >> n >> m;
    for(int i = 1, x; i <= n; i++) 
        cin >> x, a[i] = {x, i};
    sort(a + 1, a + n + 1);
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        if(sum + a[i].first <= m) sum += a[i].first, index = i, point[i] = a[i].second - 1;
        else point[i] = a[i].second;
    }
    for(int i = index + 1; i <= n; i++)
        if(point[i] == index + 1 &&  sum- a[index].first + a[i].first <= m) {
            point[index]++;
            point[i]--;
        } 
    for(int i = 1; i <= n; i++) ans += (point[i] > index);
    cout << ans + 1 << '\n';
    for(int i = 1; i <= n; i++) 
        point[i] = 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--) solve();
    return 0;
}