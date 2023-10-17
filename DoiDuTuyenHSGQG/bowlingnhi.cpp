#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5+5;
int t, n, i, j, k, l, r;
ll a[N], s[N], f[N][2], ans, tmp;
bool check;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    if( fopen("input.inp", "r") ) freopen("input.inp", "r", stdin);

    cin >> t;

    while( t-- )
    {
        cin >> n >> k;
        for(i=1; i<=n; i++) cin >> a[i];

        for(i=1; i<=n; i++) s[i] = s[i-1] + a[i];

        tmp = LLONG_MIN;
        for(i=1; i<=n; i++)
        {
            r = min(n, i+k);
            l = max(1, i-k);
            tmp = max( tmp, s[r] - s[l-1] );
        }

        memset(f, -0x3f, sizeof(f));
        ans = 0; check = false;
        f[0][0] = f[0][1] = 0;

        for(i=1; i<=n; i++)
        {
            r = min(n, i+k);
            l = max(1, i-k);
            f[i][0] = max( f[i-1][0], f[i-1][1] );
            if( s[r] - s[l-1] >= 0)
            {
                check = true;
                f[i][1] = s[r] - s[l-1];
            }

            for(j=1; j<i; j++)
            {
                l = max( min(j+k, n), i-k-1 );
                f[i][1] = max( f[i][1], f[j][1] + s[r] - s[l] );
            }
        }

        if( check ) cout << max(f[n][0], f[n][1]) << '\n';
        else cout << tmp << '\n';
    }

    return 0;
}
