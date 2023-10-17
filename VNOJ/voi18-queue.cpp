#include<bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 5e4 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

using namespace std;

int t , n , m;
pi a[N] , b[N];

void file() {
	//freopen("queue.inp" , "r" , stdin);
	//freopen("queue.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

bool cmp(pi x , pi y) {
	return x.se < y.se;
}

bool check(int x) {
	set<int> s;
	for(int i = 1 ; i <= x ; i++) b[i] = a[i];
	sort(b + 1 , b + x + 1 , cmp);
	for(int i = 1 ; i <= m ; i++) s.insert(i);
	for(int i = 1 ; i <= x ; i++) {
		if(s.empty() || *s.rbegin() < b[i].fi) return false;
		auto it = s.lower_bound(b[i].fi);
		if(*it > b[i].se) return false;
		s.erase(it);
	}
	return true;
}

void solve() {
	cin >> m >> n;
	for(int i = 1 ; i <= n ; i++) 
		cin >> a[i].fi >> a[i].se;
	int d = 1 , c = n , g , ans;
	while(d <= c) {
		g = (d + c) / 2;
		if(check(g)) d = g + 1 , ans = g;
		else c = g - 1;
	}
	cout << ans << '\n';
}

int main() {
	file();
	cin >> t;
	while(t--) solve();
	return 0;
}

