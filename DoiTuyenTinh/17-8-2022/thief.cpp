#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<ll , ll>
#define Bit(x , k) ((x >> k) & 1)
using namespace std;

const int N = 25 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("thief.inp" , "r" , stdin);
	freopen("thief.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll n , m , ans;
pi a[N];

int main() {
	file();
	cin >> n >> m;
	for(int i = 1 ; i <= m ; i++) cin >> a[i].se >> a[i].fi;
	sort(a + 1 , a + m + 1 , greater<pi>());
	for(int i = 1 ; i <= m ; i++) {
		ans += min(n , a[i].se) * a[i].fi;
		n -= min(n , a[i].se);
	}
	cout << ans;
	return 0;
}

