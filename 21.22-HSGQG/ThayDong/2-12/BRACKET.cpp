#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const ll N = 1e5 + 5 , MOD = 1e9 + 7 , inf = 1e15;

int n;
ll a[N];

namespace sub2 {
	ll dp[1005][1005];
	void solve() {
		for(int i = 0 ; i <= n ; i++)
			for(int j = 0 ; j <= n ; j++)
				dp[i][j] = -inf;
		dp[0][0] = 0;
		for(int i = 0 ; i < n ; i++) {
			for(int j = 0 ; j <= i ; j++) {
				if(dp[i][j] == -inf) continue;
				dp[i + 1][j] = max(dp[i + 1][j] , dp[i][j]);
				dp[i + 1][j + 1] = max(dp[i + 1][j + 1] , dp[i][j] + a[i + 1]);
				if(j >= 1) dp[i + 1][j - 1] = max(dp[i + 1][j - 1] , dp[i][j] - a[i + 1]);
			}
		}
		cout << dp[n][0];
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
	cin >> n;
	for(int i = 1 ; i <= n ; i++) 
		cin >> a[i];
	//if(n <= 1e3) sub2::solve();
	 {
		ll ans = 0;
		priority_queue<ll> heap;
		for(int i = 1 ; i <= n ; i++) {
			heap.push(a[i]);
			heap.push(a[i]);
			ans += (heap.top() - a[i]);
			heap.pop();
		}
		cout << ans;
	}
	return 0;
}

