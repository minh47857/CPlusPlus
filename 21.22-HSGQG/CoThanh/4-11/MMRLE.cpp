#include <bits/stdc++.h>
using namespace std;

#define print(_v) for (auto &_ : _v) {cerr << _ << ' ';} cerr << '\n';
using ll = long long;
random_device dev;
mt19937 rng((unsigned int) chrono::steady_clock().now().time_since_epoch().count());
#define NguyenLuong "MMRLE"
#define P pair<char, ll>
#define fi first
#define se second
const int N = 1e3 + 5;
ll k;

struct rle {
    string s;
    int n = 0, m = 0;
    P p[N], ans[N];
    void make_rle() {
        for (int i = 0; i < s.size();) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                ll val = 0;
                char c = s[i];
                for (++i; i < s.size() && s[i] >= '0' && s[i] <= '9'; ++i)
                    val = val * 10 + (s[i] - '0');
                p[++n] = {c, val};
            }
        }
    }

    void add(P x) {
        if (ans[m].first == x.first)
            ans[m].second += x.second;
        else
            ans[++m] = x;
    }

    void findmax(ll k) {
        stack<P> S;
        for (int i = 1; i <= n; ++i) {
            while (S.size() && k && S.top().fi < p[i].fi) {
                ll val = min(S.top().se, k);
                k -= val;
                S.top().se -= val;
                if (!S.top().se) S.pop(); 
            }
            S.push(p[i]);
        }
        while (S.size() && k) {
            ll val = min(S.top().se, k);
            k -= val;
            S.top().se -= val;
            if (!S.top().se) S.pop(); 
        }
        m = 0;
        while (S.size()) {
            add(S.top()); 
            S.pop();
        }
        reverse(ans + 1, ans + m + 1);
        for (int i = 1; i <= m; ++i)
            cout << ans[i].first << ans[i].second;
    }

    void findmin(ll k) {
        stack<P> S;
        for (int i = 1; i <= n; ++i) {
            while (S.size() && k && S.top().fi > p[i].fi) {
                ll val = min(S.top().se, k);
                k -= val;
                S.top().se -= val;
                if (!S.top().se) S.pop(); 
            }
            S.push(p[i]);
        }
        while (S.size() && k) {
            ll val = min(S.top().se, k);
            k -= val;
            S.top().se -= val;
            if (!S.top().se) S.pop(); 
        }
        m = 0;
        while (S.size()) {
            add(S.top()); 
            S.pop();
        }
        reverse(ans + 1, ans + m + 1);
        for (int i = 1; i <= m; ++i)
            cout << ans[i].first << ans[i].second;
    }
    
    friend istream& operator >> (istream& is, rle &x) {
        is >> x.s;
        x.make_rle();
        return is;
    }
    friend ostream& operator << (ostream& os, rle x) {
        for (int i = 1; i <= x.n; ++i)
            os << x.p[i].fi << ' ' << x.p[i].se << '\n';
        return os;
    }
} a;

struct Data {
    string X;
    pair<char, ll> p[N], ans[N];
    int l, l_ans;

    Data() {l = 0;}
    
    void organize() {
        for (int i = 0; i < (int)X.size(); ++i) {
            if (X[i] >= 'a' && X[i] <= 'z') {
                ll val = 0;
                int j = i + 1;
                while (j < (int)X.size() && X[j] >= '0' && X[j] <= '9') 
                    val = val * 10 + X[j] - '0', ++j;
                p[l++] = {X[i], val};
                i = j - 1;
            }
        }
    }

    void add(pair<char, ll> x) {
        if (l_ans && ans[l_ans - 1].first == x.first)
            ans[l_ans - 1].second += x.second;
        else
            ans[l_ans++] = x;
    }

    void findmax(ll k) {
        stack<pair<char, ll>> S;
        for (int i = 0; i < l; ++i) {
            while (S.size() && k && S.top().first < p[i].first) {
                ll val = min(S.top().second, k);
                k -= val;
                S.top().second -= val;
                if (!S.top().second) S.pop(); 
            }
            S.push(p[i]);
        }
        while (S.size() && k) {
            ll val = min(S.top().second, k);
            k -= val;
            S.top().second -= val;
            if (!S.top().second) S.pop(); 
        }
        l_ans = 0;
        while (S.size()) {
            add(S.top()); 
            S.pop();
        }
        reverse(ans, ans + l_ans);
        for (int i = 0; i < l_ans; ++i)
            cout << ans[i].first << ans[i].second;
    }

    void findmin(ll k) {
        stack<pair<char, ll>> S;
        for (int i = 0; i < l; ++i) {
            while (S.size() && k && S.top().first > p[i].first) {
                ll val = min(S.top().second, k);
                k -= val;
                S.top().second -= val;
                if (!S.top().second) S.pop(); 
            }
            S.push(p[i]);
        }
        while (S.size() && k) {
            ll val = min(S.top().second, k);
            k -= val;
            S.top().second -= val;
            if (!S.top().second) S.pop(); 
        }
        l_ans = 0;
        while (S.size()) {
            add(S.top()); 
            S.pop();
        }
        reverse(ans, ans + l_ans);
        for (int i = 0; i < l_ans; ++i)
            cout << ans[i].first << ans[i].second;
    }
};

void solve() {
    Data a;
    cin >> k >> a.X;
    a.organize();
    a.findmax(k);
    cout << '\n';
    a.findmin(k);
}

int main() {
    ios::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);
    if (fopen(NguyenLuong".inp", "r")) {
        freopen(NguyenLuong".inp", "r", stdin);
        freopen(NguyenLuong".out", "w", stdout);
    }
    solve();
    return 0;
}