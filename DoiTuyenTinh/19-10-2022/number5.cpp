#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("number5.inp" , "r" , stdin);
	freopen("number5.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll l , r , f[25][2][2] , ans , dp[25] , Pow[25];
int a[25];

ll calc(int i , bool n1 , bool n2) {
	if(f[i][n1][n2] != -1) return f[i][n1][n2];
	if(i == 0) return n2;
	ll res = 0;
	for(int u = 0 ; u <= max(a[i] , n1 * 9) ; u++) {
		res += calc(i - 1 , n1 | (u != a[i]) , n2 | (u == 5));
	}
	f[i][n1][n2] = res;
	return res;
}

ll solve(ll x) {
	for(int i = 1 ; i <= 20 ; i++) a[i] = x % 10 , x /= 10;
	memset(f , -1 , sizeof(f));
	return calc(20 , 0 , 0);
}

ll abcd(ll x) {
	Pow[0] = 1;
	for(int i = 1 ; i <= 20 ; i++) a[i] = x % 10 , x /= 10 , Pow[i] = Pow[i - 1] * 9;
	for(int i = 1 ; i <= 20 ; i++) {
		if(!a[i]) dp[i] = dp[i - 1];
		else if(a[i] < 5) dp[i] = (a[i] + 1) * Pow[i - 1];
		else dp[i] = a[i] * Pow[i - 1] + dp[i - 1]; 
		cout << i << ' ' << a[i] << ' ' << dp[i] << '\n';
	}
	return dp[20];
}

int main() {
//	file();
	cin >> l >> r;
//	for(ll i = l ; i <= r ; i++) {
//		int x = i , ok = 0;
//		while(x) {
//			ok |= (x % 10 == 5);
//			x /= 10;
//		}
//		if(ok) ans++;
//	}
//	cout << ans << ' ';
	cout << solve(r) - solve(l - 1);
//	cout << abcd(r) - abcd(l - 1);
	return 0;
}

