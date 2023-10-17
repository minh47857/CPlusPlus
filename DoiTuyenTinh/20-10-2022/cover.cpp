#include<bits/stdc++.h>
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define Bit(x , k) ((x >> k) & 1)

using namespace std;
const int N = 1e5 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
	freopen("cover.inp" , "r" , stdin);
	freopen("cover.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie() ; cout.tie(0);
}

int n , x , y , ans , f[N];
pi a[N];

int main() {
	file();
	cin >> n >> x >> y;
	for(int i = 1 ; i <= n ; i++) cin >> a[i].fi >> a[i].se;
	sort(a + 1 , a + n + 1);
	for(int i = 1 ; i <= n ; i++) f[i] = max(f[i - 1] , a[i].se);
	while(x < y) {
		int d = 1 , c = n , g , pos = -1;
		while(d <= c) {
			g = (d + c) / 2;
			if(a[g].fi <= x) pos = g , d = g + 1;
			else c = g - 1;
		}
		if(pos == -1 || x == f[pos]) {
			cout << -1;
			return 0;
		}
		x = f[pos];
		ans++;
	}
	cout << ans;
	return 0;
}

