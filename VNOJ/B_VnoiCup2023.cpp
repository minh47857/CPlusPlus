#include<bits/stdc++.h>
using namespace std;
int main()  {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> p[i];
    for(int i = 1; i <= n; i++) {
        cin >> q[i];
        mark[p[i]] = q[i];
    }
    if(CheckDiff(p) || CheckDiff(q)) {
        cout << "NO";
        return 0;
    }
    for(int i = 1; i <= n; i++) c += (mark[i]);
    for(int i = 1; i <= n; i++) {
        if(mark[i]) {
            t++
            a[i] = t, b[mark[i]] = c - t;
        }
    }
}