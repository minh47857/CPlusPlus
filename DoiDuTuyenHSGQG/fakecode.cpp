#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


#define f(a, b, c) for (int a = (b), _c = (c); a <= _c; ++a)
#define fr(a, b, c) for (int a = (b), _c = (c); a >= _c; --a)
#define rep(a, b) for (int a = 0, _b = (b); a < _b; ++a)
#define fe(x, a) for (auto &x : a)

#define ll long long
#define ar array
#define vt vector
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define mask(i) (1ll << (i))
#define bit(x, i) (((x) >> (i)) & 1ll)

template<class T> bool omin(T &a, const T &b) {
        return b < a ? a = b, 1 : 0;
}
template<class T> bool omax(T &a, const T &b) {
        return a < b ? a = b, 1 : 0;
}

#define dbg(...) cerr << "#" << __LINE__ << ":[" << #__VA_ARGS__ \
<< "] = [" ,DBG(__VA_ARGS__)

string to_string(const string& s) { return '"' + s + '"'; }
void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) {
        cerr << to_string(h); if(sizeof...(t)) cerr << ", "; DBG(t...);
}

/***------------------------- END OF TEMPLATE ---------------------------***/

typedef pair<int, int> ii;

const int MOD = (int)(1e9 + 7);
const long long oo = (long long)(1e9 + 7);
const int N = (int)(1e6);

int n;
vt<ii> cards[N], needs[N];
vt<ar<ll, 3>> valid_plays[N];
void file()
{
	freopen("fakecode.inp" , "r" , stdin);
	freopen("fakecode.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
void test_case() {
        cin >> n;
        f(i, 1, n) {
                int k;
                cin >> k;

                cards[i].assign(k, {0, 0});
                rep(j, k)
                        cin >> cards[i][j].first >> cards[i][j].second;
        }

        f(i, 1, n) {
                sort(all(cards[i]), [](ii a, ii b) {
                        return a.second > b.second;
                });

                vt<int> cnt (4, 0);
                fe(j, cards[i]) {
                        if (cnt[j.first] * j.first + j.first <= 3)
                                needs[i].pb(j);
                        ++cnt[j.first];
                }
        }

        f(i, 1, n) {
                rep(j, mask(sz(needs[i]))) {
                        int cost = 0, ma = 0;
                        ll dame = 0;
                        rep(k, sz(needs[i])) {
                                if (bit(j, k)) {
                                        cost += needs[i][k].first;
                                        dame += needs[i][k].second;
                                        omax(ma, needs[i][k].second);
                                }
                        }
                        if (cost <= 3)
                                valid_plays[i].pb({__builtin_popcount(j), dame, ma});
                }
        }

        vt<vt<ll>> dp (n + 1, vt<ll> (11, -1));
        dp[0][0] = 0;
        f(i, 0, n - 1) f(j, 0, 10) if (dp[i][j] > -1) 
		 
		 {
		 	cout << i << ' ' <<j <<' ' << dp[i][j] << endl;
                fe(k, valid_plays[i + 1]) {
                        int nxtNum = j + k[0];
                        if (nxtNum < 10)
                                omax(dp[i + 1][nxtNum], dp[i][j] + k[1]);
                        else
                                omax(dp[i + 1][nxtNum % 10], dp[i][j] + k[1] + k[2]);
                }
        }

        cout << *max_element(all(dp[n])) << "\n";
}

signed main() {
       // fast;
//        file("a");
file();
        int TC = 1;
//        cin >> TC;
        f(i, 1, TC) {
                test_case();
//                break;
        }
}

