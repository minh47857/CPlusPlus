#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 5e3 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll a[N][N] , dp[N][N] , ans = 0;
int d[15] , n , m;

int main() {
	cin >> m >> n;
	for(int i = 1 ; i <= m ; i++)
	for(int j = 1 ; j <= n ; j++) 
		cin >> a[i][j] , 
		dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + a[i][j];
	for(int i = 1 ; i <= m ; i++)
	for(int j = i ; j <= m ; j++) {
		memset(d , 0 , sizeof(d));
		d[0] = 1;
		for(int k = 1 ; k <= n ; k++) {
			ll area = dp[j][k] - dp[i - 1][k];
			ans += d[area % 9];
			d[area % 9]++;
		}
	}
	cout << ans;
	return 0;
}

