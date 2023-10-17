#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>

const ll N = 1e5 + 5 , MOD = 1e9 + 7 , inf = 1e15;

void file() {
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll ans = 0 , n , t , dp[N] , fac[N] , inv[N] , x = 0;

ll mu(ll a , ll b) {
	if(b == 0) return 1;
	ll tmp = mu(a , b / 2);
	tmp = (tmp * tmp) % MOD;
	if(b % 2) return (tmp * a) % MOD;
	return tmp;
}

ll C(int k , int n) {
	return fac[n] * inv[k] % MOD * inv[n - k] % MOD;
}

int main() {
	file();
   cin >> n >> t;
   for(int i = 1 , l , r ; i <= t ; i++) {
   	cin >> l >> r;
   	dp[l]++ , dp[r + 1]--;
   }
   for(int i = 1 ; i <= n ; i++) {
   	dp[i] += dp[i - 1];
   	if(dp[i] != 0) x++;
   }
   fac[0] = 1;
   for(int i = 1 ; i <= n ; i++) fac[i] = (fac[i - 1] * i) % MOD;
   inv[n] = mu(fac[n] , MOD - 2);
   for(int i = n - 1 ; i >= 0 ; i--) inv[i] = (inv[i + 1] * (i + 1)) % MOD;
   for(int i = 0 ; i <= x ; i++) {
   	if(i % 2 == 0) ans = ( ans + (C(i , x) * fac[n - i]) % MOD) % MOD;
   	else ans = (ans - (C(i , x) * fac[n - i]) % MOD + MOD) % MOD;
   }
   cout << ans;
}

