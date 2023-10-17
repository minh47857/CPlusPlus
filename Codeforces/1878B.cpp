#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, a[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    a[1] = 1, a[2] = 3;
    for(int i = 3; i <= N - 5; i++)
    {
        a[i] = a[i - 1] + 1;
        while(3 * a[i] % (a[i - 1] + a[i - 2]) == 0) a[i]++;
    }
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; i++) 
            cout << a[i] << ' ';
        cout << '\n';
    }
    return 0;
}