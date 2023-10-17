#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back

const ll N = 2e3 + 5 , MOD = 1e9 + 7 , inf = 1e15 , NN = 3e7;

void file() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int m;

namespace sub3 {
	ll n , a[N] , s[2][N] , dp[2][N][N] , Max = -inf , Min = inf;
    void solve() {
    cin >> n;
    for(int i = 1 ; i <= n ; i++) cin >> a[i];
    for(int len = 1 ; len < n ; len++) 
	  	for(int i = 1 ; i <= n ; i++) 
	  	 dp[0][i][len] = -inf , dp[1][i][len] = inf;
	  for(int i = 1 ; i <= n ; i++) s[0][i] = s[1][i] = a[i];
	  for(int len = 1 ; len < n ; len++) {
	  	for(int i = 1 ; i <= n ; i++) {
	  		if(i > len) 
			  dp[0][i][len] = max(dp[0][i][len] , s[0][i - len] + a[i]),
			  dp[1][i][len] = min(dp[1][i][len] , s[1][i - len] + a[i]);
			if(i <= n - len)
			  dp[0][i][len] = max(dp[0][i][len] , s[0][i + len] + a[i]),
			  dp[1][i][len] = min(dp[1][i][len] , s[1][i + len] + a[i]);
		  }
		for(int i = 1 ; i <= n ; i++) 
		    s[0][i] = max(s[0][i] , dp[0][i][len]), 
		    s[1][i] = min(s[1][i] , dp[1][i][len]);
	  }
	  for(int i = 1 ; i <= n ; i++) Max = max(Max , s[0][i]) , Min = min(Min , s[1][i]);
	  cout << max(abs(Max) , abs(Min)) << endl;	 
	}
}

namespace sub4 {
	
	struct block {
		int w , x , y;
		bool operator < (const block&s) const {return w <= s.w;};
	};
	
	int n , k = 0;
	ll Max = -inf , Min = inf , a[NN] , pre[2][5005] , dp[2][5005];
	block s[NN];
	vector<int> p;
	
	int id(int i , int j) {
	  return (i - 1) * m + j;	
	}
	
	int dist(int id1 , int id2) {
		int x1 , x2 , y1 , y2;
		x1 = (id1 - 1) / n + 1 , y1 = id1 % n , x2 = (id2 - 1) / n + 1 , y2 = id2 % n;
		if(y1 == 0) y1 = n;
		if(y2 == 0) y2 = n;
		return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
	}
	
	void solve() {
		cin >> n;
		for(int i = 1 ; i <= m ; i++)
		 for(int j = 1 ; j <= n ; j++) cin >> a[id(i , j)];
		for(int i = 1 ; i <= m * n ; i++)
		 for(int j = i + 1 ; j <= m * n ; j++)
		   s[++k] = {dist(i , j) , i , j};
		sort(s + 1 , s + k + 1);
		for(int i = 1 ; i <= m * n ; i++) pre[0][i] = pre[1][i] = dp[0][i] = dp[1][i] = a[i];
		for(int i = 1 ; i <= k ; i++) {
			dp[0][s[i].x] = max(dp[0][s[i].x] , pre[0][s[i].y] + a[s[i].x]);
			dp[0][s[i].y] = max(dp[0][s[i].y] , pre[0][s[i].x] + a[s[i].y]);
			dp[1][s[i].x] = min(dp[0][s[i].x] , pre[1][s[i].y] + a[s[i].x]);
			dp[1][s[i].y] = min(dp[0][s[i].y] , pre[1][s[i].x] + a[s[i].y]);
			p.pb(s[i].x) , p.pb(s[i].y);
			if(i == k || s[i].w != s[i + 1].w) {
			  for(auto x : p) 
			      pre[0][x] = max(pre[0][x] , dp[0][x]) , 
				  pre[1][x] = min(pre[1][x] , dp[1][x]);
			  p.clear();
			}
		}
	    for(int i = 1 ; i <= m * n ; i++) Max = max(pre[0][i] , Max) , Min = min(pre[1][i] , Min);
	     cout << max(abs(Max) , abs(Min));	  
	}
}

int main() {
	file();
   cin >> m;
   if(m == 1) sub3::solve();
   //sub4::solve();
   return 0;
}
