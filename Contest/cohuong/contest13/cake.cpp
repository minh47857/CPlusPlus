#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<ll,ll>
#define fi first
#define se second
#define pb push_back

const int N = 55 , M = 5e4 + 5 , inf = 1e9;

void file() {
	freopen("cake.inp" , "r" , stdin);
	freopen("cake.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , l[N];

namespace sub1 {
	int s[20] , ans = inf;
	void check() {
		int Max = 0 , Min = inf , pre = 0 , ok = 0;
		for(int i = 1 ; i < n ; i++) ok |= s[i];
		if(!ok) return;
		for(int i = 1 ; i <= n ; i++) {
			if(s[i]) 
			Max = max(l[i] - l[pre] , Max) , Min = min(l[i] - l[pre] , Min) , pre = i;
		}
		
		ans = min(ans , Max - Min);
	}
	
	void gen(int t) {
		for(int i = 0 ; i <= 1 ; i++) {
			s[t] = i;
			if(t == n - 1) check();
			else gen(t + 1);
		}
	}
	
	void solve() {
		s[n] = 1;
		gen(1);
		cout << ans << '\n';
	}
}

namespace sub3 {
	int ans = inf , f[N][M] ;
	pair<int , int> dp[N][M];
	void solve() {
		for(int i = 1 ; i <= n ; i++) 
		  for(int j = 0 ; j <= 5e4 ; j++)
		    dp[i][j] = {0 , inf} , f[i][0] = 0;
		for(int i = 1 ; i < n ; i++) dp[i][l[i]].fi = 1;
		
		for(int i = 1 ; i <= n ; i++) 
		  for(int j = 1 ; j <= 5e4 ; j++) {
		  	if(dp[i][j].fi == 0) {
		  		for(int k = 1 ; k < i ; k++) {
		  		int sum = l[i] - l[k];
		  		pair<int , int> tmp;
		  		if (sum == j && f[k][j]) tmp = {1 , f[k][j]};
		  	    if(sum <= j && dp[k][j].fi) tmp = {1 , max(min(dp[k][j].se , sum) , tmp.se)};
		  	    if(dp[i][j].fi * tmp.fi == 1) dp[i][j].se = max(dp[i][j].se , tmp.se);
		  	    if(tmp.fi == 1 && dp[i][j].fi == 0) dp[i][j] = tmp;
			  }	
		  	}
		   f[i][j] = f[i][j - 1] ;
		   if(dp[i][j].fi) f[i][j] = max(f[i][j] , min(dp[i][j].se , j));
		}
		for(int i = 1 ; i <= 5e4 ; i++) if(dp[n][i].fi) ans = min(ans , abs(i - dp[n][i].se));
		cout << ans;
	}
}
int main() {
	file();
  cin >> n ;
  for(int i = 1 ; i <= n ; i++) cin >> l[i] , l[i] = l[i - 1] + l[i];
  if(n <= 15) sub1::solve();
  else sub3::solve();
  return 0;
}
