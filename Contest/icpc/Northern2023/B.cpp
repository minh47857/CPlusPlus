#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define eps 1e-6
#define pi pair<ll , ll>
#define mp make_pair

const int N = 5e5 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

using namespace std;

ll n , m , r, ans;
pi st[4 * N];
map<ll , ll> pos;
vector<pair<pair<ll , ll> , pair<ll , ll>>> Q;
vector<ll> Y;

void update(int id , int l , int r , int u , int v , ll val) {
	if(l > v || r < u) return;
	if(l >= u && r <= v) {
        st[id].fi += val;
    }
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
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	cin >> r >> n;
    ll pre_x = 0, pre_y = 0;
    Y.pb(0), Y.pb(r);
    Q.pb(mp(mp(0, 1), mp(0,r)));
    Q.pb(mp(mp(r, -1), mp(0,r)));
	for(int i = 1; i <= n ; i++) {
		char c;
        ll A, x, y, u, v;
        cin >> c >> A;
        if(c == 'E') {
            x = pre_x + r + A;
            u = pre_x;
            y = pre_y;
            v = pre_y + r;
            pre_x = pre_x + A;
        }
        if(c == 'W') {
            x = pre_x + r;
            u = pre_x - A;
            y = pre_y;
            v = pre_y + r;
            pre_x = pre_x - A;
        }
        if(c == 'N') {
            x = pre_x + r;
            u = pre_x;
            y = pre_y;
            v = pre_y + r + A;
            pre_y = pre_y + A;
        }
        if(c == 'S') {
            x = pre_x + r;
            u = pre_x;
            y = pre_y - A;
            v = pre_y + r;
            pre_y = pre_y - A;
        }
		// m = 2;
		// for(int j = 1 ; j <= m ; j++) {
		// 	int xx , yy; cin >> xx >> yy;
		// 	x = max(x , xx);
		// 	u = min(u , xx);
		// 	y = min(y , yy);
		// 	v = max(v , yy);
		// }
		Y.pb(y) , Y.pb(v);
		Q.pb(mp(mp(u , 1) , mp(y , v)));
		Q.pb(mp(mp(x , -1) , mp(y , v)));
	}
	sort(Q.begin() , Q.end());
	sort(Y.begin() , Y.end());
	Y.erase(unique(Y.begin() , Y.end()) , Y.end());
	for(int i = 0 ; i < (int)Y.size() ; i++) pos[Y[i]] = i + 1;
	for(int i = 0 ; i < (int)Q.size() - 1 ; i++) {
		update(1 , 1 , Y.size() , pos[Q[i].se.fi] , pos[Q[i].se.se] , Q[i].fi.se);
		ans = ans + 1LL * (Q[i + 1].fi.fi - Q[i].fi.fi) * st[1].se;
	}
	cout << ans;
	return 0;
}