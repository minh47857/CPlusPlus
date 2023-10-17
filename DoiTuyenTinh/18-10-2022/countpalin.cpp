#include<bits/stdc++.h>
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define Bit(x , k) ((x >> k) & 1)

using namespace std;
const int N = 2e6 , M = 5e6 + 5 , inf = 1e9;

void file() {
	freopen("countpalin.inp" , "r" , stdin);
	freopen("countpalin.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie() ; cout.tie(0);
}

int t , m;
ll l , r , ans , a[M];

void solve() {
	for(int i = 1 ; i <= N ; i++) {
		ll x = i , y = i , p = i / 10;
		while(y) x = x * 10 + y % 10 , p = p * 10 + y % 10 , y /= 10;
		a[++m] = x;
		a[++m] = p;
	}
}

int main() {
	file();
	solve();
	while(cin >> l >> r) {
		ans = 0;
		for(int i = 1 ; i <= m ; i++) 
			if(a[i] >= l && a[i] <= r) ans++;
		cout << ans << '\n';
	}
}

