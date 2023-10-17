#include<bits/stdc++.h>
#define ld double
using namespace std;
const int N = 2e5 + 5;
const int oo = 1e6 + 5;
const ld eps = 1e-8;

void file() {
	freopen("parkour.in" , "r" , stdin);
	freopen("parkour.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int t, n, m , h[N];
ld maxU[N], maxD[N], low[N], up[N];

void in(){
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) cin >> h[i];
    for (int i = 1; i <= n; i++) maxD[i] = maxU[i] = 1.0*oo;
    for (int i = 1; i <= m; i ++) {
        int a, b, u, d;
        cin >> a >> b >> u >> d;
        if ( a > b ) swap(u, d), swap(a, b);
        for (int j = a + 1; j <= b; j ++) {
            maxD[j] = min(maxD[j], (ld) d);
            maxU[j] = min(maxU[j], (ld) u);
        }
    }
}

bool cut(ld l, ld r, ld u, ld v){
    if ( r < u || l > v ) return false;
    return true;
}

bool check(ld t){
    low[1] = h[1]*1.0 - t; up[1] = h[1]*1.0 + t;

    for (int i = 2; i <= n; i ++){
        ld nl = h[i]*1.0 - t, nu = h[i]*1.0 + t;
        ld curl = low[i-1] - maxD[i], curu = up[i-1] + maxU[i];
        if ( !cut(nl, nu, curl, curu) ) return false;
        low[i] = max(nl, curl); up[i] = min(nu, curu);
    }

    return true;
}

void solve(){
    ld d = 0.0, c = 1000000.0, ans;

    while ( d <= c ){
        ld mid = ( d + c ) / 2;
        if ( check(mid) ){
            ans = mid;
            c = mid - eps;
        }
        else d = mid + eps;
    }

    cout << fixed << setprecision(6) << ans << '\n';
}

int main(){
//	file();
    cin >> t;
    while ( t-- ){
        in();
        solve();
    }
    return 0;
}

