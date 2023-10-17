#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 3e5 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

int n , t , a[N] , b[N] , st[4 * N];
vector<int> pos[N];

int get(int id , int l , int r , int u) {
	if(l > u) return inf;
	if(r <= u) 
		return st[id];
	int mid = (l + r) / 2;
	return min(get(id * 2 , l , mid , u) , get(id * 2 + 1 , mid + 1 , r , u));
}

void update(int id , int l , int r , int u , int val) {
	if(l > u || r < u) return;
	if(l == r) {
		st[id] = val;
		return ;
	}
	int mid = (l + r) / 2;
	update(id * 2 , l , mid , u , val);
	update(id * 2 + 1 , mid + 1 , r , u , val);
	st[id] = min(st[id * 2] , st[id * 2 + 1]);
}

bool solve() {
	cin >> n;
	for(int i = 1 ; i <= n ; i++)	cin >> a[i] , pos[i].clear();
	for(int i = 1 ; i <= n ; i++)	cin >> b[i];
	for(int i = n ; i >= 1 ; i--)	pos[a[i]].pb(i);
	for(int i = 1 ; i <= 4 * n ; i++)	st[i] = inf;
	for(int i = 1 ; i <= n ; i++) 
		if(pos[i].size()) update(1 , 1 , n , i , pos[i].back());
	for(int i = 1 , P ; i <= n ; i++) {
		if(pos[b[i]].empty()) return false;
		P = pos[b[i]].back();
		pos[b[i]].pop_back();
		if(get(1 , 1 , n , b[i]) < P) return false;
		update(1 , 1 , n , b[i] , ((pos[b[i]].empty()) ? inf : pos[b[i]].back()));
	}
	return true;
}

int main() {
	cin >> t;
	while(t--) 
		cout << ((solve()) ? "YES" : "NO") << '\n';
	return 0;
}

