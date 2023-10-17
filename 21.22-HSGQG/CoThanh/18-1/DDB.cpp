#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define eps 1e-6
#define pi pair<int , int>

const int N = 2e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

using namespace std;

void file() {
	freopen("DDB.inp" , "r" , stdin);
	freopen("DDB.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int t , prime[N] , dp[N];

void sieve() {
	prime[1] = 1;
	for(int i = 2 ; i <= sqrt(2e6) ; i++) {
		if(!prime[i]) for(int j = i * i ; j <= 2e6 ; j += i) prime[j] = 1;
	}
	for(int i = 1 ; i <= 2e6 ; i++)
		dp[i] = dp[i - 1] + (1 - prime[i]);
}

int main() {
	file();
	cin >> t;
	sieve();
	while(t--) {
		int n;
		cin >> n;
		cout << dp[2 * n] - dp[n] << '\n';
	}
	return 0;
}


