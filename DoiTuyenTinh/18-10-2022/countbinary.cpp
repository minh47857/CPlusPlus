#include<bits/stdc++.h>
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define Bit(x , k) ((x >> k) & 1)

using namespace std;
const int N = 1e5 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
	freopen("countbinary.inp" , "r" , stdin);
	freopen("countbinary.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie() ; cout.tie(0);
}

int n , ans , dp[N][20];

int add(int a , int b) {
	a += b;
	if(a >= MOD) a -= MOD;
	return a;
}

int main() {
	file();
	cin >> n;
	for(int i = 5 ; i <= 15 ; i++) dp[4][i] = 1;
	for(int i = 4 ; i < n ; i++) {
		for(int mask = 5 ; mask <= 15 ; mask++) {
			int newmask = mask ^ ((Bit(mask , 3)) << 3);
			newmask *= 2;
			dp[i + 1][newmask] = add(dp[i + 1][newmask] , dp[i][mask]);
			dp[i + 1][newmask + 1] = add(dp[i + 1][newmask + 1] , dp[i][mask]);
		}	
	}
	for(int i = 5 ; i <= 15 ; i++) ans = add(ans , dp[n][i]);
	cout << ans;
	return 0;
}

