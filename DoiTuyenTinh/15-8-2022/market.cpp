#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e5 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("market.inp" , "r" , stdin);
	freopen("market.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , m , x[N], w[N];
ll dp[N];

int main() {
	file();
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++) cin >> x[i];
	for(int i = 1 ; i <= m ; i++) cin >> w[i];
	for(int i = m - 1 ; i >= 1 ; i--) w[i] = min(w[i] , w[i + 1]);
	sort(x + 1 , x + n + 1);
	memset(dp , 0x3f , sizeof(dp));
	dp[0] = 0;
	for(int i = 1 ; i <= n ; i++)  
		for(int j = 0 ; j < i ; j++) 
			dp[i] = min(dp[i] , dp[j] + w[x[i] - x[j + 1] + 1]);
	cout << dp[n];
	return 0;
}

