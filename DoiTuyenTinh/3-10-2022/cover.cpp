#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e5 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("cover.inp" , "r" , stdin);
	freopen("cover.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , ans , r;
pi a[N];

int main() {
	file();
	cin >> n;
	for(int i = 1 ; i <= n ; i++) cin >> a[i].fi >> a[i].se;
	sort(a + 1 , a + n + 1);
	ans = a[1].se - a[1].fi;
	r = a[1].se;
	for(int i = 2 ; i <= n ; i++) {
		if(a[i].se <= r) continue;
		ans += a[i].se - max(a[i].fi , r);
		r = a[i].se;
	}
	cout << ans;
	return 0;
}

