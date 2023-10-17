#include<bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 2e3 + 5 , M = 3e5 + 5 , inf = 1e9 + 7;

using namespace std;

int n , m , e[N]; 
ll s[M];

namespace sub5 {
	ll dp[N][N];
	
	void solve() {
		memset(dp , 0x3f , sizeof(dp));
		dp[n + 1][0] = 0;
		for(int i = n ; i >= 1; i--) {
			dp[i][0] = 0;
			for(int j = 1 ; j <= n - i + 1 ; j++) 
				dp[i][j] = min(dp[i + 1][j] , max(0LL , dp[i + 1][j - 1] - e[i]));
		}
		for(int i = 1 ; i <= m ; i++) {
			int d = 0 , c = n , g , res;
			while(d <= c) {
				g = (d + c) / 2;
				if(s[i] >= dp[1][g]) res = g , d = g + 1;
				else c = g - 1;
			}
			cout << res << ' ';
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++) cin >> e[i];
	for(int i = 1 ; i <= m ; i++) cin >> s[i];
    sub5::solve();
    return 0;
}

