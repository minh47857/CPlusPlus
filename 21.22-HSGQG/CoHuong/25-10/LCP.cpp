#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>

const int N = 105;

void file() {
	freopen("LCP.inp" , "r" , stdin);
	freopen("LCP.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , m , pos[N][15] , a[15][N] , dp[N] , ans = 0;

bool check(int u , int v) {
	for(int i = 1 ; i <= m ; i++) if(pos[u][i] >= pos[v][i]) return false;
	return true;
}

int main() {
	file();
 cin >> n >> m;
 for(int i = 1 ; i <= m ; i++)
 for(int j = 1 ; j <= n ; j++)
 cin >> a[i][j] , pos[a[i][j]][i] = j;
 for(int i = 1 ; i <= n ; i++) dp[i] = 1;
 for(int i = 1 ; i <= n ; i++) 
  for(int j = 1 ; j < i ; j++) 
	if(check(a[1][j] , a[1][i])) dp[a[1][i]] = max(dp[a[1][j]] + 1 , dp[a[1][i]]);		
 for(int i = 1 ; i <= n ; i++) ans = max(ans , dp[i]);
 cout << ans;
 return 0;
}

