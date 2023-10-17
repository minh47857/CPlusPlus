#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

using namespace std;

void file() {
	 freopen("ZERO.inp" , "r" , stdin);
	 freopen("ZERO.out" , "w" , stdout);
	 ios::sync_with_stdio(0);
	 cin.tie(0) ; cout.tie(0);
}

int q , dp[N] , n;

int main() {
	file();
	cin >> q;
	memset(dp , 0x3f , sizeof(dp));
	dp[0] = 0;
	for(ll i = 0 ; i < 1e6; i++) {
		dp[i + 1] = min(dp[i] + 1 , dp[i + 1]);
		if(i >= 2) 
			for(ll j = i * 2 ; j <= min(i * i , 1LL*1000000) ; j += i) 
				dp[j] = min(dp[j] , dp[i] + 1);
	}	
	while(q--) {
		cin >> n;
		cout << dp[n] << '\n';
	}
	return 0;
}


