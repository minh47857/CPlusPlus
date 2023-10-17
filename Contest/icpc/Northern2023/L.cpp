#include<bits/stdc++.h>
using namespace std;

const int N = 5e6 + 5;
const int MOD = 998244353;

long long A, B, ans;
vector<int> f;
pair<long long, int> d[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> A >> B;
    for(int i = 1; i <= B; i++)
        d[i] = {A * i, i};
    for(int i = 2; i <= B; i++) {
        for(int j = i; j <= B; j += i) {
            if(d[j].second % i != 0) continue;
            d[j].first -= d[j].first / i;
            while(d[j].second % i == 0) d[j].second /= i;
        }
    }
    for(int i = 2; i <= A; i++)
        if(A % i == 0) {
            f.push_back(i);
            while(A % i == 0) A /= i;
        }
    for(int i = 1; i <= B; i++) {
        for(int j : f) if(i % j != 0) {
            d[i].first -= d[i].first / j;
        }
        ans = (ans + d[i].first) % MOD;
    }
    cout << ans;
    return 0;
}