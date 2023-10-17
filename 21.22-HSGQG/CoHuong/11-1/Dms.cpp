#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define eps 1e-6
#define pi pair<int , int>

const int N = 105 , MOD = 1e9 + 7 , M = 505;

using namespace std;

void file() {
	freopen("Dms.inp" , "r" , stdin);
	freopen("Dms.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int n , m , dp[N][M] , a[N];

int main() {
	file();
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	dp[0][m] = 1;
	for(int i = 0 ; i < n ; i++) 
		for(int j = 0 ; j <= m ; j++) 
			for(int k = a[i + 1] ; k <= j ; k += a[i + 1]) 
				dp[i + 1][j - k] = (dp[i + 1][j - k] + dp[i][j]) % MOD;
	cout << dp[n][0];
	return 0;
}


