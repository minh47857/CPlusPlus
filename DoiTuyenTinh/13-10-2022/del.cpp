#include<bits/stdc++.h>
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define Bit(x , k) ((x >> k) & 1)

using namespace std;
const int N = 15;

void file() {
	freopen("del.inp" , "r" , stdin);
	freopen("del.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

ll t , n , k , d , c , g , ans , a[N];

bool check(ll x) {
	ll num = 0;
	for(int mask = 1 ; mask < (1 << n) ; mask++) {
		ll lcm = 0;
		bool ok = true;
		for(int i = 0 ; i < n ; i++) if(Bit(mask , i)) {
			if(!lcm) {
				lcm = a[i];
				continue;
			}
			ll gcd = __gcd(a[i] , lcm);
			if(lcm / gcd > x / a[i]) {
				ok = false;
				break;
			} else lcm = lcm / gcd * a[i];
		}
		if(!ok) continue;
		if(__builtin_popcount(mask) % 2) num += x / lcm;
		else num -= x / lcm;
	}
	return (x - num) >= k;
}

void solve() {
	cin >> n >> k;
	for(int i = 0 ; i < n ; i++) cin >> a[i];
	d = 1 , c = 1e18;
	while(d <= c) {
		g = (d + c) / 2;
		if(check(g)) ans = g , c = g - 1;
		else d = g + 1;
	}
	cout << ans << '\n';
}

int main() {
	file();
	cin >> t;
	while(t--) solve();
	return 0;
}

