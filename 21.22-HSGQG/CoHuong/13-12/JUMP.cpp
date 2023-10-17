#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const ll N = 4005 , MOD = 1e9 + 7;

void file() {
	freopen("JUMP.inp" , "r" , stdin);
	freopen("JUMP.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int n , m , k , a[N] , b[N] , c[N][N];
ll f[N][N];

void update(int x , int y , int u , int v , int val) {
	f[x][y] += val;
	f[u + 1][v + 1] += val;
	f[x][v + 1] -= val;
	f[u + 1][y] -= val;
}

int main() {
	file();
	cin >> m >> n >> k;
	for(int i = 1 ; i <= m ; i++) 
		cin >> a[i] , a[i] %= k;
	
	for(int i = 1 ; i <= n ; i++) 
		cin >> b[i] , b[i] %= k;
	for(int i = 1 ; i <= m ; i++)
		for(int j = 1 ; j <= n ; j++) 
			c[i][j] = 1 + ( a[i] + b[j] >= k ? a[i] + b[j] - k : a[i] + b[j] );
    update(1 , 1 , 1 , 1 , 1);
	for(int i = 1 ; i <= m ; i++)
		for(int j = 1 ; j <= n ; j++) {
			f[i][j] = (f[i][j] + f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + MOD * MOD) % MOD;
			update(i + 1 , j , min(i + c[i][j] , m)  , j , f[i][j]);
			update(i , j + 1 , i , min(j + c[i][j] , n) , f[i][j]);
		}
	cout << f[m][n];
	return 0;
}

