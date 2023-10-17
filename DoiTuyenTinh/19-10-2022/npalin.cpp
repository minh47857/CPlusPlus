#include<bits/stdc++.h>
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define Bit(x , k) ((x >> k) & 1)

using namespace std;
const int N = 5e3 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
	freopen("npalin.inp" , "r" , stdin);
	freopen("npalin.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie() ; cout.tie(0);
}

int t , n , f[N][N][2];
string str;

int main() {
	file();
	cin >> str;
	n = str.size();
	str = ' ' + str;
	for(int i = 1 ; i <= n + 1 ; i++) f[i][i][0] = f[i][i][1] = f[i + 1][i][0] = f[i + 1][i][1] = 1;
	for(int i = n - 1 ; i >= 1 ; i--)
		for(int j = i + 1 ; j <= n ; j++) {
			if(str[i] == str[j]) f[i][j][1] = f[i + 1][j - 1][1] , f[i][j][0] = f[i + 1][j - 1][0];
			else f[i][j][1] = f[i + 1][j - 1][0];
		}
	cin >> t;
	while(t--) {
		int l , r ; cin >> l >> r;
		cout << max(f[l][r][0] , f[l][r][1]) << '\n';
	}
	return 0;
}

