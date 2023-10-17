#include <bits/stdc++.h>
#define TASK "WORD"

using namespace std;

#define int long long
#define ULL unsigned long long
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int N = 1010;
const int inf = (int) 1e9+7;

int n, nWord;
string s, t[N];
int cost[N];
int flag[N*N], g[N];
int dp[N][N];

namespace subtask1 {
    int cal(int i, int j) {
        if (dp[i][j] != 0) return dp[i][j];

        if (i > j) return 0;
        if ((j - i + 1) & 1) return -inf;

        int &ans = dp[i][j];
        ans = -inf;
        for(int lo = i; lo <= j; ++lo)
            for(int hi = lo+1; hi <= j; ++hi) {
                int cost = flag[(s[lo-1]-'a'+1)*29+s[hi-1]-'a'+1];
                int val = cal(i, lo-1) + cal(lo+1, hi-1) + cal(hi+1, j);
                if (cost && val >= 0) ans = max(ans, cost + val);
            }
        return ans;
    }
    void run() {
        for(int i = 1; i <= n; ++i)
            for(int j = i; j <= n; ++j)
                cal(i, j);

        for(int i = 1; i <= n; ++i) {
            g[i] = g[i-1];
            for(int j = i-1; j >= 0; --j)
                g[i] = max(g[i], g[j] + cal(j+1, i));
        }
    }
}

namespace subtask2 {
    int make(char a, char b, char c) {
        int now = 0;
        now = now * 29 + a - 'a' + 1;
        now = now * 29 + b - 'a' + 1;
        now = now * 29 + c - 'a' + 1;
        return now;
    }
    int cal(int i, int j) {
        if (dp[i][j] != 0) return dp[i][j];

        if ((j-i+1) % 3) return -inf;
        if (i > j) return 0;

        int &ans = dp[i][j];
        ans = -inf;
        for(int lo = i; lo <= j; ++lo)
            ans = max(ans, cal(i, lo) + cal(lo+1, j));
        for(int lo = i+1; lo < j; ++lo) {
            int __hash = make(s[i-1], s[lo-1], s[j-1]);
            int cost = flag[__hash];
            int val = cal(i+1, lo-1) + cal(lo+1, j-1);
            if (cost && val >= 0) ans = max(ans, val  + cost);
        }
        return ans;
    }
    void run() {
        for(int i = 1; i <= n; ++i)
            for(int j = i; j <= n; ++j)
                cal(i, j);

        for(int i = 1; i <= n; ++i) {
            g[i] = g[i-1];
            for(int j = i-1; j >= 0; --j)
                g[i] = max(g[i], g[j] + cal(j+1, i));
        }
    }
}
namespace subtask3 {
    int dp[N][N], f[N][N];

    void clear(int i) {
        for(int k = 0; k <= n; ++k)
            for(int j = 0; j <= n; ++j)
                dp[k][j] = -inf;
        dp[i-1][0] = 0;
    }
    void dynamic(int word, int i, int sz) {
            for(int j = i-1; j <= n; ++j) {
                for(int match = 0; match < sz; ++match) if (dp[j][match] >= 0) {
                    for(int nxt = j+1; nxt <= n; ++nxt) {
                        dp[nxt][match] = max(dp[nxt][match], dp[j][match] + f[j+1][nxt]);
                        if (s[nxt-1] == t[word][match]) {
                            dp[nxt][match+1] = max(dp[nxt][match+1], dp[j][match] + f[j+1][nxt-1] + (cost[word]) * (match+1==sz));
                        }
                    }
                }
            }
    }
    void run() {
        for(int i = 0; i <= n; ++i)
            for(int j = i; j <= n; ++j) f[i][j] = -inf;
        for(int i = n; i >= 1; --i) {
            for(int word = 1; word <= nWord; ++word) {
                int sz = t[word].size();
                clear(i);
                dynamic(word, i, sz);
                for(int j = i; j <= n; ++j)
                    f[i][j] = max(f[i][j], dp[j][sz]);
            }
        }
        for(int i = 1; i <= n; ++i) {
            g[i] = g[i-1];
            for(int j = i; j >= 1; --j)
                g[i] = max(g[i], g[j-1] + f[j][i]);
            //cout << i << ' ' << g[i] << '\n';
        }
    }
}
bool cmp(string a, string b) {
    if (a.size() != b.size()) return a.size() < b.size();
    return (a < b);
}
main() {
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);

    fast;

    cin >> s;
    n = s.size();
    cin >> nWord;

    int sz = 0;
    for(int i = 1; i <= nWord; ++i) {
        cin >> t[i] >> cost[i];
    }
            subtask3 :: run();
    cout << g[n];

}
