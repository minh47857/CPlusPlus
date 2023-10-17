#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
    freopen("count.in" , "r" , stdin);
	freopen("count.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll n , k , m , dp[105][1 << 11] , ans = 0;

int Bit(int x , int k) {
	return (x >> k) & 1;
}

int main() {
	file();
	cin >> n >> k;
	m = 1 << (2 * k + 1);
	dp[0][(1 << (k + 1)) - 1] = 1;
	for(int i = 0 ; i < n ; i++) 
		for(int mask = 0 ; mask < m ; mask++) {
			int nmask = mask >> 1;
			for(int j = 0 ; j < 2 * k + 1 ; j++) if(!Bit(nmask , j)) {
				int pos = i + j - k + 1;
				if(pos < 1 || pos > n) continue;
				int new_mask = nmask | (1 << j);
				dp[i + 1][new_mask] = (dp[i + 1][new_mask] + dp[i][mask]) % MOD;
			}
		}
	for(int i = 0 ; i < m ; i++) 
		ans += dp[n][i];
	cout << ans;
	return 0;
}


