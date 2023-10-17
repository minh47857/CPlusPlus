#include<bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>

const ll N = 5005 , M = 1e5 + 5;
using namespace std;

void file() {
	freopen("umbrella.inp" , "r" , stdin);
	freopen("umbrella.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll n , m , x[N] , c[M] , dp[N];

int main() {
	file();
  	cin >> n >> m ;
  	for (int i = 1 ; i <= n ; i++) cin >> x[i];
 	for (int i = 1 ; i <= m ; i++) cin >> c[i];
    sort(x + 1 , x + n + 1);
    for (int i = m - 1 ; i >= 1 ; i--) c[i] = min(c[i] , c[i + 1]);
  	for (int i = 1 ; i <= n ; i++) {
  		dp[i] = c[x[i]];
  		for (int j = 0 ; j < i ; j++) dp[i] = min(dp[i] , dp[j] + c[x[i] - x[j + 1] + 1]);
	}
  	cout << dp[n];
  return 0;
}

