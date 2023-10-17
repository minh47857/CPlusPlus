#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const ll N = 100, MOD = 1e9 + 7 , inf = 1e11;

void file() {
	freopen("group0.inp" , "r" , stdin);
	freopen("group0.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll n , k , a[N];

bool check(ll x) {
	ll s = 0;
	for(int i = 1 ; i <= n ; i++) 
		if(a[i] >= x) s += x; else s += a[i];
	if(s >= x * k) return true;
	return false;
}

int main() {
	file();
	cin >> n >> k;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	ll d = 0 , c = inf , g , ans = 0;
	while(d <= c) {
		g = (d + c) / 2;
		if(check(g)) d = g + 1 , ans = g;
		else c = g - 1;
	}
	cout << ans;
	return 0;
}

