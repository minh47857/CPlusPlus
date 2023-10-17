#include<bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 1e3 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

using namespace std;

int n , k , dp[N][N];

int add(int a , int b) {
	a += b;
	if(a >= MOD) a -= MOD;
	return a;
}

int mul(int a , int b) {
	return 1LL * a * b % MOD;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
	cin >> n >> k;
	dp[0][0] = 1;
	for(int i = 0 ; i < n ; i++) {
		for(int j = 0 ; j <= k ; j++) {
			dp[i + 1][j] = add(dp[i + 1][j] , mul(dp[i][j] , j + 1));
			dp[i + 1][j + 1] = add(dp[i + 1][j + 1] , mul(dp[i][j] , i - j));
		}
	}
	cout << dp[n][k];
}

