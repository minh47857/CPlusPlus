#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const ll N = 2e3 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

ll L , H , K , c[N][N] , ans = 0 , k , n;

void file() {
	freopen("SPACE.inp" , "r" , stdin);
	freopen("SPACE.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int main() {
	file();
	cin >> L >> H >> K;
	if(K == 1) {
		cout << (L + 1) * (H + 1);
		return 0;
	}
	c[0][0] = 1;
	for(int i = 1 ; i <= 2000 ; i++) {
		c[i][0] = c[i][i] = 1;
		for(int j = 1 ; j <= i / 2 ; j++)
			c[i][j] = c[i][i - j]= (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
	}
	for(int x = 0 ; x <= L ; x++)
		for(int y = 1 ; y <= H ; y++) {
			k = K - 1 , n = __gcd(x , y);
			if(k <= n)
				ans = (ans + ((!x) ? 1 : 2) * c[n][k] * (L - x + 1) % MOD) % MOD;
		}
	cout << ans;
}

