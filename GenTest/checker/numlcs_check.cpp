#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e3 + 5 , MOD = 20030101 , inf = 1e9 + 7;

void file() {
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int t , n , m , ans , nxa[N][30] , nxb[N][30] , l[N][N] , f[N][N];
string a , b;

void solve() {
	ans = 0;
	cin >> a >> b;
	n = a.size() , m = b.size();
	a = ' ' + a , b = ' ' + b;
	for(int i = 1 ; i <= n ; i++)
		for(int j = 1 ; j <= m ; j++) 
			if(a[i] == b[j]) l[i][j] = l[i - 1][j - 1] + 1;
			else l[i][j] = max(l[i - 1][j] , l[i][j - 1]);
	l[n + 1][m + 1] = l[n][m] + 1;
	if(l[n][m] == 0) {
		cout << 0 << ' ' << 0 << '\n';
		return;
	}
	memset(f , 0 , sizeof(f));
	f[n + 1][m + 1] = 1;
	for(int i = 1 ; i <= n ; i++) {
		for(int c = 0 ; c <= 25 ; c++) nxa[i][c] = nxa[i - 1][c];
		nxa[i][a[i] - 'a'] = i; 
	}
	for(int i = 1 ; i <= m ; i++) {
		for(int c = 0 ; c <= 25 ; c++) nxb[i][c] = nxb[i - 1][c];
		nxb[i][b[i] - 'a'] = i;
	}
	for(int i = n + 1 ; i >= 1 ; i--)
		for(int j = m + 1 ; j >= 1 ; j--) if(f[i][j]) {
			if(l[i][j] == 1) ans = (ans + f[i][j]) % MOD;
			for(int c = 0 ; c <= 25 ; c++) {
				int nxi = nxa[i - 1][c] , nxj = nxb[j - 1][c];
				if(nxi && nxj && l[i][j] - 1 == l[nxi][nxj]) 
					f[nxi][nxj] = (f[nxi][nxj] + f[i][j]) % MOD;
			}
		}
	cout << l[n][m] << ' ' << ans << '\n';
}

int main() {
//	file();
	cin >> t;
	while(t--) solve();
	return 0;
}
