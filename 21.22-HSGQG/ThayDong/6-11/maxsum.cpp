#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 1e3 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , k , a[N][N] , dp[N][N][3] , ans = -inf;

int main() {
	file();
	cin >> n >> k;
	for(int i = 1 ; i <= n ; i++)
	    for(int j = 1 ; j <= n ; j++) 
	        cin >> a[i][j] , dp[i][j][0] = -inf;
	dp[1][1][0] = a[1][1];
    for(int l = 0 ; l <= k ; l++) {
    	for(int i = 1 ; i <= n ; i++)
    	   for(int j = 1 ; j <= n ; j++) dp[i][j][1 - l % 2] = -inf;
    	for(int i = 1 ; i <= n ; i++)
    	   for(int j = 1 ; j <= n ; j++) if(dp[i][j][l % 2] != -inf) {
    	   	 dp[i + 1][j][l % 2] = max(dp[i][j][l % 2] + a[i + 1][j] , dp[i + 1][j][l % 2]);
    	   	 dp[i][j + 1][l % 2] = max(dp[i][j][l % 2] + a[i][j + 1] , dp[i][j + 1][l % 2]);
    	   	 dp[i][j - 1][1 - l % 2] = max(dp[i][j][l % 2] + a[i][j - 1] , dp[i][j - 1][1 - l % 2]);
    	   	 dp[i - 1][j][1 - l % 2] = max(dp[i][j][l % 2] + a[i - 1][j] , dp[i - 1][j][1 - l % 2]);
		   }
		ans = max(ans , dp[n][n][l % 2]);
	}
	cout << ans;
	return 0;
}

