#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < int(n); ++i)
#define REPE(i, a, b) for (int i = (a); i <= int(b); ++i)
#define SZ(x) ((int)(x).size())
#define ALL(x) x.begin(), x.end()
#define PB push_back
#define EB emplace_back
using LL = long long;
using PII = pair<int, int>;
#define F first
#define S second


int n, ts, tf;
LL s[2020], f[2020], d[2020];
LL dp[2020][2020];
const LL inf = (1LL << 55);

LL next(LL t, LL s, LL f, LL d) {
  if (s >= t) return s + d;
  return t + ((s-t) % f + f) % f + d;
}

void solve() {
  scanf("%d%d%d", &n, &ts, &tf);
  REPE(i, 1, n - 1) scanf("%lld%lld%lld", &s[i], &f[i], &d[i]);
  dp[0][0] = 0;
  REPE(i, 1, n - 1) dp[0][i] = inf;
  REPE(i, 1, n - 1) {
    REPE(j, 0, n - 1) {
      dp[i][j] = next(dp[i-1][j], s[i], f[i], d[i]);
      if (j) dp[i][j] = min(dp[i][j], next(dp[i-1][j-1] + ts, s[i], f[i], d[i]));
    }
  }
  for (int i = n - 1; i >= 0; --i) {
    if (dp[n-1][i] <= tf) {
      printf("%d\n", i);
      return;
    }
  }
  puts("IMPOSSIBLE");
}

int main() {
  freopen("sightseeing.inp", "r", stdin);
  freopen("sightseeing.out", "w", stdout);
  
  int T;
  scanf("%d", &T);
  for (int kase = 1; kase <= T; ++kase) {
    //printf("Case #%d: ", kase);
    solve();
  }
  return 0;
}

