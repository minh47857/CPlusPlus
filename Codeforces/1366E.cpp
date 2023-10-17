#include<bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 2e5 + 5 , MOD =  998244353 , inf = 1e9 + 7;

using namespace std;

int n , m , a[N] , b[N] , f[N] , ans = 1;
pi s[N];
map<int , int> pos;

int binary(int x) {
	int d = 1 , c = n , g , res = -1;
	while(d <= c) {
		g = (d + c) / 2;
		if(s[g].fi < x) res = g , d = g + 1;
		else c = g - 1;
	}
	return f[res];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++) cin >> a[i] , pos[a[i]] = i;
	for(int i = 1 ; i <= m ; i++) cin >> b[i];
	for(int i = 1 ; i <= n ; i++) s[i] = {a[i] , i};
	sort(s + 1 , s + n + 1);
	if(s[1].fi != b[1]) {
		cout << 0;
		return 0;
	}
	for(int i = 1 ; i <= n ; i++) 
		f[i] = max(f[i - 1] , s[i].se);
	for(int i = 1 , posr , posl ; i < m ; i++) {
		posr = pos[b[i + 1]];
		posl = binary(b[i + 1]);
		if(posr == 0 || posl > posr) {
			cout << 0;
			return 0;
		}
		ans = 1LL * ans * (posr - posl) % MOD;
	}
	cout << ans;
	return 0;
}

