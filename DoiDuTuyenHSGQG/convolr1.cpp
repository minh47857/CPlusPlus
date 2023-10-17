#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>

const ll N = 5e3 + 5 , MOD = 1e9 + 7 , inf = 1e17;

void file() {
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll n , a[N] , b[N] , dp[N][N] , ans = -inf;

int main() {
  cin >> n;
  for(int i = 1 ; i <= n ; i++) cin >> a[i];
  for(int i = 1 ; i <= n ; i++) cin >> b[i];
  for(int i = 1 ; i <= n ; i++) {
  	for(int j = 1 ; j <= n ; j++) dp[i][j] =  max(dp[i - 1][j - 1], 0LL) + a[i] * b[i] , ans = max(dp[i][j] , ans);
  }
  cout << ans;
  return 0;
}

