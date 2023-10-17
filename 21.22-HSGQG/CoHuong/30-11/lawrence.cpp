#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back

const int N = 505 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
    freopen("lawrence.inp" , "r" , stdin);
	freopen("lawrence.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , m , a[N] , s[N] , dp[N][N] , ans = inf;

int main() {
	file();
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++) 
		cin >> a[i] , s[i] = s[i - 1] + a[i];
	memset(dp , 0x3f , sizeof(dp));
	dp[0][0] = 0;
	for(int i = 1 ; i <= n ; i++)
		for(int j = i + 1 ; j <= n ; j++)
			dp[0][0] += a[i] * a[j];
	for(int i = 0 ; i < n ; i++) 
		for(int j = 0 ; j <= m ; j++) {
			if(dp[i][j] == inf) continue;
			for(int k = i + 1 ; k <= n ; k++) {
				dp[k][j + 1] = min(dp[k][j + 1] , dp[i][j] - (s[k - 1] - s[i - 1]) * (s[n] - s[k - 1]));	
			}
		}
	for(int i = 0 ; i <= n ; i++)
		ans = min(ans , dp[i][m]);
	cout << ans;
	return 0;
}


