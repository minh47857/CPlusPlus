#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 2e5 + 5 , MOD = 1e9 + 7 , P = 450;

int n , k , dp[P][100005] , f[N] , inv[N] , ans = 0;

int mul(int a , int b) {
	return 1LL * a * b % MOD;
}

int add(int a , int b) {
	a += b;
	if(a >= MOD) a -= MOD;
	if(a < 0) a += MOD;
	return a;
}

int Pow(int a , int b) {
	if(b == 0) return 1;
	int res = Pow(a , b / 2);
	res = mul(res , res);
	if(b % 2) return mul(a , res);
	return res;
}

int C(int k , int x) {
	return mul(f[x] , mul(inv[k] , inv[x - k]));
} 

void CalcDP() {
	dp[0][0] = 1;
	for(int i = 0 ; i < P ; i++)
	  for(int j = 0 ; j <= k ; j++) {
		if(i && j > n) 
		  dp[i][j] = add(dp[i][j] , -dp[i - 1][j - n - 1]);
		if(i && j + i <= k)
		  dp[i][j + i] = add(dp[i][j + i] , dp[i][j]);
		if(i + 1 < P && j + i + 1 <= k)
		  dp[i + 1][j + i + 1] = add(dp[i + 1][j + i + 1] , dp[i][j]);
	  }
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
	cin >> n >> k; 
	CalcDP();
	f[0] = inv[0] = 1;
	for(int i = 1 ; i <= N - 5 ; i++) 
		f[i] = mul(f[i - 1] , i);
	inv[N - 5] = Pow(f[N - 5] , MOD - 2);
	for(int i = N - 6; i >= 1 ; i--)
		inv[i] = mul(inv[i + 1] , i + 1);
	for(int i = 1 ; i <= k ; i++) 
	  for(int j = 1 ; j < P ; j++) {
		 ans = add(ans , ((j % 2) ? 1 : -1) * mul(dp[j][i] , C(n - 1 , k - i + n - 1)));
	  }
	cout << add(C(n - 1 , n + k - 1) , -ans) % MOD;
	return 0;
}

