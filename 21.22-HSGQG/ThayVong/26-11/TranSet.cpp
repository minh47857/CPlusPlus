#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back

const int N = 1e3 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
    freopen("TranSet.inp" , "r" , stdin);
	freopen("TranSet.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll n , f[N][55] , a[N][35] , ans = 0 , s , Size[N];

void calc(int u , int p) {
	if(p == 0) {
		f[u][p] = 1;
		return;
	}
	if(f[u][p] != -1) return;
	p--;
    ll  dp[35][55];
    memset(dp , -0x3f , sizeof(dp));
    dp[0][0] = 0;
	for(int i = 1 ; i <= Size[u] ; i++) 
		for(int sum = 0 ; sum <= p ; sum++)
		for(int j = 0 ; j <= sum ; j++) {
			calc(a[u][i] , j);
			dp[i][sum] = max(dp[i][sum] , dp[i - 1][sum - j] + f[a[u][i]][j]);
		}
	f[u][p + 1] = dp[Size[u]][p];
	cout << u << " " << p + 1 << ' ' << f[u][p + 1] << '\n';
}

int main() {
//	file();  
	cin >> n;
	for(int i = 1 , x; i <= n ; i++) {
		cin >> x , Size[i] = x;
        for(int j = 1 ; j <= x ; j++) cin >> a[i][j];
	}
	cin >> s;
	memset(f , -1 , sizeof(f));
	for(int i = 1 ; i <= n ; i++) calc(i , s) , ans = max(ans , f[i][s]);
	cout << ans;
	cout << "why";
	return 0;
}


