#include <bits/stdc++.h>
using namespace std;

const string Fname = "CONTINUOUS";

void files() {
	if(fopen((Fname + ".inp").c_str(), "r")) {
		freopen((Fname + ".inp").c_str(), "r", stdin);
		freopen((Fname + ".out").c_str(), "w", stdout);
	}
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

#define ll long long 
#define pii pair<int, ll> 
#define fi first
#define se second
const int N = 1e5 + 5;

struct Node {
	int left = 0, right = 0, res = 0, Size = 0;
	ll val_left = LLONG_MAX, val_right = LLONG_MAX, lazy = 0;
};




Node operator + (const Node& a, const Node& b) {
	Node ans;
	if(a.res == 0 || b.res == 0) {
		if(a.res == 0) return b;
		else return a;
	}
	
	ans.Size = a.Size + b.Size;
	ans.val_left = a.val_left; ans.val_right = b.val_right;
	
	if(a.left == a.Size && a.val_right == b.val_left - 1) ans.left = a.left + b.left;
	else ans.left = a.left;
	
	if(b.right == b.Size && b.val_left - 1 == a.val_right) ans.right = a.right + b.right;
	else ans.right = b.right;
	
	int tmp = 0;
	if(a.val_right == b.val_left - 1) tmp = a.right + b.left;
	
//	cout << a.val_right << ' ' << b.val_left << ' ' << tmp << '\n'; 
		
	ans.res = max(max(a.res, b.res), tmp);
	return ans;
}

int n, m;
ll a[N];
Node st[4 * N];

void build(int id, int l, int r) {
	if(l == r) {
		st[id].Size = st[id].left = st[id].right = st[id].res = 1;
		st[id].val_left = st[id].val_right = a[l];
		st[id].lazy = 0;
		return;
	}	
	int mid = (l + r) / 2;
	build(2 * id, l, mid); build(2 * id + 1, mid + 1, r);
	st[id] = st[2 * id] + st[2 * id + 1];	
}

void down(int id) {
	ll tmp = st[id].lazy;
	
	for(int i = 0; i <= 1; ++i) {
		st[2 * id + i].lazy += tmp;
		st[2 * id + i].val_left += tmp;
		st[2 * id + i].val_right += tmp;
	}
	
	st[id].lazy = 0;
}

void update(int id, int l, int r, int u, int v, ll d) {
	if(l > v || r < u) return;
	if(u <= l && r <= v) {
		st[id].val_left += d;
		st[id].val_right += d;
		st[id].lazy += d;
		return;
	}
	down(id);
	int mid = (l + r) / 2;
	update(2 * id, l, mid, u, v, d); update(2 * id + 1, mid + 1, r, u, v, d);
	st[id] = st[2 * id] + st[2 * id + 1]; 
}
	
Node get(int id, int l, int r, int u, int v) {
	if(l > v || r < u) {
		Node tmp; 
		return tmp;
	}
	if(u <= l && r <= v) {
		return st[id];
	}
	down(id);
	int mid = (l + r) / 2;
	Node tmp = get(2 * id, l, mid, u, v);
	return tmp + get(2 * id + 1, mid + 1, r, u, v);
}	

void solve() {
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	build(1, 1, n);
	cin >> m;
	for(int i = 1, al, ar; i <= m; ++i) {
		char Qs; cin >> Qs;
		cin >> al >> ar;
		if(Qs == '+') {
			ll d; cin >> d;
			update(1, 1, n, al, ar, d);
		}
		else cout << get(1, 1, n, al, ar).res << '\n';
	}
}

int main() {
	files();
	solve();
}
