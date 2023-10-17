#include<bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 205 , M = 1005 , MOD = 1e9 + 7;

using namespace std;

int n , k , a[N] , dp[N][M][N] , ans = 0;

int mul(int a , int b) {
	return 1LL * a * b % MOD;
}

int add(int &a , int b) {
	a += b;
	if(a >= MOD) a -= MOD;
	return a;
}

int main() {
	cin >> n >> k;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	sort(a + 1 , a + n + 1);
	a[0] = a[1];
	dp[0][0][0] = 1;
	for(int i = 0 ; i < n ; i++) 
		for(int j = 0 ; j <= k ; j++) 
			for(int l = 0 ; l <= i ; l++) {
				if(j + (a[i + 1] - a[i]) * l <= k) {
					add(dp[i + 1][j + (a[i + 1] - a[i]) * l][l + 1] , dp[i][j][l]);
					add(dp[i + 1][j + (a[i + 1] - a[i]) * l][l] , mul(l + 1 ,  dp[i][j][l]));
					add(dp[i + 1][j + (a[i + 1] - a[i]) * l][l - 1] , mul(l , dp[i][j][l]));
				}
			}
	for(int i = 0 ; i <= k ; i++)
		add(ans , dp[n][i][0]);
	cout << ans;
	return 0;
}

