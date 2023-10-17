#include<bits/stdc++.h>
#define bug(x) cerr<<#x<<" = "<<x<<'\n'

using namespace std;

const int maxn = 100100, mod = 1e9 + 7, K = 25;

int mul(int a, int b) {
  return 1ll * a * b % mod;
}

int add(int a, int b) {
  a += b;
  if (a >= mod) a -= mod;
  if (a < 0) a += mod;
  return a;
}

int dp[K][maxn], N, Q;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
//  freopen("sumlove.inp", "r", stdin);
//  freopen("sumlove.out", "w", stdout);
  cin >> N >> Q;
  dp[0][0] = 1;
  for (int i = 0; i < K; ++i) {
    for (int j = 0; j < maxn; ++j) {
      if (i && j > N) {
        dp[i][j] = add(dp[i][j], -mul(2, dp[i - 1][j - N - 1]));
      }
      if (i > 1 && j > 2 * N + 1) {
        dp[i][j] = add(dp[i][j], -dp[i - 2][j - 2 * N - 2]);
      }

      if (i && j + i < maxn)
        dp[i][j + i] = add(dp[i][j + i], dp[i][j]);
      if (j + i + 1 < maxn && i + 1 < K)
        dp[i + 1][j + i + 1] = add(dp[i + 1][j + i + 1], mul(2, dp[i][j]));
      if (j + i + 2 < maxn && i + 2 < K)
        dp[i + 2][j + i + 2] = add(dp[i + 2][j + i + 2], dp[i][j]);
    }
  }
  while (Q--) {
    int S; cin >> S;
    int ans = 0;
    for (int i = 0; i < K; ++i) {
      ans = add(ans, dp[i][S]);
    }
    cout << ans << '\n';
  }
  return 0;
}
