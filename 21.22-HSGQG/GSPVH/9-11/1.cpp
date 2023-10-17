#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back

const int N = 3005 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
    //freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , m , h , w , k , a[N][N] , d , c , g , ans , dp[N][N];

int Get(int x , int y , int u , int v) {
	return dp[x][y] - dp[u - 1][y] - dp[x][v - 1] + dp[u - 1][v - 1];
}

bool check(int x) {
	for(int i = 1 ; i <= n ; i++)
	 for(int j = 1 ; j <= m ; j++) 
       dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + (a[i][j] < x);
	for(int i = 1 ; i <= n - h + 1 ; i++)
	  for(int j = 1 ; j <= m - w + 1; j++)
	    if(Get(i + h - 1 , j + w - 1 , i , j) <= k) return true;
	return false; 
}

int main() {
	file();
	cin >> n >> m >> h >> w;
	k = h * w / 2;
	for(int i = 1 ; i <= n ; i++)
    	for(int j = 1 ; j <= m ; j++)
    	    cin >> a[i][j];
    d = 1 , c = n * m; 
    while(d <= c) {
    	g = (d + c) / 2;
    	if(check(g)) ans = g , d = g + 1;
    	else c = g - 1;
	}
	cout << ans;
}
