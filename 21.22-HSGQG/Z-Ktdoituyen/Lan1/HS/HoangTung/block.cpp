#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl '\n'
#define bit(s, i) (s & (1<<i)

using namespace std;

const long long Inf = 2e18;
const int mod = 1e9 + 7;

typedef pair < int, int > ii;
typedef long long ll;

int n, k, a[100005];

long long ma[105][105], dp[105][105];
void solve1() {
    memset(ma, -0x3f, sizeof ma);
    for(int i=1;i<=n;++i)
    for(int j=i;j<=n;++j) {
        for(int p=i;p<=j;++p) ma[i][j] = max(ma[i][j], ll(a[p]));
    }

    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;
    for(int i=1;i<=n;++i)
    for(int j=1;j<=k;++j) {
        for(int p=0;p<=i-1;++p) dp[i][j] = min(dp[i][j], dp[p][j - 1] + ma[p + 1][i]);
    }
    cout << dp[n][k];
}

long long res[100005][105], pre[100005][105];

void solve2() {
    memset(res, 0x3f, sizeof res);
    memset(pre, 0x3f, sizeof pre);
    res[0][0] = 0, pre[0][0] = 0;
    a[0] = 0;
    stack < int > q;
    q.push(0);
    for(int i=1;i<=n;++i) {
        while(q.size() && a[i] > a[q.top()]) {
            for(int j=1;j<=k;++j) {
                cout << i << ' ' << q.top() << endl;
                res[i][j] = min(res[i][j], res[q.top()][j - 1] - a[q.top()] + a[i]);
            }
            q.pop();
        }
        if(q.top()) for(int j=1;j<=k;++j) res[i][j] = min(res[i][j], pre[q.top()][j - 1]);
        q.push(i);
        for(int j=1;j<=k;++j) pre[i][j] = min(pre[i][j], pre[i - 1][j]), cout << i << ' ' << j << ' ' << res[i][j] << endl;
    }
    cout << res[n][k];
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("block.inp", "r", stdin);
    freopen("block.out", "w", stdout);

    cin >> n >> k;
    for(int i=1;i<=n;++i) cin >> a[i];
    if(n <= 100) {
        solve1();
        return 0;
    }
    //solve2();
}

