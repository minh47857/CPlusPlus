#include<bits/stdc++.h>
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define Bit(x , k) ((x >> k) & 1)

using namespace std;
const int N = 505 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
	freopen("donsoi.inp" , "r" , stdin);
	freopen("donsoi.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie() ; cout.tie(0);
}

int n , s[N] , f[N][N];

int main() {
	file();
	cin >> n;
	memset(f , 0x3f , sizeof(f));
	for(int i = 1 , x ; i <= n ; i++) cin >> x, s[i] = s[i - 1] + x , f[i][i] = 0;
	for(int i = n - 1 ; i >= 1 ; i--) 
		for(int j = i + 1 ; j <= n ; j++) 
			for(int k = i ; k < n ; k++) 
				f[i][j] = min(f[i][j] , f[i][k] + f[k + 1][j] + s[j] - s[i - 1]);
	cout << f[1][n];
	return 0;
}

