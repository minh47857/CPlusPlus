#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>

const ll N = 1000001 , MOD = 1e9 + 7 , inf = 1e15;

void file() {
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , m , a[N] , ans = 0 , dp[N] , cnt[N];

int main() {
	file();
  cin >> n >> m;
  for(int i = 1 ; i <= n ; i++) {
  	cin >> a[i] ;
	if(a[i] <= m) cnt[a[i]]++;
  }
  for(int i = 1 ; i <= m ; i++) 
   for(int j = i ; j <= m ; j += i) 
    dp[j] += cnt[i];
  for(int i = 1 ; i <= m ; i++) if(dp[i] > dp[ans]) ans = i;
  if(ans == 0) cout << 1 << ' ' << 0;
  else {
  	 cout << ans << ' ' << dp[ans] << '\n';
     for(int i = 1 ; i <= n ; i++) if(ans % a[i] == 0) cout << i << ' ';
  }
  return 0;
}

