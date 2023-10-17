#include<bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 1e5 + 5;
const ll inf = 1e18;

using namespace std;

int n;
ll t[N] , st[4 * N] , f[N];
pi x[N] , y[N];
vector<int> start[N] , finish[N];

void update(int id , int l , int r , int u , ll val) {
	if(l > u || r < u) return;
	if(l == r) {
		st[id] = val;
		return;
	}
	int mid = (l + r) / 2;
	update(id * 2 , l , mid , u , val);
	update(id * 2 + 1 , mid + 1 , r , u , val);
	st[id] = min(st[id * 2] , st[id * 2 + 1]);
}

ll get(int id , int l , int r , int u , int v) {
	if(l > v || r < u) return inf;
	if(l >= u && r <= v) return st[id];
	int mid = (l + r) / 2;
	return min(get(id * 2 , l , mid , u , v) , get(id * 2 + 1 , mid + 1 , r , u , v));
}

int main() {
	//file();
	cin >> n;
	for(int i = 1 ; i <= n ; i++) {
		cin >> t[i] >> x[i].fi >> x[i].se >> y[i].fi >> y[i].se;
		if(y[i].fi == i) {
			if(y[i].se != i) start[y[i].fi + 1].pb(i) , finish[y[i].se].pb(i); 
		}
		else start[y[i].fi].pb(i) , finish[y[i].se].pb(i);
	}
	for(int i = 1 ; i <= 4 * n ; i++) st[i] = inf;
	for(int i = 2 ; i <= n ; i++) {
		for(auto j : start[i])  
			if(f[j] != inf) update(1 , 1 , n , j , f[j] + t[j] - j);
		f[i] = get(1 , 1 , n , x[i].fi , x[i].se);
		cout << ((f[i] == inf) ? -1 : (t[i] + i + f[i])) << ' ';
		if(f[i] != inf) f[i] += t[i] + i;
		for(auto j : finish[i]) update(1 , 1 , n , j , inf);
	}
	return 0;
}

