#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back

const int N = 2e5 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
    freopen("STONES.inp" , "r" , stdin);
	freopen("STONES.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , m , t , w , p , res;
pi st[4 * N];
set<int> s[N];

pi Max(pi a , pi b) {
	if(a.fi < b.fi) return b;
	return a;
}

void update(int id , int l , int r , int pos , int val) {
	//cout << id << ' ' << l << ' ' << r << '\n';
	if(l > pos || r < pos) return;
	if(l == r) {
		if(val < 0) s[l].erase(-val);
		else s[l].insert(val);
		st[id] = {*s[l].begin() , l};
		return;
	}
	int mid = (l + r) / 2;
	update(id * 2 , l , mid , pos , val);
	update(id * 2 + 1 , mid + 1 , r , pos , val);
	st[id] = Max(st[id * 2] , st[id * 2 + 1]);
}

int main() {
	file();
	cin >> m >> n;
	for(int i = 1 ; i <= m ; i++) {
		cin >> t;
		if(t == 1) {
			cin >> p >> w;
			update(1 , 1 , n , p , w);
		}
		else {
			cout << st[1].fi << '\n';
			update(1 , 1 , n , st[1].se , -st[1].fi);
		}
	}
	return 0;
}
/*
9 2
1 1 9
1 2 3
1 1 4
2
1 1 2
1 2 5
2
2
1 2 1
*/

