#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<ll,ll>
#define fi first
#define se second
#define pb push_back

const ll N = 200005 , MOD = 1e9 + 7 , inf = 1e15;

void file() {
//    freopen(".inp" , "r" , stdin);
//    freopen(".out" , "w" , stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll ans = 0 , n , a[N] , sp[N][20] , Log[N] , st[N] , ed[N];

void DequeMax() {
    deque<ll> dq;
    for(ll i = 1 ; i <= n ; i++) {
        while(dq.size() && a[i] >= a[dq.back()]) dq.pop_back();
        if(dq.size()) st[i] = dq.back() + 1;
        else st[i] = 1;
        dq.pb(i);
    }
    dq.clear();
    for(ll i = n ; i >= 1 ; i--) {
        while(dq.size() && a[i] > a[dq.back()]) dq.pop_back();
        if(dq.size()) ed[i] = dq.back() - 1;
        else ed[i] = n;
        dq.pb(i);
    }
}

void BuildGcd() {
    Log[1] = 0;
    for(ll i = 2 ; i <= n ; i++) Log[i] = Log[i/2] + 1;
    for(ll i = 1 ; i <= n ; i++) sp[i][0] = a[i];
        
    for(ll j = 1 ; j <= Log[n] ; j++) 
      for(ll i = 1 ; i + (1 << j) - 1 <= n ; i++) 
        sp[i][j] = __gcd(sp[i][j - 1] , sp[i + (1 << (j - 1))][j - 1]) ;// cout << sp[i][j] << endl;
}

ll Get(ll l , ll r) {
    ll len = Log[r - l + 1];
    return __gcd(sp[l][len] , sp[r - (1 << len) + 1][len]);
}

void Solve() {
    for(ll i = 1 ; i <= n ; i++) {
        vector<ll> R , L;
        L.pb(i);
        R.pb(i);
        
        while(R[R.size() - 1] != ed[i]) {
            ll x = Get(i , R[R.size() - 1] + 1);
            ll d = R[R.size() - 1] + 1 , c = ed[i] , g , kq;
            while(d <= c) {
                g = (d + c) / 2;
                if(Get(i , g) == x) kq = g , d = g + 1;
                else c = g - 1;
            }
            R.pb(kq);
        }
        
        while(L[L.size() - 1] != st[i]) {
            ll x = Get(L[L.size() - 1] - 1 , i);
            ll d = st[i] , c = L[L.size() - 1] - 1 , g , kq;
            while(d <= c) {
                g = (d + c) / 2;
                if(Get(g , i) == x) kq = g , c = g - 1;
                else d = g + 1;
            }
            L.pb(kq);
        }

        for(ll t = 0 ; t < L.size() ; t++) 
         for(ll k = 0 ; k < R.size() ; k++) {
             ll len1 , len2;
             if(t == 0) len1 = 1;
             else len1 = L[t - 1] - L[t];
             if(k == 0) len2 = 1;
             else len2 = R[k] - R[k - 1];
             ans += (((len1 * len2) % MOD) * ((a[i] * Get(L[t] , R[k])) % MOD)) % MOD;
             ans %= MOD;
         }
    }
}

int main() {
    file(); 
   cin >> n; 
   for(ll i = 1 ; i <= n ; i++) cin >> a[i];
   DequeMax();
   BuildGcd();
   Solve();
   cout << ans;
}



