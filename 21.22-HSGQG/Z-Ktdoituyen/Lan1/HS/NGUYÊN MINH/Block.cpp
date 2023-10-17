#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const ll N = 1e5 + 5 , MOD = 1e9 + 7 , inf = 1e17;

void file() {
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll n , k , a[N] , mx = -inf , dp[N][105] , f[N];

int main() {
	cin >> n >> k;
	for(int i = 1 ; i <= n ; i++) {
		cin >> a[i];
		mx = max(a[i] , mx);
		dp[i][1] = mx;
	}
	for(int t = 2 ; t <= k ; t++) {
		stack<int> s;
		for(int i = 1 ; i <= N ; i++) {
			dp[i][t] = f[i] = inf;
			while(!s.empty() && a[i] > a[s.top()]) {
				f[i] = min(f[i] , f[s.top()]);
				s.pop();
			}
			dp[i][t] = f[i] + a[i];
			if(!s.empty()) 
				dp[i][t] = min({dp[i][t] , dp[s.top()][t - 1] + a[i] , dp[s.top()][t]});
			f[i] = min(f[i] , dp[i][t - 1]);
			s.push(i);
		}
	}
	cout << dp[n][k];
	return 0;
}

