#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int maxn = 500100;

int K, H, N, ans;
ll A[maxn];
deque<ll> dq;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  //freopen("ktreer4.inp", "r", stdin);
  //freopen("ktreer4.out", "w", stdout);
  cin >> K >> H >> N;
  for (int i = 1; i <= N; ++i) cin >> A[i];
  sort(A + 1, A + 1 + N, greater<ll>());
  N = unique(A + 1, A + 1 + N) - A - 1;
  int pos = 1;
  while (true) {
    if (pos > N && dq.size() < 2) break;
    if (N - pos + 1 + dq.size() < 2) break;
    if(dq.size()) cout << dq.front() << endl;
    if (pos > N) {
      ll x = dq.front(); dq.pop_front();
      if ((x + K - 2) / K != dq.back())
        dq.push_back((x + K - 2) / K);
      ++ans;
    }
    if (dq.empty()) {
      dq.push_back((A[pos] + K - 2) / K);
      ++ans;
      ++pos;
    } else {
      ll x = dq.front();
      if (x == A[pos] && pos <= N) ++pos;
      if (pos <= N) {
        if (x > A[pos]) {
          dq.pop_front();
          if (dq.back() != (x + K - 2) / K)
            dq.push_back((x + K - 2) / K);
          ++ans;
        } else {
          if ((A[pos] + K - 2) / K != dq.back())
            dq.push_back((A[pos] + K - 2) / K);
          ++ans;
          ++pos;
        }
      }
    }
  }
  cout << ans << '\n';
}
