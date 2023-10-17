#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e5 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , q , a[N];
pi st[4 * N];

void dow(int id , int l , int r) {
	int mid = (l + r) / 2;
	st[id * 2].se ^= st[id].se;
	st[id * 2 + 1].se ^= st[id].se;
	if(st[id].se) st[id * 2].fi = (mid - l + 1 - st[id * 2].fi);
	if(st[id].se) st[id * 2 + 1].fi =(r - mid - st[id * 2 + 1].fi);
	st[id].se = 0;
}

void update(int id , int l , int r , int u , int v) {
	if(v < l || r < u) return;
	if(l >= u && r <= v) {
		st[id].se ^= 1 , st[id].fi = (r - l + 1 - st[id].fi); 
		return;
	}
	dow(id , l , r);
	int mid = (l + r) / 2;
	update(id * 2 , l , mid , u , v);
	update(id * 2 + 1 , mid + 1 , r , u , v);

	st[id].fi = st[id * 2].fi + st[id * 2 + 1].fi;
}

int get(int id , int l , int r , int u , int v) {
	if(v < l || r < u) return 0;
	if(l >= u && r <= v) return st[id].fi;
	dow(id , l , r);
	int mid = (l + r) / 2;
	return get(id * 2 , l , mid , u , v) + get(id * 2 + 1 , mid + 1 , r , u , v);
}

int main() {
	file();
	cin >> n >> q;
	update(1 , 0 , n , 0 , 0);
	for(int i = 1 , s = 0 ; i <= n ; i++) {
		cin >> a[i];
		s += a[i] % 2;
		if(s % 2 == 0) update(1 , 0 , n , i , i);
	}
	while(q--) {
		int k , l , r , odd , even;
		cin >> k >> l >> r;
		if(k == 1) {
			if(abs(a[l] - r) % 2) update(1 , 0 , n , l , n);
			a[l] = r;
		}
		if(k == 2) {
			even = get(1 , 0 , n , l - 1 , r);
			odd = r - l + 2 - even;
			cout << 1LL * odd * (odd - 1) / 2 + 1LL * even * (even - 1) / 2 << '\n';
		} 
	}
	return 0;
}

