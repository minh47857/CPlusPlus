#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define eps 1e-6
#define pi pair<int , int>

const int N = 2e5 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

using namespace std;

void file() {
	freopen("xaulai.inp" , "r" , stdin);
	freopen("xaulai.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

ll n , m , f[N] , inv[N] , ans = 0;

ll Pow(ll a , ll b) {
	if(b == 0) return 1;
	ll res = Pow(a , b / 2);
	res = res * res % MOD;
	if(b % 2) return res * a % MOD;
	return res;
}

ll C(int k , int x) {
	return f[x] * inv[k] % MOD * inv[x - k] % MOD;
}

int main() {
	file();
	cin >> n >> m;
	f[0] = 1 , inv[0] = 1;
	for(int i = 1 ; i <= N - 5 ; i++)
		f[i] = f[i - 1] * i % MOD;
	inv[N - 5] = Pow(f[N - 5] , MOD - 2) % MOD;
	for(int i = N - 6 ; i >= 0 ; i--)
		inv[i] = inv[i + 1] * (i + 1) % MOD;
    if(n % 2)
		for(int i = 0 ; i <= n ; i++) 
			ans = (ans + C(i , n)) % MOD;
	else 
		for(int i = 0 ; i <= n ; i += 2)
			ans = (ans + C(i , n)) % MOD;
	ans = ans * C(m , m + n) % MOD;
	cout << ans; 
}


