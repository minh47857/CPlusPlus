#include<bits/stdc++.h>
using namespace std;

#define maxn 3010

int n;
int a[maxn];
int b[maxn];
int c[maxn];
int f[maxn][3];

int main()
{
    freopen("feed.inp", "r", stdin);
    freopen("feed.out", "w", stdout);
    
    cin >> n;
    for (int j = 1; j <= n; ++ j)
        cin >> a[j];
    for (int j = 1; j <= n; ++ j)
        cin >> b[j];
    for (int j = 1; j <= n; ++ j)
        cin >> c[j];
    f[n][0]=a[n];
    f[n][1]=b[n];
    
    
    
    
    for (int i = n-1; i >= 1; -- i)
    {
        f[i][0] = max(f[i + 1][1] + a[i], f[i + 1][0] + b[i]);
        f[i][1] = max(f[i + 1][1] + b[i], f[i + 1][0] + c[i]);
    }
    cout << f[1][0];
}

