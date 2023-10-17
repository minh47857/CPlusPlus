#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define eps 1e-6
#define pi pair<int , int>

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

using namespace std;

void file() {
	freopen("puzzles.inp" , "r" , stdin);
	freopen("puzzles.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int n , a[N] , b[N] , c[N] , dp[N][30] , f[30][30] , ans = 0;

int main() {
	file();
	cin >> n;
	for(int i = 1 ; i <= n ; i++) {
		string str;
		cin >> str;
		a[i] = str[0] - 'a', b[i] = str[str.size() - 1] - 'a' , c[i] = str.size();
	}
	memset(f , -0x3f , sizeof(f));
	for(int i = 1 ; i <= n ; i++) {
		for(int j = 0 ; j <= 25 ; j++) {
			dp[i][j] = f[a[i]][j] + c[i];
			if(j == a[i]) dp[i][j] = max(dp[i][j] , c[i]);
			if(b[i] == j) ans = max(ans , dp[i][j]);
		}
		for(int j = 0 ; j <= 25 ; j++) {
			f[b[i]][j] = max(f[b[i]][j] , dp[i][j]);
			f[b[i]][a[i]] = max(f[b[i]][a[i]] , c[i]);
		}
	}
	cout << ans;
}


