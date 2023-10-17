#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const ll N = 1e5 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll n , m , x[N] , y[N] , ans;

ll solve(ll a[] , int k) {
	ll res = 0;
	for(int i = 1 ; i < k ; i++) res = (res + (a[i + 1] - a[i]) * i * (k - i) % MOD) % MOD;
	return res;
}

int main() {
	file();
		cin >> n >> m;
		for(int i = 1 ; i <= n ; i++) cin >> x[i];
		for(int i = 1 ; i <= m ; i++) cin >> y[i];
		ans = (solve(x , n) * solve(y , m)) % MOD;
		cout << ans;
		return 0;
}

