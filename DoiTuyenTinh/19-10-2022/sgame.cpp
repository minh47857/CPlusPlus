#include<bits/stdc++.h>
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define Bit(x , k) ((x >> k) & 1)

using namespace std;
const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
	freopen("sgame.inp" , "r" , stdin);
	freopen("sgame.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie() ; cout.tie(0);
}

ll n , a[N] , dp[N][3];

int main() {
	file();
	cin >> n;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	dp[1][a[1] % 3] = a[1];
	for(int i = 2 ; i <= n ; i++) {
		dp[i][a[i] % 3] = dp[i - 2][(3 - a[i] % 3) % 3] + a[i];
		for(int j = 0 ; j <= 2 ; j++) dp[i][j] = max(dp[i][j] , dp[i - 1][j]);
	}	
	cout << max({dp[n][0] , dp[n][1] , dp[n][2]});
	return 0;
}

