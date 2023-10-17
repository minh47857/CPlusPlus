#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define eps 1e-6
#define pi pair<int , int>

const int N = 405 , MOD = 1e9 + 7 , inf = 1e9 + 7;

using namespace std;

void file() {
	freopen("letters.inp" , "r" , stdin);
	freopen("letters.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int n , m , dp[N][N] , k;
ll ans = 0 , f[30];
char a[N][N];

int get(int u , int v , int x , int y) {
	return dp[x][y] - dp[x][v - 1] - dp[u - 1][y] + dp[u - 1][v - 1];
}

void solve(int u , int v) {
	int j = 1;
	for(int i = 0 ; i <= 27 ; i++) f[i] = 0;
	for(int i = 1 ; i <= n ; i++) {
		while(j < i && get(j , u , i , v) > k) {
			if(a[j][u] == a[j][v]) f[a[j][u] - 'a']--;
			j++;
		}
		if(a[i][u] != a[i][v]) continue;
		ans += f[a[i][u] - 'a'];
		f[a[i][u] - 'a']++;
	}
}

int main() {
	file();
	cin >> n >> m >> k;
	for(int i = 1 ; i <= n ; i++) 
		for(int j = 1 ; j <= m ; j++) {
			cin >> a[i][j];
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + (a[i][j] == 'a');
		}
	for(int i = 1 ; i < m ; i++)
		for(int j = i + 1 ; j <= m ; j++)
			solve(i , j);
	cout << ans;
	return 0;
}


