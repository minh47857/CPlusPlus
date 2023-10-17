#include<functional>
#include<algorithm>
#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

const int N = 100000, INF = 1e9 + 7;
int a[N], lis[N], lds[N], n;

void calcLIS(int a[], int n, int res[]) {
    vector<int> last (n, INF);
    for(int i = 0; i < n; ++i) {
        res[i] = lower_bound(last.begin(), last.end(), a[i]) - last.begin();
        last[res[i]] = min(last[res[i]], a[i]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    reverse(a, a + n);
    calcLIS(a, n, lis);
    transform(a, a + n, a, negate<int>());
    calcLIS(a, n, lds);
    int res = 0;
    for(int i = 0; i < n; ++i)
        cout << lis[i]  << ' ' <<  lds[i] << endl;
    cout << res << endl;
    return 0;
}
