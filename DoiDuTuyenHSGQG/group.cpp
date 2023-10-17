#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>

const ll N = 1e5 + 5 , MOD = 1e9 + 7 , inf = 1e15;

void file() {
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll t , n , k , R , ans , d , c , g , pos[N] , s[N];
pi bit[N];
vector<pi> num;

void update(int u , ll x) {
	for(int i = u ; i <= n ; i += (i & (-i))) bit[i].fi += x , bit[i].se++;
}

pi get(int u) {
	pi tmp = {0 , 0};
	for(int i = u ; i >= 1 ; i -= (i & (-i))) tmp.fi += bit[i].fi , tmp.se += bit[i].se;
	return tmp;
}

bool check(ll g , ll m) {
	ll l = 1 , r = n , id = 0 , mid;
	while(l <= r) {
		mid = (l + r) / 2;
		if(num[mid].fi <= g) id = mid , l = mid + 1;
		else r = mid - 1;
	} 
	pi res = get(id);
	if(res.fi + (m - res.se) * g >= g * k) return true;
	return false;
}

void solve() {
	cin >> n >> k >> R;
	num.clear()	, num.pb({0 , 0});
    for(int i = 1 ; i <= n ; i++) bit[i] = {0 , 0};
    memset(pos , 0 , sizeof(pos));
	ans = 0;
	for(int i = 1 ; i <= n ; i++) cin >> s[i] , num.pb({s[i] , i});
	sort(num.begin() , num.end());
	for(int i = 1 ; i < num.size() ; i++) pos[num[i].se] = i;
	for(int i = 1 ; i <= n ; i++) {
		update(pos[i] , s[i]);
		if(i <= R) continue;
		d = ans + 1 , c = 1e14;
		while(d <= c) {
			g = (d + c) / 2;
			if(check(g , i)) d = g + 1 , ans = g;
			else c = g - 1;
		}
		cout << ans << ' ';
	}
	cout << '\n';
}

int main() {
	file();
 cin >> t;
 while(t--) solve();
 return 0;
}

