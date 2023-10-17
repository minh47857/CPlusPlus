#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const ll N = 305 , MOD = 1e9 + 7 , inf = 1e15;

void file() {
    freopen("sweet.in" , "r" , stdin);
    freopen("sweet.out" , "w" , stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int t , n , m , a[N][N];
ll dp[N][N];

void solve() {
	ll ans = inf;
	cin >> n >> m;
	for(int i = 1 ; i <= n + 1 ; i++)
	  for(int j = 0 ; j <= n ; j++)
	  	dp[i][j] = inf;
	for(int i = 1 ; i <= n ; i++) {
	  for(int j = 1 ; j <= m ; j++)
	  	cin >> a[i][j];
	  sort(a[i] + 1 , a[i] + m + 1);
	}
	dp[1][0] = 0;
	for(int i = 1 ; i <= n ; i++) 
		for(int j = 0 ; j <= n ; j++) {
			ll s = 0;
			for(int k = 0 ; k <= min(m , n - j) ; k++) {
				s += a[i][k];
				if(j + k - 1 >= 0 && dp[i][j] != inf)
					dp[i + 1][j + k - 1] = min(dp[i + 1][j + k - 1] , dp[i][j] + k * k + s);
			}
		}
	for(int i = 0 ; i <= n ; i++)
		ans = min(ans , dp[n + 1][i]);
	cout << ans << '\n';
}

int main() {
	file();
	cin >> t;
	while(t--)
		solve();
	return 0;
}

