#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll , ll>

const ll N = 1e3 , inf = 1e15;

void file() {
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll n , w1 , w2 , w3 , q;
pi a[N];

bool cmp(pi x , pi y) {
	return x.se > y.se;
}

ll Johson(ll p1 , ll p2 , int s) {
	vector<pi> X , Y;
	for(int i = 1 ; i <= n ; i++) if(i != s) {
		if(a[i].fi <= a[i].se) X.pb(a[i]);
		else Y.pb(a[i]);
	}
	sort(X.begin() , X.end());
	sort(Y.begin() , Y.end() , cmp);
	for(auto i : X) p1 += i.fi , p2 = max(p1 , p2) + i.se;
	for(auto i : Y) p1 += i.fi , p2 = max(p1 , p2) + i.se;
	return p2;
}

void sub2() {
	pi ans = {-inf , inf};
	ll res = Johson(0 , 0 , 0);
	cout << fixed << setprecision(1) << res * 1.0 / 2 << '\n';
}

void sub3() {
	pi ans = {-inf , inf};
	for(int i = 1 ; i <= n ; i++) {
		ll t1 , t2;
		t1 = a[i].fi + a[i].se;
		t2 = Johson(a[i].fi , a[i].fi + a[i].se , i);
		if(t2 - t1 < ans.se - ans.fi) ans = {t1 , t2};
	}
	cout << fixed << setprecision(1) << (ans.se - ans.fi) * 1.0 / 2 << '\n';
}

void sub4() {
	long double ans = inf;
	if(w2 == 0 && w1 * w3 == 0) {
		cout << "0.0" << '\n';
		return;
	}
	for(int i = 1 ; i <= n ; i++) {
		ll t1 , t2;
		t1 = a[i].fi + a[i].se;
		t2 = Johson(a[i].fi , a[i].fi + a[i].se , i);
		long double y1 = ((w1 * w2) * (t2 - t1)) * 1.0 / (w1 + w2);
		long double y2 = (w2 * w3 * t2) * 1.0 / (w2 + w3);
		ans = min(ans , max(y1 , y2));
	}
	cout << fixed << setprecision(1) << ans << '\n';
}

void solve() {
	cin >> n >> w1 >> w2 >> w3;
	for(int i = 1 ; i <= n ; i++) cin >> a[i].fi >> a[i].se;
	if(w1 == 0 && w2 == 1 && w3 == 1) sub2();
	else if(w3 == 0 && w1 == 1 && w2 == 1) sub3();
    else sub4();
}

int main() {
	file();
	cin >> q;
	while(q--) solve();
	return 0;
}

