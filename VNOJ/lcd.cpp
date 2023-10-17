#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<ll , ll>
using namespace std;

const int N = 2e5 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , m , a[N];
ll ans , t = 1e18;
pi f[N];

int main() {
	file();
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	for(int i = 2 ; i <= n ; i++) {
		int l = a[i - 1] , r = a[i];
		if(l > r) r += m;
		f[l + 1].fi += l + 1 , f[l + 1].se++;
		f[r + 1].fi -= (l + 1) , f[r + 1].se--;
		ans += r - l;
	}
	for(int i = 1 ; i <= 2 * m ; i++) {
		f[i].fi += f[i - 1].fi;
		f[i].se += f[i - 1].se;
 	}
 	for(int i = 1 ; i <= m ; i++) 
 		t = min(t , f[i].fi - f[i].se * i + f[i + m].fi - f[i + m].se * (i + m));
 	cout << ans + t;
 	return 0;
}

