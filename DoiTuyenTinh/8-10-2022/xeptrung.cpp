#include<bits/stdc++.h>
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back
#define Bit(x , k) ((x >> k) & 1)

using namespace std;
const int N = 1e5 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
	freopen("xeptrung.inp" , "r" , stdin);
	freopen("xeptrung.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

ll n , m , d , c = 3e9 , g , ans , a[N];

bool check(ll k) {
	ll s = 0 , res = 1;
	for(int i = 1 ; i <= n ; i++) {
		if(s + a[i] > k) res++ , s = a[i];
		else s += a[i];
	}
	return res <= m;
}

int main() {
	file();
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++) cin >> a[i] , d = max(d , a[i]);
	while(d <= c) {
		g = (d + c) / 2;
		if(check(g)) ans = g , c = g - 1;
		else d = g + 1;
	}
	cout << ans;
	return 0;
}

