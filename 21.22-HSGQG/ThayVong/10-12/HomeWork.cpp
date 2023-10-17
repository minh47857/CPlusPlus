#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back

const int N = 2e5 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
    freopen("HomeWork.inp" , "r" , stdin);
	freopen("HomeWork.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , t , a[N] , dp[N][5];

void solve() {
	cin >> n;
	for(int i = 1 ; i <= n ; i++) 
		cin >> a[i];
	for(int i = 0 ; i <= n ; i++)
		dp[i][0] = dp[i][1] = dp[i][2] = dp[i][3] = inf;
	dp[0][3] = 0;
	for(int i = 0 ; i < n ; i++) {
		dp[i + 1][0] = min({dp[i + 1][0] , dp[i][3] + a[i + 1] , dp[i][2] + a[i + 1]});
		dp[i + 1][1] = min(dp[i + 1][1] , dp[i][0] + a[i + 1]);
		dp[i + 1][2] = min({dp[i + 1][2] , dp[i][1] , dp[i][0]});
		dp[i + 1][3] = min(dp[i + 1][3] , dp[i][2]);
	}
	cout << min({dp[n][0] , dp[n][1] , dp[n][2] ,dp[n][3]}) << '\n';
}

int main() {
	file();
	cin >> t;
	while(t--) 
		solve();
	return 0;
}


