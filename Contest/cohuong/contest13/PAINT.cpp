#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<ll,ll>
#define fi first
#define se second
#define pb push_back

const int N = 1000005 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
	freopen("PAINT.inp" , "r" , stdin);
	freopen("PAINT.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

namespace sub1 {
	int m , n , cnt = 0  , ans = -inf , s[25] , id[5][15] , a[5][15];
		void check() {
		int res = 0;
		for(int i = 2 ; i <= n ; i++) if((s[id[1][i]] + s[id[2][i]] + s[id[1][i - 1]] + s[id[2][i - 1]]) % 2 == 0) return;
	    for(int j = 1 ; j <= m ; j++)
		for(int i = 1 ; i <= n ; i++) if(s[id[j][i]]) res += a[j][i];
		ans = max(ans , res);	
	}
	
	void gen(int t) {
		for(int i = 0 ; i <= 1 ; i++) {
			s[t] = i;
			if(t == m * n) check();
			else gen(t + 1);
		}
	}
	
	void solve() {
		cin >> m >> n;
		for(int i = 1 ; i <= m ; i++) 
		  for(int j = 1 ; j <= n ; j++) cin >> a[i][j] , id[i][j] = ++cnt;	
		gen(1);
		cout << ans;
	}
}

void sub3 {
  int Bit(int x , int k) {
  	return (x >> k) & 1;
  }
  
  void solve() {
  	cin >> m >> n;
  	for(int i = 1 ; i <= m ; i++)
  	 for(int j = 1 ; j <= n ; j++)
  	  cin >> a[i][j];
  	
  }
}

int main() {
  file();
  sub1::solve();
  sub3::solve();
  return 0;
}



