#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 1e3 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("vector.inp" , "r" , stdin);
	freopen("vector.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , m;

namespace sub1 {
	int ans = 0 , a[N][25] , dp[N];
	void solve() {
		for(int i = 1 ; i <= n ; i++) {
		 for(int j = 1 ; j <= m ;j++) cin >> a[i][j];
		 sort(a[i] + 1 , a[i] + m + 1);
	    }
	    for(int i = 1 ; i <= n ; i++) {
	    	dp[i] = 1;
	    	for(int j = i - 1 ; j >= 1 ; j--) {
	    		bool ok = true;
	    		for(int l = 1 ; l <= m ; l++) 	if(a[i][l] <= a[j][l]) ok = false;
				if(ok) dp[i] = max(dp[i] , dp[j] + 1);
			}
			ans = max(ans , dp[i]);
		}
		cout << ans;
	}
}

namespace sub2 {
	int ans , a[100005] , bit[100005];
	vector<int> num;
	map<int ,int> pos;
	
	void update(int u , int val) {
		for(int i = u ; i <= n ; i += (i & (-i))) bit[i] = max(bit[i] , val);
	}
	
	int get(int u) {
		int res = 0;
		for(int i = u ; i >= 1 ; i -= (i & (-i))) res = max(bit[i] , res);
		return res;
	}
	
	void solve() {
		for(int i = 1 ; i <= n ; i++) cin >> a[i] , num.pb(a[i]);
		num.erase(unique(num.begin() , num.end()) , num.end());
		sort(num.begin() , num.end());
		for(int i = 0 ; i < num.size() ; i++) pos[num[i]] = i + 1;
		for(int i = 1 ; i <= n ; i++) {
			int res = get(pos[a[i]] - 1) + 1;
			update(pos[a[i]] , res);
			ans = max(ans , res);
		}
		cout << ans;
	}
}

int main() {
	file();
	cin >> n >> m;
	if(n <= 1000) sub1::solve();
	else sub2::solve();
	return 0;
}

