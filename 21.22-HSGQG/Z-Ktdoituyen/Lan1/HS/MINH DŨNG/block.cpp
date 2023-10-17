#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int maxn = 100100;
const ll INF = 1e18;

int N, K;
int L[maxn];
ll A[maxn], dp[maxn][105], F[maxn];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  freopen("block.inp", "r", stdin);
  freopen("block.out", "w", stdout);
  cin >> N >> K;
  ll mx = -INF;
  stack<int> st;
  for (int i = 1; i <= N; ++i) {
    cin >> A[i];
    mx = max(mx, A[i]);
    dp[i][1] = mx;
    while (!st.empty() && A[i] > A[st.top()])
      st.pop();
    if (st.empty()) L[i] = 1;
    else L[i] = st.top() + 1;
    st.push(i);
  }
  for (int t = 2; t <= K; ++t) {
    stack<int> st;
    F[0] = INF;
    for (int i = 1; i <= N; ++i) {
      dp[i][t] = F[i] = INF;
      if (L[i] - 1) {
        dp[i][t] = min(dp[L[i] - 1][t - 1] + A[i], dp[L[i] - 1][t]);
      }
      while (!st.empty() && A[i] > A[st.top()]) {
        F[i] = min(F[i], F[st.top()]);
        st.pop();
      }
      st.push(i);
      dp[i][t] = min(dp[i][t], F[i] + A[i]);
      F[i] = min(F[i], dp[i][t - 1]);
    }
  }
  cout << dp[N][K] << '\n';
  return 0;
}
