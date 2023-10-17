#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back

const int N = 2e5 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
    freopen("CITY.inp" , "r" , stdin);
	freopen("CITY.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

struct query {
	int l , r , id;
	bool operator > (const query&s) const {return r > s.r;}
};

int n , m , x[N] , ans[N] , bit[N];
map<int , int> last;
query q[N];
pi a[N];

void update(int u) {
	for(int i = u ; i <= n ; i += (i & (-i)))
		bit[i]++;
}

int get(int u) {
    int res = 0;
	for(int i = u ; i >= 1 ; i -= (i & (-i))) 
		res += bit[i];
	return res;
}

int main() {
	file();
	cin >> n;
	for(int i = 1 ; i <= n ; i++)
		cin >> x[i] , last[x[i]] = n + 1;
	for(int i = n ; i >= 1 ; i--) {
	    a[i] = {last[x[i]] , i};
	    last[x[i]] = i;
	}
	cin >> m;
	for(int i = 1 , l , r ; i <= m ; i++) {
		cin >> l >> r;
		q[i] = {l , r , i};
	}
	sort(q + 1 , q + m + 1 , greater<query>());
	sort(a + 1 , a + n + 1 , greater<pi>());
	int p = 1;
	for(int i = 1 ; i <= m ; i++) {
		while(p <= n && a[p].fi > q[i].r) 
			update(a[p].se) , p++;
		ans[q[i].id] = get(q[i].r) - get(q[i].l - 1);
	}
	for(int i = 1 ; i <= m ; i++)
		cout << ans[i] << '\n';
	return 0;
}


