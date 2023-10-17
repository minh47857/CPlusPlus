#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 3e4 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("thamquan.inp" , "r" , stdin);
	freopen("thamquan.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , m , res[N];
pi d[N] , v[N];
ll ans;

int main() {
	file();
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++) cin >> d[i].fi , d[i].se = i;
	for(int i = 1 ; i <= m ; i++) cin >> v[i].fi , v[i].se = i;
	sort(d + 1 , d + n + 1);
	sort(v + 1 , v + m + 1);
	for(int i = 1 ; i <= n ; i++) {
		ans += 1ll * d[i].fi * v[n - i + 1].fi;
		res[d[i].se] = v[n - i + 1].se;
	}
	cout << ans << '\n';
	for(int i = 1 ; i <= n ; i++) cout << res[i] << '\n';
	return 0;
}

