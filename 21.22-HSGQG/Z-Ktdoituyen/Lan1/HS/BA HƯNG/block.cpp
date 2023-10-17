#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 3;
const int K = 103;
int n, k;
int a[N];
int dp[N][K];

struct ok
{
    int lo, hi;
    int ma;
    int val;
};
ok Node[4 * N];

void build(int id, int l, int r)
{
    Node[id].lo = l;
    Node[id].hi = r;
    Node[id].val = 1e9;

    if (l == r) return;

    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
}

void update(int id, int pos, int val, int ma)
{
    if (Node[id].lo > pos || Node[id].hi < pos) return;

    if (Node[id].lo == Node[id].hi)
    {
        Node[id].val = val;
        Node[id].ma = ma;
        return;
    }

    update(id * 2, pos, val, ma);
    update(id * 2 + 1, pos, val, ma);

    Node[id].val = min(Node[id * 2].val, Node[id * 2 + 1].val);
    Node[id].ma = max(Node[id * 2].ma, Node[id * 2 + 1].ma);
}

typedef pair < int, int > ii;

ii getres(int id, int r)
{
    if (Node[id].lo > r) return {1e9, -1};

    //cout << Node[id].lo << " " << Node[id].hi << " " << Node[id].val << " " << Node[id].ma << '\n';

    if (Node[id].hi <= r)
        return {Node[id].val, Node[id].ma};

    ii cur1 = getres(id * 2, r);
    ii cur2 = getres(id * 2 + 1, r);
    int num = max(cur1.second, cur2.second);
    if (cur1.first + num < cur2.first + cur2.second || cur2.second == -1)
        return {cur1.first, num};

    return cur2;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("block.inp","r",stdin); freopen("block.out","w",stdout);

    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    if (n <= 500)
    {
        memset(dp, 0x3f, sizeof dp);
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++)
            for (int t = 1; t <= k; t++)
            {
                int ma = 0;
                for (int j = i; j >= 1; j--)
                {
                    ma = max(ma, a[j]);
                    dp[i][t] = min(dp[i][t], dp[j - 1][t - 1] + ma);
                }
            }

        cout << dp[n][k];
        return 0;
    }

    build(1, 0, n);
    update(1, 0, 0, 0);
    for (int i = 1; i <= n; i++)
        update(1, i, 1e9, a[i]);

    for (int t = 1; t <= n; t++)
    {
        for (int i = 1; i <= n; i++)
        {
            ii cur = getres(1, i - 1);
            dp[i][t] = cur.first + max(cur.second, a[i]);
        }

        for (int i = 0; i < t; i++)
            update(1, i, 1e9, 0);

        for (int i = 1; i <= n; i++)
            update(1, i, dp[i][t], a[i]);
    }

    cout << dp[n][k];
}
