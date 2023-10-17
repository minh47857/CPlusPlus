#include <bits/stdc++.h>

using namespace std;

const int MAXS = 100 + 10;
const int MAXK = 100 + 10;
const int MAXN = 676 + 10;
const int INF = (int)(1e9);

string s;
int k;
int n;
int score[26][26];
int f[MAXS][MAXK][26];

void maximize(int &a, int b) {
    a = max(a, b);
}

int main() {
    freopen("strbeauty.inp", "r", stdin);
    freopen("strbeauty.out", "w", stdout);
    
    cin >> s >> k;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        char x, y; int z;
        cin >> x >> y >> z;
        score[x - 'a'][y - 'a'] = z;
    }
    
    for(int i = 0; i <= s.length(); ++i)
        for(int j = 0; j <= k; ++j)
            for(int t = 0; t < 26; ++t)
                f[i][j][t] = -INF;
                
    f[0][0][0] = 0;
    for(int i = 0; i < s.length(); ++i)
        for(int j = 0; j <= k; ++j)
            for(int t = 0; t < 26; ++t)
                if (f[i][j][t] > -INF) {
                    //cout << i << " " << j << " " << char(t + int('a')) << " " << f[i][j][t] << "\n";
                    //no changes at i+1
                    maximize(f[i + 1][j][s[i] - 'a'], f[i][j][t] + ( (i == 0) ? 0 : score[t][s[i] - 'a'] ));
                           
                    for(int t2 = 0; t2 < 26; ++t2)
                        maximize(f[i + 1][j + 1][t2], f[i][j][t] + ( (i == 0) ? 0 : score[t][t2] ) );
                }
    int res = -INF;
    for(int j = 0; j <= k; ++j)
        for(int t = 0; t < 26; ++t)
            res = max(res, f[s.length()][j][t]);
    cout << res << "\n";
}
