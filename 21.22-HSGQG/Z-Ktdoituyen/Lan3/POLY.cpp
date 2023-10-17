#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define eps 1e-6
#define pi pair<ll , ll>
#define mp make_pair

const int N = 1e5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

using namespace std;

void file() {
	freopen("POLY.inp" , "r" , stdin);
	freopen("POLY.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

ll n , m , ans;
pi st[N];
map<int , int> pos;
vector<pair<pair<ll , ll> , pair<ll , ll>>> Q;
vector<int> Y;

namespace sub1 {
	int ans = 0 , c[1005][1005];
	void solve() {
		memset(c , 0 , sizeof(c));
		for(int i = 1 , m ; i <= n ; i++) {
			cin >> m;
			int x = -inf , y = inf , u = inf , v = -inf;
			for(int j = 1 ; j <= m ; j++) {
				int xx , yy; cin >> xx >> yy;
				x = max(x , xx);
				u = min(u , xx);
				y = min(y , yy);
				v = max(v , yy);
			}
		}
		cout << ans;
	}
}

void update(int id , int l , int r , int u , int v , int val) {
	if(l > v || r < u) return;
	if(l >= u && r <= v) st[id].fi += val;
	else {
		int mid = (l + r) / 2;
	//	cout << l << ' ' << r << ' ' << mid << '\n';
		if(mid > l && mid < r) update(id * 2 , l , mid , u , v , val),
		update(id * 2 + 1 , mid , r , u , v , val);
	}
	if(st[id].fi == 0) st[id].se = st[id * 2].se + st[id * 2 + 1].se;
	else st[id].se = Y[r - 1] - Y[l - 1];
	//cout << l << ' ' << r << ' ' << u << ' ' << v << ' ' << st[id].se << '\n';
}

int main() {
	//file();
	cin >> n;
	if(n <= 10) {
		sub1::solve();
		return 0;
	}
	
	for(int i = 1 , m ; i <= n ; i++) {
		int x = -inf , y = inf , u = inf , v = -inf;
		cin >> m;
		for(int j = 1 ; j <= m ; j++) {
			int xx , yy; cin >> xx >> yy;
			x = max(x , xx);
			u = min(u , xx);
			y = min(y , yy);
			v = max(v , yy);
		}
		Y.pb(y) , Y.pb(v);
		Q.pb(mp(mp(u , 1) , mp(y , v)));
		Q.pb(mp(mp(x , -1) , mp(y , v)));
	}
	sort(Q.begin() , Q.end());
	sort(Y.begin() , Y.end());
	Y.erase(unique(Y.begin() , Y.end()) , Y.end());
	for(int i = 0 ; i < Y.size() ; i++) pos[Y[i]] = i + 1;
	for(int i = 0 ; i < Q.size() - 1 ; i++) {
		update(1 , 1 , Y.size() , pos[Q[i].se.fi] , pos[Q[i].se.se] , Q[i].fi.se);
		//cout << Q[i].fi.fi << ' ' << Q[i].fi.se << ' ' << Q[i].se.fi << ' ' << Q[i].se.se << ' ' << pos[Q[i].se.fi] << ' ' << pos[Q[i].se.se] << ' ' << st[1].se << '\n';
		ans = ans + 1LL * (Q[i + 1].fi.fi - Q[i].fi.fi) * st[1].se;
	}
	cout << ans;
	return 0;
}


