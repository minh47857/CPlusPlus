#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;
const ll oo = 1e15;

int n, k;
ll a[N];

namespace sub3{
    ll f[N][105];

    void solve(){
        for (int i = 0; i <= n; i ++)
        for (int j = 0; j <= k; j ++)
            f[i][j] = oo;

        f[0][0] = 0;
        for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= k; j ++){
            ll mx = a[i];
            for (int t = i - 1; t >= 0; t --){
                f[i][j] = min(f[i][j], f[t][j-1] + mx);
                mx = max(mx, a[t]);
            }
        }

        cout << f[n][k];
    }
}

/*
namespace sub4{
    struct node{
        ll val, cost, lazy;
    } st[4*N];
    ll f[N][105];

    void up1(int id, int l, int r, int u, ll v){
        if ( l > u || r < u ) return;
        if ( l == r ){
            st[id].val = v;
            return;
        }
        int mid = ( l + r ) / 2;
        up1(id * 2, l, mid, u, v);
        up1(id * 2 + 1, mid + 1, r, u, v);
        if ( st[id*2].val + st[id*2].cost > st[id*2+1].val + st[id*2+1].cost )
            st[id].val = st[id*2+1].val + st[id*2+1].cost;
        else st[id].val = st[id*2].val + st[id*2].cost;
    }

    void down(int id){
        ll t = st[id].lazy; st[id].lazy = 0;
        cout << "   down " << id << " : " << st[id].lazy << '\n';
        st[id*2].lazy = max(st[id*2].lazy, t); st[id*2].cost = max(st[id*2].cost, t);
        st[id*2+1].lazy = max(st[id*2+1].lazy, t); st[id*2+1].cost = max(st[id*2+1].cost, t);

    }

    void up2(int id, int l, int r, int u, int v, ll val){
        if ( l > v || r < u ) return;
        if ( u <= l && r <= v ){
            st[id].cost = max(st[id].cost, val);
            st[id].lazy = max(st[id].lazy, val);
            cout << "   -> " << l << " " << r << ' ' << st[id].cost << '\n';
            return;
        }

        down(id);

        int mid = ( l + r ) / 2;
        up2(id * 2, l, mid, u, v, val);
        up2(id * 2 + 1, mid + 1, r, u, v, val);

        if ( st[id*2].val + st[id*2].cost > st[id*2+1].val + st[id*2+1].cost )
            st[id].val = st[id*2+1].val + st[id*2+1].cost;
        else st[id].val = st[id*2].val + st[id*2].cost;
    }

    ll get(int id, int l, int r, int u, int v){
        if ( l > v || r < u ) return oo;
        down(id);
        if ( u <= l && r <= v ) return st[id].val + st[id].cost;
        int mid = ( l + r ) / 2;
        return min(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
    }

    void solve(){
        for (int i = 0; i <= n; i ++)
        for (int j = 0; j <= k; j ++)
            f[i][j] = oo;

        f[0][1] = 0;
        for (int i = 1; i <= n; i ++)
            f[i][1] = max(f[i-1][1], a[i]);

        for (int i = 1; i <= n; i ++)
            up1(1, 1, n, i, f[i][1]);

        for (int j = 2; j <= k; j ++){
            for (int i = 1; i <= 4 * n; i ++)
                st[i].lazy = st[i].cost = 0;

            for (int i = 2; i <= n; i ++){
                up2(1, 1, n, 1, i - 1, a[i]);
                f[i][j] = get(1, 1, n, 1, i-1);
                cout << i << ' ' << j << ' ' << f[i][j] << '\n';
            }

            for (int i = 1; i <= n; i ++)
                up1(1, 1, n, i, f[i][j]);
        }

        cout << f[n][k];
    }
}
*/

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("block.inp", "r", stdin);
    freopen("block.out", "w", stdout);

    cin >> n >> k;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    //if ( n <= 100 ) 
	
	sub3::solve();
//    else
//        sub4::solve();

    return 0;
}
