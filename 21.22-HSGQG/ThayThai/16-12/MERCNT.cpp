#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 7e3 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

int n , f[N][N];
ll s[N];

void file() {
	freopen("MERCNT.inp" , "r" , stdin);
	freopen("MERCNT.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int main() {
//	file();
	cin >> n;
	for(int i = 1 , x ; i <= n ; i++)
		cin >> x , s[i] = s[i - 1] + x;
	f[0][0] = 1;
	for(int i = 1 ; i <= n ; i++) {
		int k = 0;
		for(int j = 1 ; j <= i ; j++) {
			while(k <= j - 1 && s[j - 1] - s[k - 1] > s[i] - s[j - 1])
				k++;
		    int  res = (f[j - 1][j - 1] - f[j - 1][k - 1] + MOD) % MOD;
			f[i][j] = (f[i][j - 1] + res) % MOD;
		}
	}
	cout << f[n][n];
	return 0;
}

