#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

ll n , m , k , Pow = 1 , dp[N] , f[N];

void file(){
    freopen("painting.inp" , "r" , stdin);
    freopen("painting.out" , "w" , stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main() {
	file();
	cin >> n >> m >> k;
	for(int i = 1 ; i <= k - 1 ; i++)
		Pow = (Pow * m) % MOD , dp[i] = Pow , f[i] = (f[i - 1] + dp[i]) % MOD;
	for(int i = k  ; i <= n ; i++) {
		Pow = (Pow * m) % MOD;
		dp[i] = (m - 1) * ((f[i - 1] - f[i - k] + MOD) % MOD) % MOD;
		f[i] = (f[i - 1] + dp[i]) % MOD;
	}
	cout << (Pow - dp[n] + MOD) % MOD;
	return 0;
}

