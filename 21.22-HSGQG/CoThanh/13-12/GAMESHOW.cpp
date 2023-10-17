#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back

const int N = 5005 , MOD = 1e9 + 7 , inf = 1e9 + 7;

using namespace std;

void file() {
    
	 freopen("GAMESHOW.inp" , "r" , stdin);
	 freopen("GAMESHOW.out" , "w" , stdout);
	 ios::sync_with_stdio(0);
	 cin.tie(0) ; cout.tie(0);
}

ll n , T , a[N] , dp[N][N] , ans = -1; 

int main() {
	file();
	cin >> n >> T;
	for(int i = 1 ; i <= n ; i++)
		cin >> a[i];
	memset(dp , -1 , sizeof(dp));
	dp[0][0] = 0;
	for(int i = 0 ; i < n ; i++) {
		for(int j = 0 ; j <= i ; j++) {
			if(dp[i][j] == -1) continue;
			if(dp[i][j] + a[i + 1] >= 0)
				dp[i + 1][j + 1] = max(dp[i + 1][j + 1] , dp[i][j] + a[i + 1]);
			if(dp[i][j] - T >= 0)
				dp[i + 1][j] = max(dp[i + 1][j] , dp[i][j] - T);
		}
	}
	for(int i = n ; i >= 0 ; i--) 
		if(dp[n][i] != -1) ans = i;
	cout << ans;
	return 0;
}


