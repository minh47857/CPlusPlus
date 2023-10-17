#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 1e5 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("L1L2K.inp" , "r" , stdin);
	freopen("L1L2K.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , k , a[N] , pos[N];

namespace sub12 {
	int dp[1005][1005];
	void solve() {
		for(int i = 1 ; i <= n ; i++)
		  for(int j = 1 ; j <= n ; j++) {
		  	dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]);
		  	if(abs(i - a[j]) <= k) dp[i][j] = max(dp[i][j] , dp[i - 1][j - 1] + 1);
		  }
		cout << dp[n][n];
	}
}

namespace sub3 {
	int res , ans = 0 , bit[N];
	vector<int> P;
	int get(int u) {
		int s = 0;
		for(int i = u ; i >= 1 ; i -= (i & (-i))) s = max(bit[i] , s);
		return s;
	}
	
	void update(int u , int val) {
		for(int i = u ; i <= n ; i += (i & (-i))) bit[i] = max(bit[i] , val);
	}
	
	void solve() {
		for(int i = 1 ; i <= n ; i++) {
			vector<int> tmp;
			for(int j = max(1 , i - k) ; j <= min(n , i + k) ; j++) tmp.pb(pos[j]);
			sort(tmp.begin() , tmp.end() , greater<int>());
			for(auto x : tmp) P.pb(x);
		}
		for(auto x : P) {
			res = get(x - 1) + 1;
			update(x , res);
			ans = max(res , ans);
		}
		cout << ans;
	}
}
int main() {
	file();
  cin >> n >> k;
  for(int i = 1 ; i <= n ; i++) cin >> a[i] , pos[a[i]] = i;
  if(n <= 1000) sub12::solve();
  else sub3::solve();
}

