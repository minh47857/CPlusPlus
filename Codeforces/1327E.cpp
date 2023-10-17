#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const ll N = 1e6 + 5 , MOD = 998244353 , inf = 1e9 + 7;

ll ans , n , Pow[N];

int main() {
	cin >> n;
	Pow[0] = 1;
	for(int i = 1 ; i <= n ; i++)
		Pow[i] = Pow[i - 1] * 10 % MOD;
	for(int len = 1 ; len <= n ; len++) {
		if(len == n) cout << 10 << ' ';
		else if(len == n - 1) cout << 180 << ' ';
		else {
			ans = 18 * Pow[n - len - 1] % MOD;
			ans = (ans + 81 * (n - len - 1) * Pow[n - len - 2] % MOD) % MOD;
			cout << ans * 10 % MOD << ' ';
		}
	}
}

