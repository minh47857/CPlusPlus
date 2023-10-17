#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define eps 1e-6
#define pi pair<int , int>

const int N = 5e4 + 5 , MOD = 1e9 + 19972207 , K = 205;

using namespace std;

void file() {
	freopen("digits.inp" , "r" , stdin);
	freopen("digits.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int n , k , p , s[N] , dp[N][K] , f[K][35];
string str;

int main() {
	file();
	cin >> n >> k >> p >> str;
	str = ' ' + str;
	for(int i = 1 ; i <= n ; i++) 
		s[i] = (s[i - 1] * 10 + (str[i] - '0')) % p;
	f[0][0] = 1;
	dp[0][0] = 1;
	for(int i = 1 ; i <= n ; i++) 
		for(int j = k ; j >= 1 ; j--) {
			dp[i][j] = f[j - 1][s[i]];
			f[j][s[i]] = (dp[i][j] + f[j][s[i]]) % MOD;
		}
	cout << dp[n][k];
}


