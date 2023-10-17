#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 205 , M = (1 << 16) + 5 , MOD = 1e9 + 7;

void file() {
	freopen("primeset.inp" , "r" , stdin);
	freopen("primeset.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int a[N] , b[N] , n , m , f[N] , dp[N][M];

int main() {
	file();
   cin >> n;
   for(int i = 1 ; i <= n ; i++) cin >> a[i];
   cin >> m;
   for(int i = 0 ; i < m ; i++) cin >> b[i];
   dp[0][0] = 1;
   for(int i = 1 ; i <= n ; i++)
    for(int j = 0 ; j < m ; j++)
     if(a[i] % b[j] == 0) f[i] |= (1 << j);
   for(int i = 0 ; i < n ; i++) 
   	 for(int j = 0 ; j < (1 << m) ; j++)
   	   dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % MOD ,
   	   dp[i + 1][j | f[i + 1]] = (dp[i + 1][j | f[i + 1]] + dp[i][j]) % MOD;
    cout << dp[n][(1 << m) - 1];
    return 0;
}

