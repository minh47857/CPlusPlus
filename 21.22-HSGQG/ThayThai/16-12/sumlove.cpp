#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>
 
const int N = 1e5 + 5 , MOD = 1e9 + 7 , K = 640;
 
int n , q , dp[K][N];
 
int mul(int a , int b) {
	return 1LL * a * b % MOD;
}
 
int Plus(int a , int b) {
	a += b;
	if(a >= MOD) a -= MOD;
	if(a < 0) a += MOD;
	return a;
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
	cin >> n >> q;
	dp[0][0] = 1;
	for(int i = 0 ; i < K ; i++)
	  for(int j = 0 ; j <= N - 5 ; j++) {
	  	if(i >= 1 && j > n) 
		  dp[i][j] = Plus(dp[i][j] , -mul(2 , dp[i - 1][j - n - 1]));
		if(i >= 2 && j > 2 * n + 1)
		  dp[i][j] = Plus(dp[i][j] , -dp[i - 2][j - 2 * n - 2]);
		if(i && j + i <= N - 5)
		  dp[i][j + i] = Plus(dp[i][j + i] , dp[i][j]);
		if(i + 1 < K && j + i + 1 <= N - 5)
		  dp[i + 1][j + i + 1] = Plus(dp[i + 1][j + i + 1] , mul(2 , dp[i][j]));
		if(i + 2 < K && j + i + 2 <= N - 5)
		  dp[i + 2][j + i + 2] = Plus(dp[i + 2][j + i + 2] , dp[i][j]);
	  }
	while(q--) {
		int k , ans = 0;
		cin >> k;
		for(int i = 0 ; i < K ; i++)
			ans = Plus(ans , dp[i][k]);
		cout << ans << '\n';
	}
	return 0;
}
