#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define eps 1e-6
#define pi pair<int , int>

const int N = 1e6 + 5;

using namespace std;

void file() {
	freopen("guard.inp" , "r" , stdin);
	freopen("guard.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int t , n , q , k , f[N] , s[N] , c[N]; 
ll st[4 * N];
vector<int> a[N];

void update(int id , int l , int r , int pos , ll val) {
	if(l > pos || r < pos) return;
	if(l == r) {
		st[id] = val;
		return;
	}
	int mid = (l + r) / 2;
	update(id * 2 , l , mid , pos , val);
	update(id * 2 + 1 , mid + 1 , r , pos , val);
	st[id] = min(st[id * 2] , st[id * 2 + 1]);
}

ll get(int id , int l , int r , int u , int v) {
	if(l > v || r < u) return 1e14;
	if(l >= u && r <= v) return st[id];
	int mid = (l + r) / 2;
	return min(get(id * 2 , l , mid , u , v) , get(id * 2 + 1 , mid + 1 , r , u , v));
}

void solve() {
	cin >> n >> k >> q;
	for(int i = 1 ; i <= q ; i++) cin >> s[i];
	s[1] = 0;
	for(int i = 1 ; i <= q ; i++) {
		cin >> c[i];
		a[i].clear();
		for(int j = 1 , x ; j <= c[i] ; j++) 
			cin >> x ,  a[i].pb(x);
	}
	for(int i = 1 ; i <= n ; i++) f[i] = 0;
	for(int i = 1 ; i <= 4 * n ; i++) st[i] = 1e14;
	update(1 , 0 , q , 0 , 0);
	int h = 0 , pos = 1;
	ll ans = 0;
	for(int i = 1 ; i <= q ; i++) {
		for(int j = 0 ; j < c[i] ; j++) {
			if(!f[a[i][j]]) h++;
			f[a[i][j]]++;
		}
		while(h > k) {
			for(int j = 0 ; j < c[pos] ; j++) {
				f[a[pos][j]]--;
				if(!f[a[pos][j]]) h--;
			}
			pos++;	
		}
		ans = get(1 , 0 , q , pos - 1 , i - 1);
		update(1 , 0 , q , i , ans + s[i + 1]);
	}
	cout << ans << ' ';
}

int main() {
	file();
	cin >> t >> t;
	while(t--) solve();
	return 0;
}


