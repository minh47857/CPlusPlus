#include<bits/stdc++.h>
#define bug(x) cerr<<__LINE__<<": "<<#x<<" = "<<x<<'\n'

using namespace std;
using ll = long long;

const int maxn = 200;
const ll INF = 1e18;

int N;
ll po[16];
string T;

ll get(const string &S, int l, int r) {
  ll res = 0;
  for (int i = l; i < r; ++i)
    res = 1ll * res * 10 + (S[i] - '0');
  return res;
}

string toString(ll val) {
  string res = "";
  while (val) {
    int c = val % 10;
    res += (char)(c + '0');
    val /= 10;
  }
  reverse(res.begin(), res.end());
  return res;
}

bool head(const string &A, const string &B) {
  for (int i = 0; i < min(A.size(), B.size()); ++i)
    if (A[i] != B[i]) return false;
  return true;
}

bool tail(const string &A, const string &B) {
  for (int i = 0; i < min(A.size(), B.size()); ++i) {
    int j1 = A.size() - 1 - i, j2 = B.size() - 1 - i;
    if (A[j1] != B[j2]) return false;
  }
  return true;
}

int cs(ll a) {
  int cnt = 0;
  while (a) {
    ++cnt;
    a /= 10;
  }
  return cnt;
}

ll num(ll x) {
  ll res = 0;
  int d;
  while (d = cs(x)) {
    res += 1ll * d * (x - po[d - 1] + 1);
    x = po[d - 1] - 1;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  freopen("table.inp", "r", stdin);
  freopen("table.out", "w", stdout);
  cin >> N >> T;
  po[0] = 1;
  for (int i = 1; i < 16; ++i)
    po[i] = 1ll * po[i - 1] * 10;
  ll ans = INF;
  if (N <= 16) {
    ans = num(get(T, 0, N));
  }
  { /// a number between
    for (int len = 1; len <= 16; ++len) {
      ll ok = INF;
      for (int i = 0; i + len <= T.size(); ++i) {
        ll number = get(T, i, i + len);
        bool ok1 = true;
        ll cur = num(number) + T.size() - i - len;
        { /// check left
          int r = i;
          ll X = number;
          while (r > 0) {
            --X;
            int L = cs(X);
            if (r >= L) {
              ll num2 = get(T, r - L, r);
              if (num2 != X) {
                ok1 = false;
                break;
              }
            } else {
              ll num2 = get(T, 0, r);
              if (!tail(toString(num2), toString(X))) {
                ok1 = false;
                break;
              }
            }
            r -= L;
          }
        }
        { /// check right
          int l = i + len;
          ll X = number;
          while (l < T.size()) {
            ++X;
            int L = cs(X);
            if (l + L <= T.size()) {
              ll num2 = get(T, l, l + L);
              if (num2 != X) {
                ok1 = false;
                break;
              }
            } else {
              ll num2 = get(T, l, T.size());
              if (!head(toString(num2), toString(X))) {
                ok1 = false;
                break;
              }
            }
            l += L;
          }
          if (ok1) ok = min(ok, cur);
        }
      }
      ans = min(ans, ok);
      if (ok != INF) break;
    }
  }
  { /// intersect

  }
  if (ans == INF) ans = -1;
//  bug(num(1999));
  cout << ans << '\n';
  return 0;
}
