#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("stilts.inp" , "r" , stdin);
	freopen("stilts.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , m , k;
vector<vector<ll>> a , dp;
ll ans = 0;

int main() {
	file();
	cin >> m >> n >> k;
    a.resize(m + 5) , dp.resize(m + 5);
    for(int i = 1 ; i <= m ; i++) a[i].resize(n + 2 * k + 5 , 0) , dp[i].resize(n + 2 * k + 5 , 0);
	for(int i = 1 ; i <= m ; i++)
	for(int j = 1 ; j <= n ; j++)
		cin >> a[i][j + k];
	for(int i = 1 ; i <= n ; i++) dp[1][i + k] = a[1][i + k];
	for(int i = 2 ; i <= m ; i++) {
		deque<int> dq;
	    for(int j = 1 ; j <= n + 2 * k ; j++) {
	    	while(dq.size() && dp[i - 1][j] >= dp[i - 1][dq.back()]) dq.pop_back();
	    	dq.pb(j);
	    	if(dq.front() + 2 * k + 1 <= j) dq.pop_front();
	    	if(j >= 2 * k + 1) dp[i][j - k] = dp[i - 1][dq.front()] + a[i][j - k];
		}
	}
	for(int i = 1 ; i <= n ; i++) ans = max(ans , dp[m][i + k]);
	cout << ans;
	return 0;
}

