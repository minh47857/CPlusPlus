#include<bits/stdc++.h>
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define Bit(x , k) ((x >> k) & 1)

using namespace std;
const int N = 65 , K = 105 , inf = 1e9;

void file() {
	freopen("binary.inp" , "r" , stdin);
	freopen("binary.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie() ; cout.tie(0);
}

ll n , k , dp[N][N][K];

int main() {
	file();
	cin >> n >> k;
	if(n % 2) {
		cout << 0;
		return 0;
	}
	dp[1][1][1 % k] = 1;
	for(int i = 1 ; i < n ; i++)
		for(int j = 1 ; j <= i ; j++) 
			for(int r = 0 ; r < k ; r++) {
				dp[i + 1][j + 1][(r * 2 + 1) % k] += dp[i][j][r];
				dp[i + 1][j][r * 2 % k] += dp[i][j][r];
			}
	cout << dp[n][n / 2][0];
	return 0;
}

