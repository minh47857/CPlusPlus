#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back
#define Bit(x , k) ((x >> k) & 1)

using namespace std;
const int N = 1e6 + 5 , M = 32000 , inf = 1e9 + 7;

void file() {
	freopen("primecount.inp" , "r" , stdin);
	freopen("primecount.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int t , c[N] , f[N];

void sieve() {
	for(int i = 2 ; i <= sqrt(M) ; i++)
		if(!c[i]) for(int j = i * i ; j <= M ; j += i) c[j] = 1;
}

int main() {
	file();
	sieve();
	cin >> t;
	while(t--) {
		int l , r , ans = 0;
		cin >> l >> r;
		for(int i = 2 ; i <= M ; i++) if(!c[i]) 
			for(int j = max((l + i - 1) / i * i , i * i) ; j <= r ; j += i) 
				f[j - l + 1] = 1;
		for(int i = 1 ; i <= r - l + 1 ; i++) 
			ans += 1 - f[i] , f[i] = 0;
		cout << ans - (l == 1) << '\n';
	}
	return 0;
}

