#include<bits/stdc++.h>
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define Bit(x , k) ((x >> k) & 1)
#define pb push_back

using namespace std;
const int N = 2e5 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
	freopen("max.inp" , "r" , stdin);
	freopen("max.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie() ; cout.tie(0);
}

int n , m;
ll bit[N];
pi a[N];
map<int , int> pos;
vector<int> v;

void update(int i , ll val) {
	for( ; i <= m ; i += (i & (-i))) bit[i] = max(bit[i] , val);
}

ll get(int i) {
	ll res = 0;
	for( ; i >= 1 ; i -= (i & (-i))) res = max(res , bit[i]);
	return res;
}

int main() {
	file();
	cin >> n;
	for(int i = 1 ; i <= n ; i++) cin >> a[i].fi >> a[i].se , v.pb(a[i].fi) , v.pb(a[i].se);
	sort(v.begin() , v.end());
	v.erase(unique(v.begin() , v.end()) , v.end());
	m = v.size();
	for(int i = 0 ; i < m ; i++) pos[v[i]] = i + 1;
	sort(a + 1 , a + n + 1);
	for(int i = 1 , l , r ; i <= n ; i++) {
		l = pos[a[i].fi] , r = pos[a[i].se];
		ll tmp = get(l);
		update(r , tmp + a[i].se - a[i].fi);
	}
	cout << get(m);
	return 0;
}

