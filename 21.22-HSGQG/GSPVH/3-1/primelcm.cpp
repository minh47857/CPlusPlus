#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define eps 1e-6
#define pi pair<ll , int>

const int N = 1e5 + 5 , MOD = 998244353;

using namespace std;

void file() {
	freopen("primelcm.inp" , "r" , stdin);
	freopen("primelcm.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int ip[10000005] , n , f[N] , ans[N];
pi a[N];
vector<int> prime;

void sieve() {
	for(int i = 2 ; i <= sqrt(1e7) ; i++) {
		if(!ip[i]) for(int j = i * i ; j <= 1e7 ; j += i) ip[j] = 1;
	}
	for(int i = 2 ; i <= 1e7 ; i++) 
		if(!ip[i]) prime.pb(i);
}

int main() {
	file();
	sieve();
	cin >> n;
	f[0] = 1;
	for(int i = 1 ; i <= n ; i++) {
		ll x;
		cin >> x;
		a[i] = {x , i};
		f[i] = 1;
	}
	sort(a + 1 , a + n + 1);
//	ll A = 1;
//	for(ll x : prime) {
//		ll p = 1LL * x * x;
//		while(p <= a[1].fi) {
//			p *= x;
//		}
//		A = A * p % MOD; 
//	}
//	cout << A << '\n';
	for(int x : prime) {
		ll  p = 1LL * x * x;
		int d , c , g , res = 1;
		while(p <= 1e14) {
			d = res , c = n;
			res = -1;
			while(d <= c) {
				g = (d + c) /2;
				if(a[g].fi >= p) c = g - 1 , res = g;
				else d = g + 1;
			}
			if(res == -1) break;
			f[res] = 1LL * f[res] * x % MOD;
			if(p > 1e15 / x) break;
			p *= x;
		}
	}
//	for(int i = 1 ; i <= n ; i++)	cout << f[i] << ' ';
	for(int i = 1 ; i <= n ; i++)
   		 f[i] = 1LL * f[i - 1] * f[i] % MOD , ans[a[i].se] = f[i];
   	for(int i = 1 ; i <= n ; i++)	cout << ans[i] << ' ';
   	return 0;
}


