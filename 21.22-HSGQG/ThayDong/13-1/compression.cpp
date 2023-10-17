#include<bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 3005 , MOD = 1e9 + 7 , inf = 1e9 + 7;

using namespace std;

int n , m , f[N][N] , l1 , l2 , ans;

int calc(int x , int y , int u , int v) {
	return f[u][v] - f[x - 1][v] - f[u][y - 1] + f[x - 1][y - 1];
}

bool check(int x , int y) {
	for(int i = x ; i <= n ; i += x)
		for(int j = y ; j <= m ; j += y) {
			int tmp = calc(i - x + 1 , j - y + 1 , i , j);
			if(tmp > 0 && tmp < x * y) return false;
		}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++)
		for(int j = 1 ; j <= m ; j++) {
			char c ; cin >> c;
			f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + (c - '0');
		}
	for(int d = 1 ; d <= n ; d++) {
		if(n % d) continue;
		for(int r = 1 ; r <= m ; r++) 
			if(m % r == 0 && d * r > ans && check(d , r)) 
				l1 = d , l2 = r , ans = d * r;
	}
	cout << n / l1 << ' ' << m / l2 << '\n';
	for(int i = l1 ; i <= n ; i += l1) {
		for(int j = l2 ; j <= m ; j += l2)
			cout << calc(i - l1 + 1 , j - l2 + 1 , i , j) / ans;
		cout << '\n';
	}
	return 0;
}

