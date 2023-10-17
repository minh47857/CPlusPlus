#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

ll a[1005] , n , Max = 0;

namespace sub2 {
	int ans = 0 , f[N];
	void solve() {
		memset(f , 0 , sizeof(f));
		for(int i = 1 ; i <= n ; i++) {
			int x = a[i];
			for(int j = 2 ; j <= sqrt(x) ; j++) {
				if(x % j != 0) continue;
				while(x % j == 0) 
					x /= j;
				f[j]++;
				ans = max(ans , f[j]);
			}
			if(x != 1) {
				f[x]++;
				ans = max(ans , f[x]);
			}
		}
		cout << ans;
	}
	
}

namespace sub3 {
	int ans = 0 , ip[N] , f[N];
	vector<ll> Prime , s;
	void sieve() {
		for(int i = 2 ; i <= sqrt(1e6) ; i++) {
			if(!ip[i]) 
				for(int j = i * i ; j <= 1e6 ; j += i)
						ip[j] = 1;
		}
		for(int i = 2 ; i <= 1e6 ; i++) 
			if(!ip[i]) Prime.pb(i);
	}
	
	void solve() {
		sieve();
		for(int i = 1 ; i <= n ; i++) {
			for(int j : Prime) {
				if(a[i] % j != 0) continue;
				while(a[i] % j == 0) a[i] /= j;
				f[j]++;
				ans = max(ans , f[j]);
			}
		}
		for(int i = 1 ; i <= n ; i++)
			for(int j = i + 1 ; j <= n ; j++) {
				ll x = __gcd(a[i] , a[j]);
				if(x != 1) s.pb(x);
			}
		sort(s.begin() , s.end());
		s.erase(unique(s.begin() , s.end()) , s.end());
		for(auto x : s) {
			int tmp = 0;
			for(int i = 1 ; i <= n ; i++)
				if(a[i] % x == 0) tmp++;
			ans = max(ans , tmp);
		}
		cout << ans;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
	cin >> n;
	for(int i = 1 ; i <= n ; i++) 
		cin >> a[i] , Max = max(a[i] , Max);
//	if(Max <= 1e6) sub2::solve();
    sub3::solve();
}

