#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lb long double
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back

const int N = 1e3 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
    freopen("p01.inp" , "r" , stdin);
	freopen("p01.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n ;
lb p , c[N][N] , Pow0[N] , Pow1[N] , ans = 0;

int main() {
	file();
	cin >> n >> p;
	c[0][0] = 1;
	
	for(int i = 1 ; i <= n ; i++) {
		c[i][0] = 1;
		for(int j = 1 ; j <= i ; j++)
		c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
	}
	
	Pow0[0] = Pow1[0] = 1;
	for(int i = 1 ; i <= n ; i++) 
		Pow0[i] = 1.0 * Pow0[i - 1] * (1.0 - p) , 
		Pow1[i] = 1.0 * Pow1[i - 1] * p;
	
	for(int i = 0 ; i <= n ; i++) {
		ans = ans + 1.0 * i * c[n][i] * Pow1[i] * Pow0[n - i];
	}
	
	cout << fixed << setprecision(5) << ans;
	
	return 0;
}


