#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

ll t , n , a[N] , f[N] , g[N] , ip[N] , ans , e;

void sieve() {
	ip[1] = 1;
	for(int i = 2 ; i < sqrt(N) ; i++) if(!ip[i]) 
		for(int j = i * i ; j < N ; j += i)
				ip[j] = 1;
}

int main() {
	sieve();
	cin >> t;
	while(t--) {
		ans = 0;
		cin >> n >> e;
		for(int i = 1 ; i <= n ; i++) 
			cin >> a[i];
		for(int i = 1 ; i <= e + n ; i++)
			f[i] = g[i] = 0;
		for(int i = 1 ; i <= n ; i++) 
			if(a[i] != 1) f[i] = 0;
			else f[i] = f[i - e] + 1;
		for(int i = n ; i >= 1 ; i--)
			if(a[i] != 1) g[i] = 0;
			else g[i] = g[i + e] + 1;
		for(int i = 1 ; i <= n ; i++) if(!ip[a[i]]) {
			ans = ans + (f[i - e] + 1) * (g[i + e] + 1) - 1;
		}
		cout << ans << '\n';
	}
}

