#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
    freopen("paper.inp" , "r" , stdin);
	freopen("paper.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll n , m , a[N];

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
	cin >> m >> n;
	for(int i = 1 ; i <= n ; i++) 
		cin >> a[i] , m -= (a[i] - 1);
	cout << C(n - 1 , m - 1);
	return 0;
}


