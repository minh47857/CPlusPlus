#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pi pair<ll , ll>

const int N = 1e5 + 5;

int k , q , a[N] , l , r;
ll d , s = 0;
pi st[4 * N];

void build(int id , int l , int r) {
	if(l == r) {
		st[id] = {a[l] , 0};
		return;
	}
	int mid = (l + r) >> 1;
	build(id * 2 , l , mid);
	build(id * 2 + 1 , mid + 1 , r);
	st[id].fi = max(st[id * 2].fi , st[id * 2 + 1].fi);
}

void dow(int id) {
	int t = st[id].se;
	st[id].se = 0;
	st[id * 2].fi += t;
	st[id * 2].se += t;
	st[id * 2 + 1].fi += t;
	st[id * 2 + 1].se += t;
}

void update(int id , int l , int r , int u , int v) {
	if(u > r || v < l) return;
	if(u <= l && v >= r) {
		st[id].fi--;
		st[id].se--;
		return;
	}
	int mid = (l + r) >> 1;
	dow(id);
	update(id * 2 , l , mid , u , v);
	update(id * 2 + 1 , mid + 1 , r , u , v);
	st[id].fi = max(st[id * 2].fi , st[id * 2 + 1].fi);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
	cin >> k >> d >> q;
	for(int i = 1 ; i <= k ; i++) 
		cin >> a[i] , s += a[i];
	build(1 , 1 , k);
	cout << max((s + d - 1) / d , st[1].fi) << '\n';
	for(int i = 1 ; i <= q ; i++) {
		cin >> l >> r, 
		update(1 , 1 , k , l , r),
		s -= (r - l + 1);
		cout << i + max((s + d - 1) / d , st[1].fi) << '\n';
	}
	return 0;
}

