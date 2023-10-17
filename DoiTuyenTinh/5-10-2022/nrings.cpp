#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<ll , ll>
using namespace std;

const int N = 1e5 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("nrings.inp" , "r" , stdin);
	freopen("nrings.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll n , a[N] , s[N] , presum;
pi p[N];

int main() {
//	file();
	cin >> n;
	for(int i = 1 ; i <= n ; i++) cin >> s[i];
	if(n % 3 == 0) {
		a[1] = 1 , a[2] = 1 , a[3] = s[2] - 2;
		for(int i = 4 ; i <= n ; i++) a[i] = a[i - 3] + s[i - 1] - s[i - 2];
	} else {
		p[1].fi = 1;
		a[1] = s[2];
		for(int i = 2 ; i <= n ; i++) {
			p[i].fi = (p[i - 1].fi + 3) % n;
			if(!p[i].fi) p[i].fi = n;
			if(p[i - 1].fi == n) p[i].se = s[p[i].fi - 1] - s[1];
			else p[i].se = s[p[i].fi - 1] - s[p[i - 1].fi + 1];
			presum += p[i].se;
			if(p[i].fi == 2 || p[i].fi == 3) a[1] -= presum; 
		}
		a[1] /= 3;
		for(int i = 2 ; i <= n ; i++) a[p[i].fi] = a[p[i - 1].fi] + p[i].se;
	}
	for(int i = 1 ; i <= n ; i++) cout << a[i] << '\n';
	return 0;
}

