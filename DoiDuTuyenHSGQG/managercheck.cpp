#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=103;
const int K=1e4+3;
const ll inf = INT_MAX;

int n, i, j, l, r, k, t, cs[N], csj[N], m1, m2, tmp;
ll a[N], f[3][N][K], ans;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> l >> r >> k;
    for(i=1; i<=n; i++) cin >> a[i];

    m1=0;
    for(i=1; i<l; i++) cs[++m1] = i;
    for(i=r+1; i<=n; i++) cs[++m1] = i;

    m2 = 0; ans=0;
    for(i=l; i<=r; i++)
    {
        csj[++m2] = i;
        ans += a[i];
    }

    for(j=0; j<=n; j++)
        for(t=0; t<=k; t++)
            f[0][j][t] = f[1][j][t] = inf;

    f[0][0][0] = f[0][1][0] = f[1][0][0] = ans;
    for(i=1; i<=n; i++) f[0][i][0] = ans;
    for(i=1; i<=m1; i++)
        for(j=1; j<=m2; j++)
            for(t=0; t<=k; t++)
            {
                f[i%2][j][t] = min( f[1-i%2][j][t], f[i%2][j-1][t] );
                tmp = t - abs(cs[i]-csj[j]);
                if( tmp >=0 && f[1-i%2][j-1][tmp]!=inf ) f[i%2][j][t] = min( f[i%2][j][t], f[1-i%2][j-1][tmp] - (a[csj[j]] - a[cs[i]]) );
                ans = min(ans, f[i%2][j][t]);
            }

    cout << ans;
    return 0;
}

