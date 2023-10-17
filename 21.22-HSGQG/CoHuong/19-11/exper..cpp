#include<bits/stdc++.h>
#define simon "exper"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N = 5e3 + 5;

int n;
struct point{
    int x, y, id;
    bool operator < (const point &a) const{
        return x < a.x;
    }
} a[N];
int Log2[N], sp[N][30], ans[N];

int get(int l, int r){
    if ( l > r ) return 0;
    int j = Log2[r-l+1];
    return max(sp[l][j], sp[r-(1<<j)+1][j]);
}

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i].x >> a[i].y, a[i].id = i;
    sort(a + 1, a + 1 + n);

    Log2[1] = 0;
    for (int i = 2; i <= n; i ++)
        Log2[i] = Log2[i/2] + 1;

    for (int i = 1; i <= n; i ++)
        sp[i][0] = a[i].y;

    for (int j = 1; j <= Log2[n]; j ++)
    for (int i = 1; i <= n; i ++)
        sp[i][j] = max(sp[i][j-1], sp[i+(1<<(j-1))][j-1]);

    for (int i = 1; i <= n; i ++){
        for (int j = i - 1; j >= 1; j --){
            int mxh = get(j + 1, i - 1);
            if ( mxh <= a[i].y || mxh <= a[j].y )
                ans[a[i].id] ++;
        }

        for (int j = i + 1; j <= n; j ++){
            int mxh = get(i + 1, j - 1);
            if ( mxh <= a[i].y || mxh <= a[j].y )
                ans[a[i].id] ++;
        }
    }

    for (int i = 1; i <= n; i ++)
        cout << ans[i] << '\n';

    return 0;
}
