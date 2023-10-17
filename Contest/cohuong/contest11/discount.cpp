#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>

const ll N = 1000001 , MOD = 1e9 +7 , inf = 1e15;

void file() {
	freopen("discount.in" , "r" , stdin);
	freopen("discount.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
int n , k;
ll s[N] , a[N];
namespace sub12 {
	ll dp[N][3];
	void solve() {
		for(int i = 0 ; i <= n ; i++) dp[i][0] = inf;
		for(int i = 1 ; i <= n ; i++) {
			dp[i][1] = min(dp[i - 1][1] , dp[i - 1][0]) + a[i];
			for(int j = i - 1 ; j >= max(i - k , 1) ; j--) dp[i][0] = min(dp[j][1] + (s[i] - s[j]) / 2 , dp[i][0]) ;// cout << i << ' ' <<j << ' ' << s[i] - s[j] << '\n';
			//cout << i << ' ' << dp[i][1] << ' ' << dp[i][0] << '\n';
		}
		cout << min(dp[n][0] , dp[n][1]);
	}
}

int main() {
	file();
  cin >> n >> k;
  for(int i = 1 ; i <= n ; i++) cin >> a[i] , s[i] = s[i - 1] + a[i];
  if(n <= 5000) sub12::solve();
  
}

