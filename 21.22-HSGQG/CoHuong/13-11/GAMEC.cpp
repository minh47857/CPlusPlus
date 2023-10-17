#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back

const ll N = 2e5 + 5 , inf = 1e15;

void file() {
    freopen("GAMEC.inp" , "r" , stdin);
	freopen("GAMEC.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll n , f[N] , a[N];

void calc(int id) {
	if(f[id] != -1) return;
	f[id] = -inf;
	ll x = id , res = 0;
	res += a[x] , x += a[x];
	if(x > n) {
		f[id] = res;
		return;
	}
	res += a[x] , x -= a[x];
	if(x <= 0) {
		f[id] = res;
		return;
	}
	calc(x);
	if(f[x] == -inf) res = -inf;
	else res = f[x] + res;
	f[id] = res;
	return;
}

int main() {
	file();
	cin >> n;
	for(int i = 2 ; i <= n ; i++) cin >> a[i];
	memset(f , -1 , sizeof(f));
	for(int i = 2 ; i <= n ; i++) calc(i);
	for(int i = 1 ; i < n ; i++) {
		a[1] = i;
		ll x = 1 , res = 0;
		res += a[x] , x += a[x];
		if(x > n) {
			cout << res << '\n';
			continue;
		}
		res += a[x] , x -= a[x];
		if(x <= 0) {
			cout << res << '\n';
			continue;
		}
		if(x == 1) {
			cout << -1 << '\n';
			continue;
		}
		if(f[x] == -inf) cout << -1 << '\n';
		else cout << res + f[x] << '\n';
	}
	return 0;
}


