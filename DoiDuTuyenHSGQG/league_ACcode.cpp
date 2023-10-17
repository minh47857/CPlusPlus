#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<ll, ll>
#define fi first
#define se second
const ll N = 5e5 + 5;

ll n, m, q, x, Max = 0, res[N], st[4 * N] = {}, cnt = 1, Year = 0;
pii a[N] = {}, Qr[N];

void update(ll id, ll l, ll r, ll x) {
	if(l > x || r < x) return;
	if(l == x && r == x) {
		++st[id];
		return;
	}
	ll mid = (l + r) / 2;
	update(2 * id, l, mid, x);
	update(2 * id + 1, mid + 1, r, x);
	st[id] = st[2 * id] + st[2 * id + 1];
}

ll get(ll id, ll l, ll r, ll x, ll val) {
	if(l == r) return l;
	ll mid = (l + r) / 2;
	if(val + st[2 * id] >= x) return get(2 * id, l, mid, x, val);
	else return get(2 * id + 1, mid + 1, r, x, val + st[2 * id]);
}

void solve() {
	cin >> n >> m >> q;
	for(ll i = 1; i <= m; ++i)
		a[i].se = i;
	for(ll i = 1, tmp; i <= n; ++i) 
		cin >> tmp, ++a[tmp].fi;
	
	for(ll i = 1; i <= q; ++i) 
		cin >> Qr[i].fi, Qr[i].se = i;
	sort(Qr + 1, Qr + q + 1);

	Year = n;
	sort(a + 1, a + m + 1);
	a[m + 1].fi = -1;
		
	for(ll i = 1; i <= m; ++i) {
		ll tmp = i;
		update(1, 1, m, a[i].se);
		while(a[i].fi == a[i + 1].fi) ++i, update(1, 1, m, a[i].se);
		
		if(a[i + 1].fi != -1) {
			ll Diff = a[i + 1].fi - a[i].fi;
			while(cnt <= q && Qr[cnt].fi - Year <= Diff * i) {
				ll u = Qr[cnt].fi - Year;
				u = (u % Diff == 0 ? u / Diff : (u / Diff) + 1);
				
				res[Qr[cnt].se] = get(1, 1, m, u, 0);
				++cnt;
			} 
			Year += Diff * i;
		}		
	}
	
	
	if(cnt <= q) {
		for(ll i = cnt; i <= q; ++i) {
			ll u = Qr[i].fi - Year;
			res[Qr[i].se] = (u % m == 0 ? m : u % m);
		}
	}
	for(ll i = 1; i <= q; ++i)
		cout << res[i] << '\n'; 
} 

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	solve();	
}
