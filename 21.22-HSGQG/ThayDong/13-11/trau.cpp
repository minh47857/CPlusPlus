#include<bits/stdc++.h>
#define ll long long
#define pi pair<int, ll>
#define fi first
#define se second
using namespace std;
const int N = 5e5 + 5;

int k, h, n;
ll p[N];
map<ll, int> d;
ll ans = 0;

int getPar(int x){
    return ( x + k - 2 ) / k;
}

int Tang(int x){
    int res = 0;
    while ( getPar(x) != 1 ){
        x = getPar(x);
        res ++;
    }
    return res + 1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> k >> h >> n;

    priority_queue<pi> heap;

    for (int i = 1; i <= n; i ++){
        int x; cin >> x;
        heap.push({Tang(x), x});
        d[x] = 1;
    }

    while ( heap.size() > 1 ){
        int u = heap.top().se, tangu = heap.top().fi;
        heap.pop();
        int pu = getPar(u);
        ans ++;
        if ( !d[pu] ) heap.push({tangu-1, pu}), d[pu] = 1;
    }

    cout << ans;

    return 0;
}
