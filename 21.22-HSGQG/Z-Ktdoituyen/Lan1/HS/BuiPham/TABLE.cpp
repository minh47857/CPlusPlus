#include <bits/stdc++.h>

using namespace std;

const int lim = 1e15;

long long cal(long long x) {
    long long l = 1;
    long long r = 10;
    long long res = 0;
    for (int i = 1 ; i <= 16 ; ++i) {
        res += (r - l) * i;
        l *= 10;
        r *= 10;
        if (r > x) {
            if (l <= x) res += (x - l + 1) * (i + 1);
            break;
        }
    }
    return res;
}

string add(string s) {
    string t;
    t = s;
    int pos = -1;
    for (int i = s.size() - 1 ; i >= 0 ; --i) {
        if (s[i] - '0' != 9) {
            t[i] = char(s[i] + 1);
            pos = i;
            break;
        }
    }
    if (pos == -1) {
        t = "1";
        for (int i = 0 ; i < s.size() ; ++i) t += '0';
    } else for (int i = pos + 1 ; i < s.size() ; ++i) t[i] = '0';
    return t;
}

bool checkpre(string s,string t) {
    s = add(s);
    if (t.size() < s.size()) return false;
    for (int i = 0 ; i < s.size() ; ++i)
    if (s[s.size() - 1 - i] != t[t.size() - 1 - i]) return false;
    return true;
}

bool checksuf(string s,string t) {
    t = add(t);
    if (t.size() < s.size()) return false;
    for (int i = 0 ; i < s.size() ; ++i)
    if (s[i] != t[i]) return false;
    return true;
}

int main() {
    freopen("TABLE.inp","r",stdin);
    freopen("TABLE.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    string s;
    int n;
    cin >> n >> s;
    s = ' ' + s;
    long long res = 1e18;
    for (int pre = 0 ; pre <= min(n , 16) ; ++pre) {
        if (pre == n) {
            long long x = 0;
            for (int i = 1 ; i <= pre ; ++i) x = x * 10 + s[i] - '0';
            if (x != 0) {
                if (x <= lim) res = min(res , cal(x));
            } else {
                x = 1;
                for (int i = 1 ; i <= pre ; ++i) x = x * 10;
                if (x <= lim) res = min(res , cal(x));
            }
        }
        for (int suf = 0 ; suf <= min(n - pre , 16) ; ++suf) {
            if (suf + pre == n) {
//                string x , t , y;
//                for (int i = 1 ; i <= pre ; ++i) x += s[i];
//                for (int i = n - suf + 1 ; i <= n ; ++i) t += s[i];
//                y = add(x);
//                for (int len = min(y.size() , t.size()) ; len <= 16 ; ++len) {
//                    bool ok = true;
//                    for (int i = 0 ; i < y.size() - (len - t.size()) + 1 ; ++i)
//                    if (y[i] != t[len - y.size() + 1 + i]) ok = false;
//                    if (!ok) continue;
//                    long long x = 0;
//                    for (int i = 0 ; i < t.size() ; ++i) x = x * 10 + t[i];
//                    for (int i = y.size() - (len - t.size()) + 1 ; i < y.size() ; ++i) x = x * 10 + y[i];
//                    if (x > 0 && x <= lim) res = min(res , cal(x));
//                }
            }
            for (int len = 1 ; len <= n - suf - pre ; ++len) {
                string cur;
                for (int i = pre + 1 ; i <= pre + len ; ++i) cur += s[i];
                bool ok = true;
                if (pre > 0) {
                    string x;
                    for (int i = 1 ; i <= pre ; ++i) x += s[i];
                    if (!checkpre(x , cur)) ok = false;
                }
                if (!ok) continue;
                int pos = pre + len;
                while (pos < n - suf) {
                    string nxt = add(cur);
                    if (pos + nxt.size() > n - suf) ok = false;
                    if (nxt.size() > 16) ok = false;
                    string x;
                    for (int i = 0 ; i < nxt.size() ; ++i)
                    if (nxt[i] != s[pos + i + 1]) {
                        ok = false;
                        break;
                    }
                    if (!ok) break;
                    pos += nxt.size();
                    cur = nxt;
                }
                if (!ok) continue;
                if (suf > 0) {
                    string x;
                    for (int i = n - suf + 1 ; i <= n ; ++i) x += s[i];
                    if (!checksuf(x , cur)) ok = false;
                }
                if (!ok) continue;
                long long x = 0;
                for (int i = 0 ; i < cur.size() ; ++i) x = x * 10 + cur[i] - '0';
                if (x + (suf > 0) <= lim && x > 0) res = min(res , cal(x) + suf);
            }
        }
    }
    if (res >= 1e18) cout << -1;
    else cout << res;
}
