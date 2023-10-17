#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back

const ll N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e15;

void file() {
    freopen("NOISE.inp" , "r" , stdin);
	freopen("NOISE.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll n , m , k , c[105] , dp[105][505] , ans = inf;

ll Get(int n , int k) {
	if(n % (k + 1) == 0) {
  	ll p = n / (k + 1);
  	return (p * (p + 1) / 2) * (k + 1);
  }
  else {
  	ll x1 = n / (k + 1);
  	ll x2 = x1 + 1;
  	ll k2 = n - x1 * (k + 1);
	ll k1 = k + 1 - k2;
	return  k1 * x1 * (x1 + 1) / 2 + k2 * x2 * (x2 + 1) / 2;
  }
}

int main() {
	file();
  cin >> n >> m >> k;
  assert(m == 1);
  for(int i = 1 , x ; i <= n ; i++) cin >> x , c[x]++;
  for(int i = 0 ; i <= m ; i++)
   for(int j = 0 ; j <= k ; j++) 
    dp[i][j] = inf;
  dp[0][k] = 0;
  for(int i = 0 ; i <= m ; i++)
   for(ll j = 0 ; j <= k ; j++) 
     for(ll l = 0 ; l <= min(c[i + 1] , j) ; l++) {
     	if(dp[i][j] != inf){
     		 dp[i + 1][j - l] = min(dp[i + 1][j - l], dp[i][j] + Get(c[i + 1] , l));
     	}
	 }
  for(int i = 0 ; i <= k ; i++) ans = min(ans , dp[m][i]);
  cout << ans;
}


