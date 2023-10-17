#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll , ll>

const ll N = 1e6 + 5 , MOD = 1e9 + 19972207 , inf = 1e9 + 7;

void file() {
	freopen("divseq.inp" , "r" , stdin);
	freopen("divseq.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll n , k , ans = 1 , m = 0;
pi a[100];

ll sqr(ll x) {
	return (x * x) % MOD;
}

ll Pow(ll a , ll b) {
	if(b == 0) return 1LL;
	if(b % 2) return (a * sqr(Pow(a , b / 2))) % MOD;
	return sqr(Pow(a , b / 2));
}

ll C(ll k , ll n) {
	ll res1 = 1 , res2 = 1;
	for(ll i = n - k + 1 ; i <= n ; i++) res1 = (res1 * (i % MOD)) % MOD;
	for(ll i = 1 ; i <= k ; i++) res2 = (res2 * i) % MOD;
	return ((Pow(res2 , MOD - 2) * res1) % MOD);
}

int main() {
	file();
	cin >> n >> k;
	k--;
	for(ll i = 2 ; i <= sqrt(n) ; i++) 
		if(n % i == 0) {
			int dem = 0;
			while(n % i == 0) n /= i , dem++;
			a[++m] = {i , dem};
		}
	if(n != 1) a[++m] = {n , 1};
	for(ll i = 1 ; i <= m ; i++) ans = (ans * C(a[i].se , k + a[i].se)) % MOD;
	cout << ans;
	return 0;
}

