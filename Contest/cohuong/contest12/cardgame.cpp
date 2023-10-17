#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>

const ll N = 20 , MOD = 1e9 + 7 , inf = 1e15;

void file() {
	freopen("cardgame.in" , "r" , stdin);
	freopen("cardgame.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll t , n , r[N] , b[N] , f[1 << N];

int Bit(int x , int k) {
	return (x >> k) & 1;
}

void solve() {
	cin >> n;
	for(int i = 1 ; i <= n ; i++) cin >> r[i];
	for(int i = 1 ; i <= n ; i++) cin >> b[i];
	  
	for(int mask = 1 ; mask < (1 << n) ; mask++) {
	  if(__builtin_popcount(mask) == 1) {f[mask] = 0 ; continue;}
	  else f[mask] = inf;
	  for(int i = 1 ; i <= n ; i++) if(Bit(mask , i - 1)) {
	  	ll res = inf;
	  	 for(int j = 1 ; j <= n ; j++) if(i != j && Bit(mask , j - 1)) {
	  	 	res = min({res , r[i] ^ b[j] , r[j] ^ b[i]});
		   }
		f[mask] = min(f[mask] , f[mask ^ (1 << (i - 1))] + res);
	  }
	}
	cout << f[(1 << n) - 1] << '\n';
}

int main() {
	file();
  cin >> t;
  while(t--) solve();
  return 0;
}

