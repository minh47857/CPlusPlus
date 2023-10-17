#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back

const int N = 1e5 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

using namespace std;

void file() {
	freopen("VISIT.inp" , "r" , stdin);
	freopen("VISIT.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int n , m;
ll a[N];

bool check(ll x) {
	int cnt = 0;
	ll s = 0;
	for(int i = 1 ; i <= n ; i++) {
		if(s + a[i] > x) {
			cnt++ , s = a[i];
			if(s > x) return false;
		}
		else s += a[i];
	}
	cnt++;
	return cnt <= m;
}

int main() {
	file();
	cin >> n >> m;
	n++;
	m++;
	for(int i = 1 , x ; i <= n ; i++)
		cin >> a[i];
	ll d = 0 , c = 1e14 , g , ans;
	while(d <= c) {
		g = (d + c) / 2;
		if(check(g)) ans = g , c = g - 1;
		else d = g + 1;
	}
	cout << ans;
	return 0;
}


