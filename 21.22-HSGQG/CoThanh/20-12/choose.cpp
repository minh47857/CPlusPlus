#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define eps 1e-6
#define pi pair<int , int>

const ll N = 505 , MOD = 1e9 + 7 , inf = 1e15;

using namespace std;

void file() {
	freopen("choose.inp" , "r" , stdin);
	freopen("choose.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

ll n , m , a[N][N] , f[N][N] , ans = -inf;

int main() {
	file();
	cin >> m >> n;
	for(int i = 1 ; i <= m ; i++)
	  for(int j = 1 ; j <= n ; j++)
	    cin >> a[i][j];
	for(int i = 1 ; i <= n ; i++)
	  for(int j = i + 1 ; j <= n ; j++) {
	  	f[i][j] = -inf;
	  	for(int k = 1 ; k <= m ; k++) {
	  		ans = max(ans , f[i][j] + a[k][i] + a[k][j]);
	  		f[i][j] = max(f[i][j] , a[k][i] + a[k][j]);
		  }
		}
	cout << ans;
	return 0;
}


