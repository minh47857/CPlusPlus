#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
    freopen("FLIP.inp" , "r" , stdin);
	freopen("FLIP.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , m , nn , a[N] , b[N] , c[N] , bit[N] , st[4 * N];
pi p[N];
vector<int> query[N] , V;
map<int , int> pos;

void update1(int id , int l , int r , int pos , int val) {
	if(l > pos || r < pos) return;
	if(l == r) {
		st[id] = val;
		return;
	}
	int mid = (l + r) / 2;
	update1(id * 2 , l , mid , pos , val);
	update1(id * 2 + 1 , mid + 1 , r , pos , val);
	st[id] = max(st[id * 2] , st[id * 2 + 1]);
}

int get1(int id , int l , int r , int u , int v) {
	if(r < u || l > v) return 0;
	if(u <= l && r <= v) {
		return st[id];
	}
	int mid = (l + r) / 2;
	get1(id * 2 , l , mid , u , v); 
	return max(get1(id * 2 , l , mid , u , v) , get1(id * 2 + 1 , mid + 1 , r , u , v));
}

void update2(int u) {
	for( ; u >= 1 ; u -= (u & (-u)))
		bit[u]++;
}

int get2(int u) {
	int res = 0;
	for( ; u <= nn ; u += (u & (-u)))
		res += bit[u];
	return res;
}

int main() {
	file();
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++) {
		cin >> a[i] >> b[i];
		V.pb(a[i]);
		V.pb(b[i]);
	}
	for(int i = 1 ; i <= m ; i++) 
		cin >> c[i] , V.pb(c[i]) , p[i] = {c[i] , i};
	sort(p + 1 , p + m + 1);
	sort(V.begin() , V.end());
	V.erase(unique(V.begin() , V.end()) , V.end());
	nn = V.size();
	for(int i = 0 ; i < V.size() ; i++)
		pos[V[i]] = i + 1;
	for(int i = 1 ; i <= m ; i++)
		update1(1 , 1 , nn , pos[p[i].fi] , p[i].se) ;
	for(int i = 1 ; i <= n ; i++) {
		int val =  get1(1 , 1 , nn , pos[min(a[i] , b[i])] , pos[max(a[i] , b[i])] - 1) + 1;
		if(val == m + 1) {
			if(a[i] < b[i]) swap(a[i] , b[i]);
		}
		else query[val].pb(i);
	}
	for(int i = m ; i >= 1 ; i--) {
		update2(pos[c[i]]);
		for(auto id : query[i]) {
			if(i != 1 && a[id] < b[id]) swap(a[id] , b[id]);
			int NumSwap = get2(pos[max(a[id] , b[id])]);
			if(NumSwap % 2) swap(a[id] , b[id]);
		}
	}
	for(int i = 1 ; i <= n ; i++)
		cout << a[i] << ' ';
	return 0;
}


