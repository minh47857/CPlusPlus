#include<bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll , ll>

const ll N = 1e5 + 5 , MOD = 1e9 + 7 , inf = 1e17;

using namespace std;

int n , q;
ll S , type[N] , h[N] , x[N] , y[N];
pi a[N];

namespace sub1 {
	ll st[4 * N] , lazy[4 * N] , f[N];
	
	void build(int id , int l , int r) {
		if(l == r) {
			st[id] = f[l];
			lazy[id] = 0;
			return;
		}
		int mid = (l + r) / 2;
		build(id * 2 , l , mid);
		build(id * 2 + 1 , mid + 1 , r);
		st[id] = max(st[id * 2] , st[id * 2 + 1]);
	}
	
	void dow(int id) {
		ll t = lazy[id];
		lazy[id] = 0;
		st[id * 2] += t;
		st[id * 2 + 1] += t;
		lazy[id * 2] += t;
		lazy[id * 2 + 1] += t;
	}
	
	void update(int id , int l , int r , int u , int v , ll val) {
		if(l > v || r < u) return;
		if(l >= u && r <= v) {
			st[id] += val;
			lazy[id] += val;
			return;
		}
		dow(id);
		int mid = (l + r) / 2;
		update(id * 2 , l , mid , u , v , val);
		update(id * 2 + 1 , mid + 1 , r , u , v , val);
		st[id] = max(st[id * 2] , st[id * 2 + 1]);
	}
	
	ll get(int id , int l , int r , int u , int v) {
		if(l > v || r < u) return -inf;
		if(l >= u && r <= v) return st[id];
		dow(id);
		int mid = (l + r) / 2;
		return max(get(id * 2 , l , mid , u , v) , get(id * 2 + 1 , mid + 1 , r , u , v));
	}
	
	void solve() {
		f[0] = 0;
		for(int i = 1 ; i <= n ; i++) 
			f[i] = f[i - 1] + a[i].se ;
		build(1 , 1 , n);
		for(int i = 1 ; i <= q ; i++) {
			if(type[i] == 1) {
				update(1 , 1 , n , h[i] , n  , y[i] - a[h[i]].se);
				a[h[i]].se = y[i];
			}
			else {
				if(1LL * h[i] >= S) {
					cout << get(1 , 1 , n , h[i] , h[i]) - max(get(1 , 1 , n , 1 , min(h[i] - 1, h[i] - S)) , 0LL) << '\n';
				}
				else 
					cout << -1 << '\n';
			}
		}
	}
}

namespace sub2 {
	ll st[4 * N] , lazy[4 * N] , f[N];
	
	void build(int id , int l , int r) {
		if(l == r) {
			st[id] = f[l];
			lazy[id] = 0;
			return;
		}
		int mid = (l + r) / 2;
		build(id * 2 , l , mid);
		build(id * 2 + 1 , mid + 1 , r);
		st[id] = min(st[id * 2] , st[id * 2 + 1]);
	}
	
	void dow(int id) {
		ll t = lazy[id];
		lazy[id] = 0;
		st[id * 2] += t;
		st[id * 2 + 1] += t;
		lazy[id * 2] += t;
		lazy[id * 2 + 1] += t;
	}
	
	void update(int id , int l , int r , int u , int v , ll val) {
		if(l > v || r < u) return;
		if(l >= u && r <= v) {
			st[id] += val;
			lazy[id] += val;
			return;
		}
		dow(id);
		int mid = (l + r) / 2;
		update(id * 2 , l , mid , u , v , val);
		update(id * 2 + 1 , mid + 1 , r , u , v , val);
		st[id] = min(st[id * 2] , st[id * 2 + 1]);
	}
	
	ll get(int id , int l , int r , int u , int v) {
		if(l > v || r < u) return inf;
		if(l >= u && r <= v) return st[id];
		dow(id);
		int mid = (l + r) / 2;
		return min(get(id * 2 , l , mid , u , v) , get(id * 2 + 1 , mid + 1 , r , u , v));
	}
	
	int go(int id , int l , int r , int u , ll val) {
		if(st[id] > val) return -1;
		if(l > u) return -1;
		if(l == r) 	return l;
		dow(id);
		int mid = (l + r) / 2 , res = -1;
		if(st[id * 2 + 1] <= val) 	
			res = go(id * 2 + 1 , mid + 1 , r , u , val);
		if(res == -1) 
			res = go(id * 2 , l , mid , u , val);
		return res;
	}
	
	void solve() {
		f[0] = 0;
		for(int i = 1 ; i <= n ; i++) 
			f[i] = f[i - 1] + a[i].fi;
		build(1 , 1 , n);
		for(int i = 1 ; i <= q ; i++) {
			if(type[i] == 1) {
				update(1 , 1 , n , h[i] , n  , x[i] - a[h[i]].fi);
				a[h[i]].fi = x[i];
			}
			else {
				ll tmp = get(1 , 1 , n , h[i] , h[i]) - S;
				int ans = go(1 , 1 , n , h[i] - 1 , tmp);
				if(ans == -1) {
					if(tmp >= 0) cout << h[i] << '\n';
					else cout << -1 << '\n';
				}
				else cout << h[i] - ans << '\n';
			}
		}
	}
}

namespace sub3 {
	int id[N];
	ll st[4 * N] , bit[N] , ans[N] , g[N];
	pi f[N];
	vector<int> query[N];
	
	void update(int u , ll val) {
		for(int i = u ; i <= n ; i += (i & (-i))) 
			bit[i] = max(bit[i] , val);
	}
	
	ll get(int u) {
		ll res = -inf;
		for(int i = u ; i >= 1 ; i -= (i & (-i)))
			res = max(res , bit[i]);
		return res;
	}
	
	int binary(ll val , int i) {
		int d = 1 , c = n , g , res = -1;
		while(d <= c) {
			g = (d + c) / 2;
			if(f[g].fi <= val) res = g , d = g + 1;
			else c = g - 1;
		}
		return res;
	}
	
	void solve() {
		int i = 1;
		for( ; i <= q ; i++) {
			if(type[i] == 2) break;
			a[h[i]] = {x[i] , y[i]};
		}
		f[0] = {0 , 0};
		for(int i = 1 ; i <= n ; i++) {
			f[i].fi = f[i - 1].fi + a[i].fi;
			f[i].se = i;
			g[i] = g[i - 1] + a[i].se;
		}
		sort(f + 1 , f + n + 1);
		for(int i = 1 ; i <= n ; i++) id[f[i].se] = i , bit[i] = -inf; 
		for( ; i <= q ; i++) {
			if(type[i] == 1) break;
			query[h[i]].pb(i);
		}
		for(int i = 1 ; i <= n ; i++) {
			if(query[i].size()) {
				ll tmp = inf;
				int pos = binary(f[id[i]].fi - S , id[i]);
				if(pos == -1) {
					if(f[id[i]].fi >= S) tmp = g[i];
					else tmp = -1;
				}
				else {
					if(f[id[i]].fi >= S) tmp = g[i];
					ll val = get(pos);
					if(val != -inf) tmp = min(tmp , g[i] - val);
					if(tmp == inf) tmp = -1;
				}
				for(auto x : query[i]) ans[x] = tmp;
			}
			update(id[i] , g[i]);
		}
		for(int i = 1 ; i <= q ; i++) 
			if(type[i] == 2) cout << ans[i] << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
	bool sub1 = true , sub2 = true;
	cin >> n >> S;
	for(int i = 1 ; i <= n ; i++) cin >> a[i].fi , sub1 &= (a[i].fi == 1);
	for(int i = 1 ; i <= n ; i++) cin >> a[i].se , sub2 &= (a[i].se == 1);
	cin >> q;
	for(int i = 1 ; i <= q ; i++) {
		cin >> type[i] >> h[i];
		if(type[i] == 1) {
			cin >> x[i] >> y[i];
			sub1 &= (x[i] == 1);
			sub2 &= (y[i] == 1);
		}
	}
	if(sub1) sub1::solve();
	else if(sub2) sub2::solve();
	else sub3::solve();
	return 0;
}
