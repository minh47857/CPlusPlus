#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("carrays.inp" , "r" , stdin);
	freopen("carrays.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , m , k;
ll dp[N] , ans = 1 , pre;

int main() {
	file();
	cin >> n >> m >> k;
	k = min(n , k);
	dp[1] = m;
	ans = m;
	pre = m;
	for(int i = 2 ; i < k ; i++) {
		ans = (ans * m) % MOD;
		dp[i] = (pre * (m - 1) + m) % MOD;
		pre = (dp[i] + pre) % MOD;
	}
	for(int i = k ; i <= n ; i++) {
		ans = (ans * m) % MOD;
		dp[i] = pre * (m - 1) % MOD;
		pre = (pre + dp[i]) % MOD;
		pre = (pre - dp[i - k + 1] + MOD) % MOD;
	}
	cout << (ans - dp[n] + MOD) % MOD;
	return 0;
}

