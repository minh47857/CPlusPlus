#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back
#define Bit(x , k) ((x >> k) & 1)

using namespace std;
const int N = 1e3 + 5 , M = 1e6 + 5, inf = 1e9 + 7;

void file() {
	freopen("tera.inp" , "r" , stdin);
	freopen("tera.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int n , L , a[N] , b[N] , c[N] , d[N] , x[M] , y[M];
ll ans;
vector<pi> u , v;

int main() {
	//file();
	cin >> n >> L;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	for(int i = 1 ; i <= n ; i++) cin >> b[i];
	for(int i = 1 ; i <= n ; i++) cin >> c[i];
	for(int i = 1 ; i <= n ; i++) cin >> d[i];
	for(int i = 1 ; i <= n ; i++)
		for(int j = 1 ; j <= n ; j++)
			x[(i - 1) * n + j] = a[i] + b[j];
	for(int i = 1 ; i <= n ; i++)
		for(int j = 1 ; j <= n ; j++)
			y[(i - 1) * n + j] = c[i] + d[j];
	sort(x + 1 , x + n * n + 1);
	sort(y + 1 , y + n * n + 1 , greater<int>());
	for(int i = 1 ; i <= n * n ; i++) {
		int dem = 1;
		while(i < n * n && x[i] == x[i + 1]) i++ , dem++;
		v.pb({x[i] , dem});
	}
	for(int i = 1 ; i <= n * n ; i++) {
		int dem = 1;
		while(i < n * n && y[i] == y[i + 1]) i++ , dem++;
		u.pb({y[i] , dem});
	}
	int l = 0;
	for(auto i : v) {
		while(l < u.size() - 1 && i.fi + u[l].fi > L) l++;
		if(i.fi + u[l].fi == L) ans += 1LL * i.se * u[l].se;
	}
	cout << ans;
	return 0;
}

