#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define si short int
#define ms(d, i) memset(d, i, sizeof(d))
#define ln cout << '\n'

#define pii pair<int, int>
#define pll pair<long long, long long>
#define fi first
#define se second

#define vi vector<int>
#define pb push_back

const string Fname = "DMT";
const int mod = 1e9 + 7;
const int N = 1e7 + 5;
int ip[N], s[N];

void input() {
ios::sync_with_stdio(0);
cout.tie(0); cin.tie(0);
if (fopen((Fname + ".inp").c_str(), "r")){
freopen((Fname + ".inp").c_str(), "r", stdin);
freopen((Fname + ".out").c_str(), "w", stdout);
}
}

void init() {
ms(ip, true);
ip[0] = ip[1] = false;
for (ll i = 2; i <= 1e6; ++i) {
if (ip[i]) for (ll j = i * i; j <= 1e6; j += i) ip[j] = false;
}

ip[3] = false;
ip[27] = true;

s[0] = 0;
for (int i = 1; i <= 1e6; ++i) s[i] = s[i - 1] + (ip[i] ? 1 : 0);
}

void solve() {
ll l, r; cin >> l >> r;
ll x = sqrt(l) + (sqrt(l) == (ll)(sqrt(l)) ? 0 : 1);
ll y = sqrt(r);
int L = x / 3 + (x / 3 == x / 3.0 ? 0 : 1);
int R = y / 3;
cout << L - 1 << ' ' << R << ' ';
cout << s[R] << ' ' << s[L - 1] << endl;
 cout << s[R] - s[L - 1] << '\n';
}

// check lai code truoc khi nop
// Luu y khi chia sub

int main()
{
input();
init();
int t; cin >> t; while (t--)
solve();
return 0;
}
