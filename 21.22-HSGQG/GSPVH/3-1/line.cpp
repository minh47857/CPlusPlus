#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 2e5 + 5 , MOD = 998244353 , M = 305;

int n , k , m , h[N] , a[N] , dp[N][M] , f[N] , inv[N] , sum , ans;

void file() {
    freopen("line.inp" , "r" , stdin);
    freopen("line.out" , "w" , stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int add(int a , int b) {
	a += b;
	if(a >= MOD) a -= MOD;
	return a;
}

int mul(int a , int b) {
	return 1LL * a * b % MOD;
}

int Pow(int a , int b) {
	if(b == 0) return 1;
	int res = Pow(a , b / 2);
	res = mul(res , res);
	if(b % 2) return mul(res , a);
	return res;
}

int A(int k , int n) {
	if(k > n) return 0;
	return mul(f[n] , inv[n - k]);
}

int main() {
	file();
	cin >> n >> n >> k;
	for(int i = 1 ; i <= n ; i++) 
		cin >> h[i];
	sort(h + 1 , h + n + 1 , greater<int>());
    for(int i = 1 ; i <= n ; i++) {
    	a[++m] = 1;
    	while(i < n && h[i] == h[i + 1]) i++ , a[m]++;
	}
	f[0] = inv[0] = 1;
	for(int i = 1 ; i <= n ; i++) 
		f[i] = mul(f[i - 1] , i);
	inv[n] = Pow(f[n] , MOD - 2);
	for(int i = n - 1 ; i >= 1 ; i--)
		inv[i] = mul(inv[i + 1] , i + 1);
	dp[1][0] = f[a[1]];
	for(int i = 1 ; i < m ; i++) {
		sum += a[i];
		for(int j = 0 ; j <= k ; j++) 
			for(int l = 0 ; l <= a[i + 1] ; l++) {
				if(j + a[i + 1] - l > k) continue;
				dp[i + 1][j + a[i + 1] - l] = add(dp[i + 1][j + a[i + 1] - l] , mul(mul(dp[i][j] , A(l , a[i + 1])) , A(a[i + 1] - l , sum + a[i + 1] - l - 1)));
			}
	}
	for(int i = 0 ; i <= k ; i++) 
		ans = add(ans , dp[m][i]);
	cout << ans;  
	return 0;
}
