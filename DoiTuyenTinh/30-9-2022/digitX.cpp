#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("digitX.inp" , "r" , stdin);
	freopen("digitX.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int q , g[N] , f[N][10];

int main() {
	file();
	for(int i = 1 ; i <= 1e6 ; i++) {
		int x = i , tmp = 1;
		while(x) {
			if(x % 10) tmp *= x % 10;
			x /= 10;
		}
		g[i] = (tmp < 10 ? tmp : g[tmp]);
		for(int k = 1 ; k <= 9 ; k++) f[i][k] = f[i - 1][k];
		f[i][g[i]]++;
	}
	cin >> q;
	while(q--) {
		int l , r , k;
		cin >> l >> r >> k;
		cout << f[r][k] - f[l - 1][k] << '\n';
	}
	return 0;
}

