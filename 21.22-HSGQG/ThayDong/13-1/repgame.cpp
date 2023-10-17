#include<bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 5e4 + 5 , M = 250;
const ll inf = 1e18;

using namespace std;

int n , m , a[N] , Pow[10] , l[10] , r[10] , f[M];
ll dp[N][M];

int Bit(int x , int k) {
	return (x / Pow[k]) % 3;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	for(int i = 0 ; i < m ; i++) cin >> l[i] >> r[i];
	Pow[0] = 1;
	for(int i = 1 ; i <= m ; i++) Pow[i] = Pow[i - 1] * 3;
	for(int mask = 0 ; mask < Pow[m] ; mask++) {
		f[mask] = m;
		for(int i = 0 ; i < m ; i++) 
			if(Bit(mask , i) == 1) {
				f[mask] = i;
				break;
			}
	}
	memset(dp , 0x3f , sizeof(dp));
	dp[0][0] = 0;
	for(int i = 1 ; i <= n ; i++) {
		for(int mask = 0 ; mask < Pow[m] ; mask++) {
			for(int j = 0 ; j < m ; j++) {
// bit = 0 : chua mo doan
// bit = 1 : dang mo doan			
// bit = 2 : da dong doan
				int x = Bit(mask , j);
				if(x == 0) {
					dp[i][mask] = min(dp[i][mask] , dp[i - 1][mask]);
					if(l[j] <= i && i <= r[j])
						dp[i][mask + Pow[j]] = min(dp[i][mask + Pow[j]] , dp[i][mask]);
				}
				if(x == 1) {
					if(i <= r[j]) dp[i][mask] = min(dp[i][mask] , dp[i - 1][mask]);
					dp[i][mask + Pow[j]] = min(dp[i][mask + Pow[j]] , dp[i - 1][mask]);
				}
				if(x == 2) dp[i][mask] = min(dp[i][mask] , dp[i - 1][mask]);
				
			}
		}
		for(int mask = 0 ; mask < Pow[m] ; mask++) {
			dp[i][mask] += 1LL * a[i] * f[mask];
			for(int j = 0 ; j < m ; j++) {
				int x = Bit(mask , j);
				if(x == 1 && (r[j] < i || l[j] > i)) dp[i][mask] = inf;
				if(x == 2 && i < l[j]) dp[i][mask] = inf;
			}
		}
	}
	ll ans = inf;
	for(int i = 0 ; i < Pow[m] ; i++)
		ans = min(ans , dp[n][i]);
	cout << ans;
	return 0;
}

