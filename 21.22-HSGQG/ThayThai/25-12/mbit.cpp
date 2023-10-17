#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 4e4 + 5 , MOD = 1e9 + 7 , K = 4e4;

ll n , m , f[N] , inv[N] , p[N] , ans = 0;

ll Pow(int a , int b) {
	if(b == 0) return 1;
	ll res = Pow(a , b / 2);
	res = res * res % MOD;
	if(b % 2) return a * res % MOD;
	return res;
}

ll C(int k , int x) {
	return f[x] * inv[k] % MOD * inv[x - k] % MOD;
}

int main() {
	cin >> n >> m;
	if(m > n) swap(m , n);
	f[0] = p[0] = inv[0] = 1;
	for(int i = 1 ; i <= K ; i++) 
		f[i] = f[i - 1] * i % MOD , p[i] = p[i - 1] * 2 % MOD;
	inv[K] = Pow(f[K] , MOD - 2);
	for(int i = K - 1; i >= 1 ; i--)
		inv[i] = inv[i + 1] * (i + 1) % MOD;
	for(int i = 1 ; i <= m ; i++) {
	//	cout << i << ' ' << f[m] << ' ' << inv[i] << ' ' << inv[m - i] << ' '  << C(i , m) << ' ' << p[m - i] << ' ' << C(i , m) * Pow((p[m - i] - 1 + MOD) % MOD , n) % MOD << '\n';
		if(i % 2 == 0) ans = (ans - C(i , m) * Pow((p[m - i] - 1 + MOD) % MOD , n) % MOD + MOD) % MOD;
		else ans = (ans + C(i , m) * Pow((p[m - i] - 1 + MOD) % MOD , n) % MOD + MOD) % MOD;
	}
	cout << (Pow((p[m] - 1 + MOD) % MOD , n) - ans + MOD) % MOD;
	return 0;
}

