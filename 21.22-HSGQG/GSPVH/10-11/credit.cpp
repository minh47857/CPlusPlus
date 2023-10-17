#include<bits/stdc++.h>
#define x first
#define y second
#define bug(x) cerr<<#x<<" = "<<x<<'\n'

using namespace std;
using ll = long long;

const int maxn = 300100;
const ll INF = 1e18;

typedef pair<int, int> ii;

struct FT {
  int N;
  vector<ll> T;
  FT() {}
  FT(int N) : N(N), T(N + 5, 0) {}
  void upd(int x, int val) {
    for (; x <= N; x += x & -x)
      T[x] += val;
  }
  ll get(int x) {
    ll ret = 0;
    for (; x; x -= x & -x)
      ret += T[x];
    return ret;
  }
  int kth(int K) {
    int pos = 0, sum = 0;
    for (int i = 19; i >= 0; --i) {
      if (pos + (1 << i) <= N && sum + T[pos + (1 << i)] < K) {
        pos += (1 << i);
        sum += T[pos];
      }
    }
    return pos + 1;
  }
};

bool minn(ll &a, ll b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

struct trip {
  int x, y, z;
  trip() {}
  trip(int x, int y, int z) : x(x), y(y), z(z) {}
  bool operator < (const trip &other) const {
    if (x != other.x) return x < other.x;
    if (y != other.y) return y < other.y;
    return z < other.z;
  }
};

int N, M, K, res[maxn];
trip A[maxn];
ii B[maxn];
FT T1, T2;
vector<int> all;

ll getSum(int tot) {
  if (T1.get(M) < tot) return INF;
  if (!tot) return 0;
  int pos = T1.kth(tot);
  int rem = tot - T1.get(pos - 1);
  ll ret = T2.get(pos - 1);
  ret += 1ll * rem * all[pos - 1];
  return ret;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  freopen("credit.inp", "r", stdin);
  freopen("credit.out", "w", stdout);
  cin >> N >> N >> K;
  for (int i = 1; i <= N; ++i) {
    cin >> A[i].y >> A[i].x;
    A[i].z = i;
  }
  sort(A + 1, A + 1 + N);
  for (int i = 1; i <= N; ++i) {
    all.push_back(A[i].y);
    all.push_back(A[i].x - A[i].y);
  }
  sort(all.begin(), all.end());
  all.erase(unique(all.begin(), all.end()), all.end());
  M = (int)all.size();
  for (int i = 1; i <= N; ++i) {
    B[i].x = lower_bound(all.begin(), all.end(), A[i].y) - all.begin() + 1;
    B[i].y = lower_bound(all.begin(), all.end(), A[i].x - A[i].y) - all.begin() + 1;
  }
  T1 = FT(M); /// count
  T2 = FT(M); /// sum
  for (int i = 1; i <= N; ++i) {
    T1.upd(B[i].x, 1);
    T2.upd(B[i].x, A[i].y);
  }
  ll ans = getSum(K), cur = 0, pos = 0;
  for (int i = 1; i <= N; ++i) {
    T1.upd(B[i].x, -1);
    T2.upd(B[i].x, -A[i].y);
    ll sum = cur + A[i].x + getSum(K - i - 1);
    if (minn(ans, sum)) pos = i;
    cur += A[i].y;
    T1.upd(B[i].y, 1);
    T2.upd(B[i].y, A[i].x - A[i].y);
  }
  cout << ans << '\n';
  {
    vector<ii> a;
    res[A[pos].z] = 2;
    for (int i = 1; i < pos; ++i) {
      res[A[i].z] = 1;
      a.push_back({A[i].x - A[i].y, A[i].z});
    }
    for (int i = pos + 1; i <= N; ++i) {
      res[A[i].z] = 0;
      a.push_back({A[i].y, A[i].z});
    }
    sort(a.begin(), a.end());
    if (!pos) pos = -1;
    for (int i = 0; i < K - pos - 1; ++i)
      res[a[i].y]++;
  }
  for (int i = 1; i <= N; ++i) cout<<res[i];
  cout<<'\n';
}
